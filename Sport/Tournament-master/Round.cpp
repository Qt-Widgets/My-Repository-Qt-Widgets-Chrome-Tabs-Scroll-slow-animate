#include "Round.h"

#include <QTimer>
#include <QDebug>

Round::Round(QList< Player * > players, QObject *parent) : QObject(parent) { createMatches(players); }

Round::Round(QList< Match * > previousRoundMatches, QObject *parent) : QObject(parent)
{
    while (previousRoundMatches.size() > 0)
    {
        Match *m1 = previousRoundMatches.takeFirst();
        Match *m2 = Q_NULLPTR;
        if (previousRoundMatches.size() > 0) m2 = previousRoundMatches.takeFirst();



        Match *m = new Match(m1, m2, this);
        m->setName(QObject::tr("Match ") + QString::number(m_Matches.size() + 1));
        m_Matches.append(m);
    }
    qDebug() << "matches.size= " << m_Matches.size();
}

void Round::createMatches(QList< Player * > players)
{
    // Firstroundmatches
    while (!players.isEmpty())
    {
        Player *p1 = players.takeFirst();
        Player *p2 = Q_NULLPTR;
        if (!players.isEmpty()) p2 = players.takeFirst();

        Match *m = new Match(p1, p2, this);
        if (!p1 && p2)
        {
            m->setFinished(true);
            m->setWinner(p2);
        }
        else if (p1 && !p2)
        {
            m->setFinished(true);
            m->setWinner(p1);
        }
        m->setName(QObject::tr("Match ") + QString::number(m_Matches.size() + 1));
        m_Matches.append(m);
    }
}

void Round::finishMatch(Match *m, Player *winner)
{
    m->setWinner(winner);
    m->finish();
}

void Round::startNextMatch()
{
    foreach (auto m, m_Matches)
    {
        if (!m->isFinished())
        {
            if (!m->getPlayer1())
            {
                if (m->getPreviousMatch1())
                {
                    m->setPlayer1(m->getPreviousMatch1()->getWinner());
                    m->requestUpdate();
                }
            }
            if (!m->getPlayer2())
            {
                if (m->getPreviousMatch2())
                {
                    m->setPlayer2(m->getPreviousMatch2()->getWinner());
                    m->requestUpdate();
                }
            }
            m->setActive(true);
            connect(m, SIGNAL(finished()), this, SLOT(onMatchFinished()));
            matchStarted(m);
            //            QTimer::singleShot(20000, m, SLOT(onTimerFinished()));
            return;
        }
    }
    m_Finished = true;
    finished();
}

bool Round::isFinished() const { return m_Finished; }

QList< Player * > Round::getWinners()
{
    QList< Player * > players;
    foreach (auto m, m_Matches)
    {
        if (!m->isFinished()) continue;
        players.append(m->getWinner());
    }
    return players;
}

void Round::onMatchFinished()
{
    Match *m = static_cast< Match * >(sender());
    if (m) m->setActive(false);
    startNextMatch();
}

QList< Match * > Round::getMatches() const { return m_Matches; }

int Round::nMatches() const { return m_Matches.size(); }

QString Round::getName() const { return m_Name; }

void Round::setName(const QString &Name) { m_Name = Name; }
