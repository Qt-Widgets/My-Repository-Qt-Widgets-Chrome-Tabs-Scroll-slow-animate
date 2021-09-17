#ifndef POINTSWIDGET_H
#define POINTSWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

class PointsWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit PointsWidget(QWidget *parent = nullptr);

    void setWinner(bool Winner);
    void setRoundsWon(int value);

  signals:

    // QWidget interface
  protected:
    void paintEvent(QPaintEvent *event) override;

  private:
    QHBoxLayout *layout = Q_NULLPTR;
    QLabel *m_RoundsWonLabel = Q_NULLPTR;
    bool m_Winner = false;
    int m_RoundsWon = 0;
};

#endif  // POINTSWIDGET_H
