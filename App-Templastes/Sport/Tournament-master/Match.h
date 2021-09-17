#ifndef MATCH_H
#define MATCH_H

#include "Player.h"

#include <QObject>

class Match : public QObject
{
    Q_OBJECT
  public:
    explicit Match(Player *p1, Player *p2, QObject *parent = nullptr);
    Match(Match *m1, Match *m2, QObject *parent = Q_NULLPTR);

    Match *getPreviousMatch1() const;
    Match *getPreviousMatch2() const;

    Player *getPlayer1() const;
    void setPlayer1(Player *value);

    Player *getPlayer2() const;
    void setPlayer2(Player *value);

    Player *getWinner() const;
    void setWinner(Player *value);

    bool isFinished();
    void setFinished(bool value);

    QString getName() const;
    void setName(const QString &Name);

    bool IsActive() const;
    void setActive(bool active);

    void finish();

  signals:
    void finished();
    void requestUpdate();


  private slots:
    void onPreviousMatchFinished();

  private:
    Player *player1 = Q_NULLPTR;
    Player *player2 = Q_NULLPTR;
    Match *previousMatch1 = Q_NULLPTR;
    Match *previousMatch2 = Q_NULLPTR;
    Player *winner = Q_NULLPTR;
    bool m_Finished = false;
    QString m_Name;
    bool m_IsActive = false;

  public slots:
    void onTimerFinished();
};

#endif  // MATCH_H
