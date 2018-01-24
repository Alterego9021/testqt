#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <uniset2/UniSetTypes.h>
#include <uniset2/UInterface.h>
#include <uniset2/MessageType.h>
#include <uniset2/Configuration.h>
#include <uniset2/IONotifyController.h>
#include <uniset2/extensions/SMInterface.h>
#include <glibmm.h>
#include <QtDebug>
#include <mpu3/MPUSharedMemory.h>
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(std::shared_ptr<MPUSharedMemory> shm, QWidget *parent = 0 );
    ~MainWindow();
    ssize_t nbit;
    long chislo;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    uniset::ObjectId sid;
    std::shared_ptr<uniset::Configuration> conf;
    uniset::PassiveTimer timer;

    uniset::ObjectId sid1;
    uniset::ObjectId sid2;
    uniset::ObjectId sid3;
    uniset::ObjectId sid4;
    uniset::ObjectId sid5;
    uniset::ObjectId sid6;
    uniset::ObjectId sid7;
    uniset::ObjectId sid8;
    uniset::ObjectId sid9;
    uniset::ObjectId sid10;
    uniset::ObjectId sid11;
    uniset::ObjectId sid12;
    uniset::ObjectId sid13;
    uniset::ObjectId sid14;
    uniset::ObjectId sid15;
    uniset::ObjectId sid16;
    uniset::ObjectId sid17;
    uniset::ObjectId sid18;
    uniset::ObjectId sid19;
    uniset::ObjectId sid20;
    uniset::ObjectId sid21;
    uniset::ObjectId sid22;
    uniset::ObjectId sid23;
    uniset::ObjectId sid24;



    bool show_time();

protected:
    std::shared_ptr<MPUSharedMemory> shmgui;

    uniset::SensorMessage sm;

};

#endif // MAINWINDOW_H
