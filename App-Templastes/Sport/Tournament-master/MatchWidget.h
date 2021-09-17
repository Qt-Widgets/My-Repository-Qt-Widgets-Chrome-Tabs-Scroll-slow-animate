#ifndef MATCHWIDGET_H
#define MATCHWIDGET_H

#include "PointsWidget.h"
#include "Match.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

class MatchWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit MatchWidget(Match *match, QWidget *parent = nullptr);

  signals:

  private:
    QVBoxLayout *layout = Q_NULLPTR;

    QWidget *player1Widget = Q_NULLPTR;
    QHBoxLayout *player1Layout = Q_NULLPTR;
    QLabel *p1Label = Q_NULLPTR;
    PointsWidget *pointsPlayer1Widget = Q_NULLPTR;

    QWidget *player2Widget = Q_NULLPTR;
    QHBoxLayout *player2Layout = Q_NULLPTR;
    QLabel *p2Label = Q_NULLPTR;
    PointsWidget *pointsPlayer2Widget = Q_NULLPTR;

    Player *m_Player1 = Q_NULLPTR;
    Player *m_Player2 = Q_NULLPTR;

    // QWidget interface
  protected:
    void paintEvent(QPaintEvent *event) override;

  private slots:
    void onUpdateRequest();
};

#endif  // MATCHWIDGET_H
