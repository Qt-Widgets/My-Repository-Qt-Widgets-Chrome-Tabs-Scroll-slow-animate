#include "Tournament.h"

#include <QDebug>
#include <QRandomGenerator>

Tournament::Tournament(QObject *parent) : QObject(parent) {}

void Tournament::init()
{
    createFirstRound();
    while (m_Rounds.last()->nMatches() != 1)
    {
        createRound(m_Rounds.last());
    }
}

void Tournament::start()
{
    Round *r = m_Rounds.first();
    r->startNextMatch();
}

void Tournament::addPlayer(Player *player) { m_Players.append(player); }

void Tournament::removePlayer(Player *player) { m_Players.removeAll(player); }

void Tournament::createFirstRound()
{
    QList< Player * > randomizedPlayers;
    QRandomGenerator *generator = QRandomGenerator::system();
    while (m_Players.size())
    {
        randomizedPlayers << m_Players.takeAt(generator->bounded(0, m_Players.size()));
    }

    Round *round = new Round(randomizedPlayers, this);
    addRound(round);
    m_CurrentRound = round;
}

void Tournament::createRound(Round *previousRound)
{
    Round *round = new Round(previousRound->getMatches());

    addRound(round);
}

void Tournament::addRound(Round *round)
{
    connect(round, SIGNAL(finished()), this, SLOT(onRoundFinished()));
    connect(round, SIGNAL(matchStarted(Match *)), this, SLOT(onRoundMatchStarted(Match *)));
    connect(round, SIGNAL(matchFinished(Match *)), this, SLOT(onRoundMatchFinished(Match *)));

    if (round->getMatches().size() == 2)
        round->setName(QObject::tr("Halbfinale"));
    else if (round->getMatches().size() == 1)
        round->setName(QObject::tr("Finale"));
    else
        round->setName(QObject::tr("Runde ") + QString::number(m_Rounds.size() + 1));
    m_Rounds.append(round);
}

Round *Tournament::getCurrentRound() const { return m_CurrentRound; }

QList< Round * > Tournament::getRounds() const { return m_Rounds; }

QList< Player * > Tournament::getPlayers() const { return m_Players; }

bool Tournament::isFinished() const { return m_Finished; }

void Tournament::onRoundFinished()
{
    Round *round = static_cast< Round * >(sender());
    if (!round) throw Q_NULLPTR;
    m_CurrentRound = round;
    auto winners = round->getWinners();

    if (winners.size() == 1)
    {
        m_Finished = true;
        finished(winners.first());

        qDebug() << "======= Winner of Tournament " << winners.first()->getName() << "! ==========";
    }
    else
    {
        qDebug() << "======= NEW ROUND ==========";
        if (round != m_Rounds.last())
        {
            int iNext = m_Rounds.indexOf(round) + 1;
            Round *r = m_Rounds[iNext];
            r->startNextMatch();
            requestUpdate();
        }
    }
}

void Tournament::onRoundMatchFinished(Match *m)
{
    qDebug() << "Match Finished...Winner: " << m->getWinner()->getName();
    requestUpdate();
}

void Tournament::onRoundMatchStarted(Match *m)
{
    requestUpdate();
    qDebug() << "Match Started...";
    qDebug() << "  P1: " << (m->getPlayer1() ? m->getPlayer1()->getName() : "");
    qDebug() << "  P2: " << (m->getPlayer2() ? m->getPlayer2()->getName() : "");
}
