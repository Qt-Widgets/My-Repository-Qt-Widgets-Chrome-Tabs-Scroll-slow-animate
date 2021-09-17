#include "MatchWidgetForm.h"
#include "ui_MatchWidgetForm.h"

#include "Match.h"
#include "Player.h"

#include <QPainter>
#include <QPainterPath>
#include <QDebug>

MatchWidgetForm::MatchWidgetForm(Match *match, QWidget *parent) : QWidget(parent), ui(new Ui::MatchWidgetForm)
{
    ui->setupUi(this);
    connect(match, SIGNAL(finished()), this, SLOT(onUpdateRequest()));
    connect(match, SIGNAL(requestUpdate()), this, SLOT(onUpdateRequest()));

    m_Player1 = match->getPlayer1();
    m_Player2 = match->getPlayer2();

    if (m_Player1) ui->label->setText(m_Player1->getName());
    if (m_Player2) ui->label_2->setText(m_Player2->getName());

    ui->widget_4->setFixedSize(ui->widget->height() + 20, ui->widget->height() + 20);
    ui->widget_6->setFixedSize(ui->widget->height() + 20, ui->widget->height() + 20);

    if (match->isFinished())
    {
        if (match->getWinner() == match->getPlayer1())
        {
            ui->widget_4->setRoundsWon(1);
            ui->widget_4->setWinner(true);
            ui->widget_4->update();
        }
        else if (match->getWinner() == match->getPlayer2())
        {
            ui->widget_6->setRoundsWon(1);
            ui->widget_6->setWinner(true);
            ui->widget_6->update();
        }
    }
}

MatchWidgetForm::~MatchWidgetForm() { delete ui; }

void MatchWidgetForm::onUpdateRequest()
{
    Match *match = static_cast< Match * >(sender());
    m_Player1 = match->getPlayer1();
    m_Player2 = match->getPlayer2();
    if (m_Player1) ui->label->setText((m_Player1->getName()));
    if (m_Player2) ui->label_2->setText((m_Player2->getName()));

    if (match->isFinished())
    {
        auto player = match->getWinner();
        if (player == m_Player1)
        {
            ui->widget_4->setWinner(true);
            ui->widget_4->setRoundsWon(1);
        }
        else if (player == m_Player2)
        {
            ui->widget_6->setWinner(true);
            ui->widget_6->setRoundsWon(1);
        }
    }
}


void MatchWidgetForm::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addRoundedRect(QRectF(0, 0, width(), height()), 5, 5);

    painter.fillPath(path, QColor(105, 105, 105));
    painter.drawPath(path);
}
