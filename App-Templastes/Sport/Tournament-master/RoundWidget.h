#ifndef ROUNDWIDGET_H
#define ROUNDWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

class MatchWidget;

class RoundWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit RoundWidget(const QString &roundName, QWidget *parent = nullptr);

    void addMatchWidgets(QList< MatchWidget * > machtWidgets);

  signals:

    // QWidget interface
  protected:
    void paintEvent(QPaintEvent *event) override;

  private:
    QVBoxLayout *layout = Q_NULLPTR;
};

#endif  // ROUNDWIDGET_H
