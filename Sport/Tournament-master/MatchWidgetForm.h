#ifndef MATCHWIDGETFORM_H
#define MATCHWIDGETFORM_H

#include <QWidget>

class Match;
class Player;

namespace Ui
{
    class MatchWidgetForm;
}

class MatchWidgetForm : public QWidget
{
    Q_OBJECT

  public:
    explicit MatchWidgetForm(Match *match, QWidget *parent = nullptr);
    ~MatchWidgetForm();

  private:
    Ui::MatchWidgetForm *ui;
    Player *m_Player1 = Q_NULLPTR;
    Player *m_Player2 = Q_NULLPTR;

  private slots:
    void onUpdateRequest();

    // QWidget interface
  protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif  // MATCHWIDGETFORM_H
