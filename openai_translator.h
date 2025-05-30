#ifndef OPENAI_TRANSLATOR_H
#define OPENAI_TRANSLATOR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class OpenAITranslator : public QObject {
    Q_OBJECT
public:
    explicit OpenAITranslator(QObject *parent = nullptr);

    void setApiKey(const QString &key);
    void setApiUrl(const QString &url);
    void translateText(const QString &text);

signals:
    void translationFinished(const QString &translatedText);
    void translationFailed(const QString &errorMsg);

private slots:
    void onReplyFinished(QNetworkReply *reply);

private:
    QString apiKey;
    QString apiUrl;
    QNetworkAccessManager *networkManager;
};

#endif // OPENAI_TRANSLATOR_H
