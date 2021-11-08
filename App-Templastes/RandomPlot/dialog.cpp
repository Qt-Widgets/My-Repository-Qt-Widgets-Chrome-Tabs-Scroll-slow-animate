#include "dialog.h"
#include "ui_dialog.h"
#include "plotcircle.h"
#include "plotsquare.h"
#include "plottriangle.h"

#include <QTime>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Create seed for the random generator
    // That is needed only once on application startup
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    // Disable the "Stop Plotting" pushbutton, because when the application
    // loads, plotting is disabled by default.
    ui->pushButton_2->setEnabled(false);

    // Initialise the scene onto the ui.graphicsView
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Set the scale of the Window implicitly, to prevent bug in my interview
    // application, whereby the first point was always plotted in the centre
    // of the scene object.
    ui->graphicsView->scale(1, 1);
    scene->setSceneRect(0,0,400,400);

    // Initialises a new instance of QTimer called timer
    // It calls the plot() function every time the timer is evaulated.
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),SLOT(plot()));


}

void Dialog::plot()
{
    // Checks the values of the radiobuttons, and creates new instances of the appropriate Plot_ class
    // objects.

    if (ui->radioButton_3->isChecked())
    {
    PlotCircle *point = new PlotCircle;
    scene->addItem(point);
    }
    if (ui->radioButton_2->isChecked())
    {
    PlotSquare *point = new PlotSquare;
    scene->addItem(point);
    }
    if (ui->radioButton->isChecked())
    {
    PlotTriangle *point = new PlotTriangle;
    scene->addItem(point);
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    // Starts the timer, disables the start button and enables the stop button.
    // The timer value runs from 100ms to 1000ms. Because I wanted the vertical
    // slider to be fast at the top, slow at the bottom, the slider runs from
    // -1000 to -100. Therefore the absolute value of this parameter is passed
    // into the timer.
    timer->start(abs(ui->verticalSlider->value()));
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
}

void Dialog::on_pushButton_2_clicked()
{
    // Stops the timer, disables the stop button and enables the start button.
    timer->stop();
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}

void Dialog::on_pushButton_3_clicked()
{
    //Clears the scene of all points.
    scene->clear();
}

void Dialog::on_verticalSlider_valueChanged(int value)
{
    // Restarts the timer, but only if the Start button is not enabled (i.e. the application is
    // busy plotting)
    if (!ui->pushButton->isEnabled())
    {
        timer->stop();
        timer->start(abs(ui->verticalSlider->value()));
    }
}
