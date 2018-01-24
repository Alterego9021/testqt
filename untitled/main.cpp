#include <uniset2/UniSetTypes.h>
#include <uniset2/MessageType.h>
#include <uniset2/UniSetActivator.h>
#include <mpu3/MPUSharedMemory.h>
#include <iostream>
#include "mainwindow.h"
#include <QApplication>

using namespace uniset;
using namespace std;


int main(int argc, char *argv[])
{
    uniset_init(argc, (const char**)(argv) );
    auto conf = uniset_conf();

    ObjectId ID(DefaultObjectId);
    auto name = conf->getArgParam("--name", "GUIManager1");
    ID = conf->getObjectID(name);

    if( ID == uniset::DefaultObjectId )
    {
        cerr << "(main): идентификатор '" << name
             << "' не найден в конф. файле!"
             << " в секции " << conf->getObjectsSection() << endl;
        return 0;
    }

    auto act = UniSetActivator::Instance();
    auto shm = MPUSharedMemory::init_mpusmemory(argc, argv);
    if( !shm )
        return 1;

    act->add(shm);

    SystemMessage sm(SystemMessage::StartUp);
    act->broadcast( sm.transport_msg() );
    act->run(true);

    QApplication a(argc, argv);
    MainWindow w(shm);

   w.show();

    return a.exec();
}
