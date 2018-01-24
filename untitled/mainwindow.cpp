#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace uniset;
using namespace std;


MainWindow::MainWindow(std::shared_ptr<MPUSharedMemory> shm, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    conf = uniset_conf();

    if( !shm )
        cout << "no shm "<< endl;

    shmgui = shm;
    sid = conf->getSensorID("Empty_AS");
    sid1 = conf->getSensorID("MPU1_BI1U_А11В11_AS");
    sid2 = conf->getSensorID("MPU1_BI1U_А11С11_AS");
    sid3 = conf->getSensorID("MPU1_BI1U_А12В12_AS");
    sid4 = conf->getSensorID("MPU1_BI1U_А12С12_AS");
    sid5 = conf->getSensorID("MPU1_I_AV11_AS");
    sid6 = conf->getSensorID("MPU1_I_AV12_AS");
    sid7 = conf->getSensorID("MPU1_U_AV11_AS");
    sid8 = conf->getSensorID("MPU1_U_AV12_AS");
    sid9 = conf->getSensorID("MPU1_I_BTR11_AS");
    sid10 = conf->getSensorID("MPU1_I_BTR12_AS");
    sid11 = conf->getSensorID("MPU1_T_BK1_AV1_AS");
    sid12 = conf->getSensorID("MPU1_T_BK2_AV1_AS");
    sid13 = conf->getSensorID("MPU1_T_BK1_UZ1AV1_AS");
    sid14 = conf->getSensorID("MPU1_T_BK2_UZ1AV1_AS");
    sid15 = conf->getSensorID("MPU1_T_BK1_UZ2AV1_AS");
    sid16 = conf->getSensorID("MPU1_T_BK2_UZ2AV1_AS");
    sid17 = conf->getSensorID("MPU1_T_BK3_UZ3AV1_AS");
    sid18 = conf->getSensorID("MPU1_T_BK4_UZ4AV1_AS");
    sid19 = conf->getSensorID("MPU1_T_BK5_AF1AV1_AS");
    sid20 = conf->getSensorID("MPU1_T_BK6_AF1AV1_AS");
    sid21 = conf->getSensorID("MPU1_Risol_AV1_AS");
    sid22 = conf->getSensorID("MPU1_UZ121_State_AS");
    sid23 = conf->getSensorID("MPU1_UZ131_State_AS");
    sid24 = conf->getSensorID("MPU1_BIU2_А11В11_AS");



    ui->setupUi(this);

    sigc::connection connPoll = Glib::signal_timeout().connect(sigc::mem_fun(*this, &MainWindow::show_time), 150);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    chislo = shmgui->getValue(sid);
    ui->label->setText(QString::number(chislo));
}

void MainWindow::on_pushButton_2_clicked()
{
    QString text = ui->textEdit->toPlainText();
    cout << text.split(" ")[0].toInt()<< endl;
    shmgui->setValue(sid,text.split(" ")[0].toInt());
    cout << timer.getCurrent() << endl;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    shmgui->setValue(sid,position);
    ui->label->setText(QString::number(position));
    ui->progressBar->setValue(position);

}

bool MainWindow::show_time()
{
    chislo = shmgui->getValue(sid);
    ui->label->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid1);
    ui->label_2->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid2);
    ui->label_3->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid3);
    ui->label_4->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid4);
    ui->label_5->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid5);
    ui->label_6->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid6);
    ui->label_7->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid7);
    ui->label_8->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid8);
    ui->label_9->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid9);
    ui->label_10->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid10);
    ui->label_11->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid11);
    ui->label_12->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid12);
    ui->label_13->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid13);
    ui->label_14->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid14);
    ui->label_15->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid15);
    ui->label_16->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid16);
    ui->label_17->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid17);
    ui->label_18->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid18);
    ui->label_19->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid19);
    ui->label_20->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid20);
    ui->label_21->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid21);
    ui->label_22->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid22);
    ui->label_23->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid23);
    ui->label_24->setText(QString::number(chislo));
    chislo = shmgui->getValue(sid24);
    ui->label_25->setText(QString::number(chislo));





    return true;
}
