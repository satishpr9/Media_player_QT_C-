#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playercontrols.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
       vw = new QVideoWidget(this);
       player->setVideoOutput(vw);
       this->setCentralWidget(vw);


        slider = new QSlider(this);
        bar = new QProgressBar(this);

        slider->setOrientation(Qt::Horizontal);

        this->statusBar()->addPermanentWidget(slider);
        this->statusBar()->addPermanentWidget(bar);

        connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
        connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
        connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

        connect(player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
        connect(player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_actionopen_triggered()
{
    QString filename =QFileDialog::getOpenFileName(this,"Open a File","","Video File(*.avi, *.webm, *.mkv ,*.mpg, *.mp4)");
    on_actionstop_triggered();
    player ->setMedia(QUrl::fromLocalFile(filename));
    player->play();
    on_actionplay_triggered();

}

void MainWindow::on_actionplay_triggered()
{
    player ->play();
    this->statusBar()->showMessage("playing");
}

void MainWindow::on_actionpause_triggered()
{
    player->pause();
    this->statusBar()->showMessage("Paused");
}

void MainWindow::on_actionstop_triggered()
{
    player->stop();
    this->statusBar()->showMessage("Stop");
}
