#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class SettingsData;

class Settings : public QObject
{
    Q_OBJECT

  public:
    static Settings *instance(QObject *parent = Q_NULLPTR);
    bool load();
    bool save();

    // delete copy-ctor and asignment operator
    Settings(Settings const &) = delete;
    void operator=(Settings const &) = delete;

    SettingsData *getSettingsData() const;

  private:
    Settings(QObject *parent = Q_NULLPTR);
    void toJson(QJsonObject &json);
    void fromJson(const QJsonObject &json);

    SettingsData *m_SettingsData = Q_NULLPTR;
    QString filePath;

    static Settings *m_instance;
    bool prepareWrite(const QString &filename);
    bool mkpath(const QString &path);
    bool setFilePermissions(const QString &filename);
};

#endif  // SETTINGS_H
