#include "Settings.h"

#include "SettingsData.h"

#include <QJsonArray>
#include <QDebug>
#include <QString>
#include <QDir>
#include <QSettings>
#include <QCoreApplication>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>

Settings::Settings(QObject *parent) : QObject(parent)
{
    m_SettingsData = new SettingsData(this);
    filePath = QDir::currentPath();
    if (!filePath.endsWith(QDir::separator())) filePath += QDir::separator();
    filePath += "Settings.json";

    QFileInfo info(filePath);
    if (info.exists())
        load();
    else
    {
        save();
    }
}

Settings *Settings::m_instance = Q_NULLPTR;

Settings *Settings::instance(QObject *parent)
{
    if (!m_instance)
    {
        m_instance = new Settings(parent);
    }
    return m_instance;
}

void Settings::toJson(QJsonObject &json)
{
    QJsonArray arr;
    QJsonObject obj;
    m_SettingsData->toJson(obj);
    arr.append(obj);
    json["Settings"] = arr;
}

void Settings::fromJson(const QJsonObject &json)
{
    if (!json.contains("Settings") || !json["Settings"].isArray()) return;

    auto array = json["Settings"].toArray();
    foreach (auto arrayItem, array)
    {
        if (!arrayItem.isObject()) continue;
        auto jsonSetup = arrayItem.toObject();

        m_SettingsData = new SettingsData();
        m_SettingsData->fromJson(jsonSetup);
    }
}

SettingsData *Settings::getSettingsData() const { return m_SettingsData; }

bool Settings::load()
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonObject rootObject = doc.object();

    fromJson(rootObject);

    return true;
}

bool Settings::save()
{
    if (!prepareWrite(filePath))
    {
        QMessageBox::warning(Q_NULLPTR, QObject::tr("Fehler"), QObject::tr("Keine Schreibberechtigung in Ordner: "));
        return false;
    }

    QJsonObject rootObject;

    toJson(rootObject);

    QJsonDocument doc;
    doc.setObject(rootObject);

    QFile file(filePath);
    file.open(QIODevice::WriteOnly);
    file.write(doc.toJson());
    file.flush();
    file.close();
    setFilePermissions(filePath);
}

bool Settings::prepareWrite(const QString &filename)
{
    QFileInfo info(filename);

    // Prüfen ob die Datei existiert und auch eine Datei ist in die geschrieben werden kann....
    if (info.exists()) return info.isFile() && info.isWritable();

    QString absoluteDir = info.absoluteDir().absolutePath();

    // Falls die Datei nicht existiert, rekursiv prüfen ob das Verzeichnis existiert
    while (!info.exists())
    {
        info = QFileInfo(info.absoluteDir().absolutePath());
    }

    // Falls die erste existierende Datei nicht schreibbar oder eine Datei ist, kann der benötigte Pfad nicht erzeugt werden
    if (!(info.isDir() && info.isWritable())) return false;

    return mkpath(absoluteDir);
}

bool Settings::mkpath(const QString &path)
{
    QFileInfo info(path);
    QString absolutePath = info.absoluteFilePath();

    if (info.exists())
    {
        if (!info.isDir()) return false;
        return info.isWritable() && info.isReadable() && info.isExecutable();
    }

    QStringList createdDirectories;
    while (!info.exists())
    {
        createdDirectories.prepend(info.fileName());
        QDir dir = info.absoluteDir();
        info = QFileInfo(dir.absolutePath());
        if (info.exists() && !info.isDir() && !info.isWritable()) return false;
    }
    QDir dir(info.absoluteFilePath());
    QString dirsToCreate = "";
    foreach (QString s, createdDirectories)
    {
        if (s.length() > 0) dirsToCreate += "/";
        dirsToCreate += s;
    }

    if (!dir.mkpath(absolutePath)) return false;

    QString filename = info.absoluteFilePath();
    setFilePermissions(filename);
    foreach (QString s, createdDirectories)
    {
        filename += "/" + s;
        setFilePermissions(filename);
    }

    return true;
}

bool Settings::setFilePermissions(const QString &filename)
{
    QFileInfo info(filename);

    if (!info.exists()) return false;

    QFile file(filename);
    QFileDevice::Permissions additionalPermissions = QFileDevice::ReadGroup | QFileDevice::WriteGroup | QFileDevice::ReadOther;
    if (info.isDir()) additionalPermissions = additionalPermissions | QFileDevice::ExeGroup | QFileDevice::ExeOther;
    return file.setPermissions(file.permissions() | additionalPermissions);
}
