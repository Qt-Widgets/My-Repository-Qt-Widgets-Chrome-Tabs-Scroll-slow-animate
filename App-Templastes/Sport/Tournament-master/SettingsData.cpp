#include "SettingsData.h"

#include <QJsonObject>

SettingsData::SettingsData(QObject *parent) : QObject(parent) {}

void SettingsData::toJson(QJsonObject &json)
{
    json["BackgroundColor1"] = backgroundColor1.name();
    json["BackgroundColor2"] = backgroundColor2.name();
    json["BackgroundColor3"] = backgroundColor3.name();
    json["BackgroundColor4"] = backgroundColor4.name();
    json["BackgroundColor5"] = backgroundColor5.name();
    json["BackgroundColor6"] = backgroundColor6.name();
    json["RoundsBorder"] = roundsBorderColor.name();
    json["RoundsBackgroundColor"] = roundsBackgroundColor.name();
    json["RoundsLineColor"] = roundsLineColor.name();

    json["MatchBackgroundColor"] = matchBackgroundColor.name();
    json["ActiveMatchBorderColor"] = activeMatchBorderColor.name();
    json["MatchSeparatorColor"] = matchSeparatorColor.name();
    json["MatchPointsColor"] = matchPointsBackgroundColor.name();
    json["MatchPointsWinnerColor"] = matchPointsWinnerBackgroundColor.name();
    json["MatchPlayerTextColor"] = matchPlayerTextColor.name();
    json["MatchPointsTextColor"] = matchPointsTextColor.name();
}

void SettingsData::fromJson(const QJsonObject &json)
{
    if (json.contains("BackgroundColor1")) backgroundColor1.setNamedColor(json["BackgroundColor1"].toString());
    if (json.contains("BackgroundColor2")) backgroundColor2.setNamedColor(json["BackgroundColor2"].toString());
    if (json.contains("BackgroundColor3")) backgroundColor3.setNamedColor(json["BackgroundColor3"].toString());
    if (json.contains("BackgroundColor4")) backgroundColor4.setNamedColor(json["BackgroundColor4"].toString());
    if (json.contains("BackgroundColor5")) backgroundColor5.setNamedColor(json["BackgroundColor5"].toString());
    if (json.contains("BackgroundColor6")) backgroundColor6.setNamedColor(json["BackgroundColor6"].toString());
    if (json.contains("RoundsBorder")) roundsBorderColor.setNamedColor(json["RoundsBorder"].toString());
    if (json.contains("RoundsBackgroundColor")) roundsBackgroundColor.setNamedColor(json["RoundsBackgroundColor"].toString());
    if (json.contains("RoundsLineColor")) roundsLineColor.setNamedColor(json["RoundsLineColor"].toString());

    if (json.contains("MatchBackgroundColor")) matchBackgroundColor.setNamedColor(json["MatchBackgroundColor"].toString());
    if (json.contains("ActiveMatchBorderColor")) activeMatchBorderColor.setNamedColor(json["ActiveMatchBorderColor"].toString());
    if (json.contains("MatchSeparatorColor")) matchSeparatorColor.setNamedColor(json["MatchSeparatorColor"].toString());
    if (json.contains("MatchPointsColor")) matchPointsBackgroundColor.setNamedColor(json["MatchPointsColor"].toString());
    if (json.contains("MatchPointsWinnerColor")) matchPointsWinnerBackgroundColor.setNamedColor(json["MatchPointsWinnerColor"].toString());
    if (json.contains("MatchPlayerTextColor")) matchPlayerTextColor.setNamedColor(json["MatchPlayerTextColor"].toString());
    if (json.contains("MatchPointsTextColor")) matchPointsTextColor.setNamedColor(json["MatchPointsTextColor"].toString());
}

