#ifndef ROUND_H
#define ROUND_H

#include "Match.h"

#include <QObject>

class Round : public QObject
{
    Q_OBJECT
  public:
    explicit Round(QList< Player * > players, QObject *parent = nullptr);
    explicit Round(QList< Match * > previousRoundMatches, QObject *parent = nullptr);

    void createMatches(QList< Player * > players);
    void finishMatch(Match *m, Player *winner);
    bool isFinished() const;
    QList< Player * > getWinners();

    QString getName() const;
    void setName(const QString &Name);

    void startNextMatch();

    QList< Match * > getMatches() const;
    int nMatches() const;

  signals:
    void finished();
    void matchStarted(Match *m);
    void matchFinished(Match *);

  private slots:
    void onMatchFinished();

  private:
    QList< Match * > m_Matches;
    bool m_Finished = false;
    QString m_Name;
};

#endif  // ROUND_H
