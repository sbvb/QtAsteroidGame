#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include <QGraphicsScene>
#include "player.h"
#include <QGraphicsView>
#include <QTimer>
#include "score.h"
#include "game.h"

#define soundvolume 50

Game *game;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    titlemusic=new QMediaPlayer();
    titlemusic->setMedia(QUrl("qrc:/sounds/titlemusic.mp3")); //"Blasteroids Spectrum Title Music", extracted from youtube.com
    titlemusic->setVolume(soundvolume);
    titlemusic->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_About_triggered()
{
    openAboutWindow=new About(this);
    openAboutWindow->setModal(true);
    openAboutWindow->show();
}

void MainWindow::on_actionOpen_Help_triggered()
{
    openHelpWindow=new Help(this);
    openHelpWindow->setModal(true);
    openHelpWindow->show();
}

void MainWindow::on_actionPlay_triggered(){
    titlemusic->stop();
    int timelimit=ui->lcdNumber->value();
    if (ui->radioButton->isChecked())
        game=new Game(0,1,timelimit);
    else
        if (ui->radioButton_2->isChecked())
            game=new Game(0,2,timelimit);
        else
            game=new Game(0,3,timelimit);

}

void MainWindow::on_actionUpdate_triggered(){
    ui->lcdNumber->display(ui->dial->value()*15);
}
