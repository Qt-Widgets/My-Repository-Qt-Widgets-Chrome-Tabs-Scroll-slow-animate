#ifndef SETTINGSDATA_H
#define SETTINGSDATA_H

#include <QObject>
#include <QColor>

class SettingsData : public QObject
{
    Q_OBJECT
  public:
    explicit SettingsData(QObject *parent = nullptr);

    void toJson(QJsonObject &json);
    void fromJson(const QJsonObject &json);

    void resetColors();

    QString getTest() const;
    void setTest(const QString &value);

    QColor getBackgroundColor1() const;
    void setBackgroundColor1(const QColor &value);

    QColor getBackgroundColor2() const;
    void setBackgroundColor2(const QColor &value);

    QColor getBackgroundColor3() const;
    void setBackgroundColor3(const QColor &value);

    QColor getBackgroundColor4() const;
    void setBackgroundColor4(const QColor &value);

    QColor getBackgroundColor5() const;
    void setBackgroundColor5(const QColor &value);

    QColor getBackgroundColor6() const;
    void setBackgroundColor6(const QColor &value);

    QColor getRoundsBorderColor() const;
    void setRoundsBorderColor(const QColor &value);

    QColor getRoundsBackgroundColor() const;
    void setRoundsBackgroundColor(const QColor &value);

    QColor getRoundsLineColor() const;
    void setRoundsLineColor(const QColor &value);

    QColor getMatchBackgroundColor() const;
    void setMatchBackgroundColor(const QColor &value);

    QColor getActiveMatchBorderColor() const;
    void setActiveMatchBorderColor(const QColor &value);

    QColor getMatchSeparatorColor() const;
    void setMatchSeparatorColor(const QColor &value);

    QColor getMatchPointsBackgroundColor() const;
    void setMatchPointsBackgroundColor(const QColor &value);

    QColor getMatchPointsWinnerBackgroundColor() const;
    void setMatchPointsWinnerBackgroundColor(const QColor &value);

    QColor getMatchPlayerTextColor() const;
    void setMatchPlayerTextColor(const QColor &value);

    QColor getMatchPointsTextColor() const;
    void setMatchPointsTextColor(const QColor &value);

  private:
    // TournamentGraphicsScene
    QColor backgroundColor1 = QColor("#024C62");
    QColor backgroundColor2 = QColor("#024C62");
    QColor backgroundColor3 = QColor("#04627F");
    QColor backgroundColor4 = QColor("#0394C0");
    QColor backgroundColor5 = QColor("#04627F");
    QColor backgroundColor6 = QColor("#024C62");
    QColor roundsBorderColor = QColor(0, 0, 0);
    QColor roundsBackgroundColor = QColor(0, 0, 0);
    QColor roundsLineColor = QColor(0, 0, 0);

    // GraphicsItem
    QColor matchBackgroundColor = QColor(105, 105, 105);
    QColor activeMatchBorderColor = QColor(117, 233, 0);
    QColor matchSeparatorColor = QColor(255, 255, 255);
    QColor matchPointsBackgroundColor = QColor(192, 192, 192);
    QColor matchPointsWinnerBackgroundColor = QColor(255, 140, 0);
    QColor matchPointsTextColor = QColor(0, 0, 0);
    QColor matchPlayerTextColor = QColor(0, 0, 0);

  signals:
};

#endif  // SETTINGSDATA_H
