#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Round.h"

#include <QObject>

class Tournament : public QObject
{
    Q_OBJECT
  public:
    explicit Tournament(QObject *parent = nullptr);


    void init();
    void start();
    void addPlayer(Player *player);
    void removePlayer(Player *player);

    bool isFinished() const;

    QList< Round * > getRounds() const;
    QList< Player * > getPlayers() const;

    Round *getCurrentRound() const;

  signals:
    void finished(Player *winner);
    void requestUpdate();

  private slots:
    void onRoundFinished();
    void onRoundMatchFinished(Match *m);
    void onRoundMatchStarted(Match *m);

  private:
    void createFirstRound();
    void createRound(Round *previousRound);
    void addRound(Round *round);

    QList< Round * > m_Rounds;
    QList< Player * > m_Players;
    bool m_Finished = false;
    Round *m_CurrentRound = Q_NULLPTR;
};

#endif  // TOURNAMENT_H
