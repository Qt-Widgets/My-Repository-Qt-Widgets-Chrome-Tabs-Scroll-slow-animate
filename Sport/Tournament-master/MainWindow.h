#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MatchWidget.h"

#include <QMainWindow>
#include <QMap>

class Tournament;
class TournamentGraphicScene;

QT_BEGIN_NAMESPACE namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    void onMatchFinishedPerClick(Match *match, Player *winner);
    void onSettingsPressed();
    void onAddPlayerPressed();

  private:
    Ui::MainWindow *ui;
    MatchWidget *mw3 = Q_NULLPTR;

    QMap< Match *, MatchWidget * > matchMap;

    Tournament *t = Q_NULLPTR;
    TournamentGraphicScene *tgs = Q_NULLPTR;

    // QWidget interface
  protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif  // MAINWINDOW_H
