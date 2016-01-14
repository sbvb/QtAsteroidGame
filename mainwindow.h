#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "about.h"
#include "help.h"
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_About_triggered();
    void on_actionOpen_Help_triggered();
    void on_actionPlay_triggered();
    void on_actionUpdate_triggered();

private:
    Ui::MainWindow *ui;
    About *openAboutWindow;
    Help *openHelpWindow;
    QMediaPlayer *titlemusic;
};

#endif // MAINWINDOW_H
