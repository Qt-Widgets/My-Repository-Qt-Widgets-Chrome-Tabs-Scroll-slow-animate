#include "Match.h"

#include <QDebug>

Match::Match(Player *p1, Player *p2, QObject *parent) : QObject(parent)
{
    player1 = p1;
    player2 = p2;

    if (!player1 || !player2)
    {
        if (!player1)
            winner = player2;
        else
            winner = player1;
        finish();
    }
}

Match::Match(Match *m1, Match *m2, QObject *parent)
{
    previousMatch1 = m1;
    previousMatch2 = m2;
    if (m1 && m1->isFinished())
    {
        player1 = m1->getWinner();
        if (!m2)
        {
            setWinner(player1);
            finish();
        }
    }
    if (m2 && m2->isFinished())
    {
        player2 = m2->getWinner();
        if (!m1)
        {
            setWinner(player2);
            finish();
        }
    }


    if (m1) connect(m1, SIGNAL(finished()), this, SLOT(onPreviousMatchFinished()));
    if (m2) connect(m2, SIGNAL(finished()), this, SLOT(onPreviousMatchFinished()));
}

Match *Match::getPreviousMatch1() const { return previousMatch1; }

Match *Match::getPreviousMatch2() const { return previousMatch2; }

Player *Match::getPlayer1() const { return player1; }

void Match::setPlayer1(Player *value) { player1 = value; }

Player *Match::getPlayer2() const { return player2; }

void Match::setPlayer2(Player *value) { player2 = value; }

Player *Match::getWinner() const { return winner; }

void Match::setWinner(Player *value) { winner = value; }

bool Match::isFinished() { return m_Finished; }

void Match::setFinished(bool value) { m_Finished = value; }

QString Match::getName() const { return m_Name; }

void Match::setName(const QString &Name) { m_Name = Name; }

void Match::finish()
{
    if (m_Finished) return;
    qDebug() << "Finish match " << m_Name;
    m_Finished = true;
    m_IsActive = false;
    finished();
}

void Match::onPreviousMatchFinished()
{
    qDebug() << "onPreviousMatchFinished()";
    Match *m = static_cast< Match * >(sender());
    qDebug() << "Match Name = " << m->getName();
    if (m == previousMatch1)
    {
        player1 = m->winner;
        if (!previousMatch2)
        {
            winner = player1;
            finish();
        }
    }
    else
    {
        player2 = m->winner;
        if (!previousMatch1)
        {
            winner = player2;
            finish();
        }
    }
    requestUpdate();
}

bool Match::IsActive() const { return m_IsActive; }

void Match::setActive(bool IsActive) { m_IsActive = IsActive; }

void Match::onTimerFinished()
{
    if (player1)
        winner = player1;
    else
        winner = player2;
    qDebug() << this << ", " << winner->getName();
    finish();
}
