#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QtWidgets/QtWidgets>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QFileDialog>
#include <QWidget>
#include <QSlider>
#include <QStatusBar>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:


    void on_actionopen_triggered();

    void on_actionplay_triggered();

    void on_actionpause_triggered();

    void on_actionstop_triggered();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QProgressBar* bar;
    QWidget* vm;
    QSlider* slider;


};
#endif // MAINWINDOW_H
