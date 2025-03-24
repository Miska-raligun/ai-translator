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

void OpenAITranslator::setModel(const QString &model) {
    Model = model;
}

void OpenAITranslator::setTemperature(const double &temperature) {
    Temperature = temperature;
}

void OpenAITranslator::translateText(const QString &text) {
    QJsonObject message1{
        {"role", "system"},
        {"content",
         "You are a professional technical translator. "
         "When the input is in Chinese, translate it into English. "
         "When the input is in any other language, translate it into Chinese. "
         "Ensure the translation style is accurate, concise, and technically appropriate. "
         "For long paragraphs, split them into shorter logical units and translate them accordingly. "
         "Do not include any explanations or extra information. Output the translated content only."}
    };
    QJsonObject message2{{"role", "user"}, {"content", text}};

    QJsonArray messages{message1, message2};
    QJsonObject body;
    body["model"] = Model;  // 替换为你的平台模型
    body["messages"] = messages;
    body["temperature"] = Temperature;

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