void SettingsData::resetColors()
{
    // TournamentGraphicsScene
    backgroundColor1 = QColor("#024C62");
    backgroundColor2 = QColor("#024C62");
    backgroundColor3 = QColor("#04627F");
    backgroundColor4 = QColor("#0394C0");
    backgroundColor5 = QColor("#04627F");
    backgroundColor6 = QColor("#024C62");
    roundsBorderColor = QColor(0, 0, 0);
    roundsBackgroundColor = QColor(0, 0, 0);
    roundsLineColor = QColor(0, 0, 0);

    // GraphicsItem
    matchBackgroundColor = QColor(105, 105, 105);
    activeMatchBorderColor = QColor(117, 233, 0);
    matchSeparatorColor = QColor(255, 255, 255);
    matchPointsBackgroundColor = QColor(192, 192, 192);
    matchPointsWinnerBackgroundColor = QColor(255, 140, 0);
    matchPointsTextColor = QColor(0, 0, 0);
    matchPlayerTextColor = QColor(0, 0, 0);
}

QColor SettingsData::getBackgroundColor1() const { return backgroundColor1; }

void SettingsData::setBackgroundColor1(const QColor &value) { backgroundColor1 = value; }

QColor SettingsData::getBackgroundColor2() const { return backgroundColor2; }

void SettingsData::setBackgroundColor2(const QColor &value) { backgroundColor2 = value; }

QColor SettingsData::getBackgroundColor3() const { return backgroundColor3; }

void SettingsData::setBackgroundColor3(const QColor &value) { backgroundColor3 = value; }

QColor SettingsData::getBackgroundColor4() const { return backgroundColor4; }

void SettingsData::setBackgroundColor4(const QColor &value) { backgroundColor4 = value; }

QColor SettingsData::getBackgroundColor5() const { return backgroundColor5; }

void SettingsData::setBackgroundColor5(const QColor &value) { backgroundColor5 = value; }

QColor SettingsData::getBackgroundColor6() const { return backgroundColor6; }

void SettingsData::setBackgroundColor6(const QColor &value) { backgroundColor6 = value; }

QColor SettingsData::getRoundsBorderColor() const { return roundsBorderColor; }

void SettingsData::setRoundsBorderColor(const QColor &value) { roundsBorderColor = value; }

QColor SettingsData::getRoundsBackgroundColor() const { return roundsBackgroundColor; }

void SettingsData::setRoundsBackgroundColor(const QColor &value) { roundsBackgroundColor = value; }

QColor SettingsData::getRoundsLineColor() const { return roundsLineColor; }

void SettingsData::setRoundsLineColor(const QColor &value) { roundsLineColor = value; }

QColor SettingsData::getMatchBackgroundColor() const { return matchBackgroundColor; }

void SettingsData::setMatchBackgroundColor(const QColor &value) { matchBackgroundColor = value; }

QColor SettingsData::getActiveMatchBorderColor() const { return activeMatchBorderColor; }

void SettingsData::setActiveMatchBorderColor(const QColor &value) { activeMatchBorderColor = value; }

QColor SettingsData::getMatchSeparatorColor() const { return matchSeparatorColor; }

void SettingsData::setMatchSeparatorColor(const QColor &value) { matchSeparatorColor = value; }

QColor SettingsData::getMatchPointsBackgroundColor() const { return matchPointsBackgroundColor; }

void SettingsData::setMatchPointsBackgroundColor(const QColor &value) { matchPointsBackgroundColor = value; }

QColor SettingsData::getMatchPointsWinnerBackgroundColor() const { return matchPointsWinnerBackgroundColor; }

void SettingsData::setMatchPointsWinnerBackgroundColor(const QColor &value) { matchPointsWinnerBackgroundColor = value; }

QColor SettingsData::getMatchPlayerTextColor() const { return matchPlayerTextColor; }

void SettingsData::setMatchPlayerTextColor(const QColor &value) { matchPlayerTextColor = value; }

QColor SettingsData::getMatchPointsTextColor() const { return matchPointsTextColor; }

void SettingsData::setMatchPointsTextColor(const QColor &value) { matchPointsTextColor = value; }
