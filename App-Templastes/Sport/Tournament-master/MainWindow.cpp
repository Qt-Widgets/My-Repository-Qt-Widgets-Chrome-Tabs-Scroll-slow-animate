#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "Tournament.h"
#include "RoundWidget.h"
#include "MatchGraphicsItem.h"
#include "TournamentGraphicScene.h"
#include "GraphicsView.h"
#include "Settings.h"
#include "SettingsDialog.h"
#include "AddPlayerDialog.h"

#include <QTimer>
#include <QDebug>




MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Settings::instance();  // INIT

    t = new Tournament(this);
    for (int i = 0; i < 13; i++)
    {
        t->addPlayer(new Player("Spieler " + QString::number(i + 1)));
    }
    t->init();
    t->start();

    tgs = new TournamentGraphicScene(t);
    connect(tgs, SIGNAL(itemClicked(Match *, Player *)), this, SLOT(onMatchFinishedPerClick(Match *, Player *)));
    connect(tgs, &TournamentGraphicScene::settingsPressed, this, &MainWindow::onSettingsPressed);
    connect(tgs, &TournamentGraphicScene::addPlayerPressed, this, &MainWindow::onAddPlayerPressed);
    GraphicsView *view = new GraphicsView(tgs, this);
    view->show();
    ui->centralwidget->layout()->addWidget(view);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::onMatchFinishedPerClick(Match *match, Player *winner) { t->getCurrentRound()->finishMatch(match, winner); }

void MainWindow::onSettingsPressed()
{
    SettingsDialog *dia = new SettingsDialog(this);
    if (dia->exec() == QDialog::Accepted)
    {
        Settings::instance()->save();
        tgs->updateColors();
    }
}

void MainWindow::onAddPlayerPressed()
{
    if (t)
    {
        delete t;
        t = Q_NULLPTR;
    }

    AddPlayerDialog *dia = new AddPlayerDialog(this);
    if (dia->exec() == QDialog::Accepted)
    {
        t = new Tournament(this);
        foreach (auto p, dia->getPlayerList())
        {
            t->addPlayer(new Player(p));
        }

        t->init();
        t->start();

        tgs->update();
    }
}

void MainWindow::closeEvent(QCloseEvent *event) { Settings::instance()->save(); }
