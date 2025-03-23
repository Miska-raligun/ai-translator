#include "openai_translator.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkRequest>

OpenAITranslator::OpenAITranslator(QObject *parent) : QObject(parent) {
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished,
            this, &OpenAITranslator::onReplyFinished);
}

void OpenAITranslator::setApiKey(const QString &key) {
    apiKey = key;
}

void OpenAITranslator::setApiUrl(const QString &url) {
    apiUrl = url;
}

void OpenAITranslator::translateText(const QString &text) {
    QJsonObject message1{{"role", "system"}, {"content", "You are a translation assistant. Your job is to translate the user's input into either Chinese or English, depending on the source language. Just return the translated text only, without any explanation or extra information."}};
    QJsonObject message2{{"role", "user"}, {"content", text}};

    QJsonArray messages{message1, message2};
    QJsonObject body;
    body["model"] = "Pro/deepseek-ai/DeepSeek-V3";  // 替换为你的平台模型
    body["messages"] = messages;
    body["temperature"] = 0.3;

    QNetworkRequest request((QUrl(apiUrl)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());

    QJsonDocument doc(body);
    networkManager->post(request, doc.toJson());
}

void OpenAITranslator::onReplyFinished(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        emit translationFailed(reply->errorString());
        reply->deleteLater();
        return;
    }

    QJsonDocument responseDoc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject root = responseDoc.object();
    QJsonArray choices = root["choices"].toArray();
    if (!choices.isEmpty()) {
        QString raw = choices[0].toObject()["message"].toObject()["content"].toString();
        QString result = QString::fromUtf8(raw.toUtf8());
        emit translationFinished(result.trimmed());
    } else {
        emit translationFailed("No translation result.");
    }

    reply->deleteLater();
}
