#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "AppMain.h"
#include <QQmlContext>
#include <QSortFilterProxyModel>

#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string>

struct ModelTest{
    std::string name;
    int Assembly;
    int Cpp;
    int JavaScript;
    int QML;
    int OpenGL;
};


int main(int argc, char *argv[])
{


    key_t key = ftok("shmfile",65);

    // shmget returns an identifier in shmid
    int shmid = shmget(key,sizeof(ModelTest) * 2,0666|IPC_CREAT);

    // shmat to attach to shared memory
    ModelTest *str = (ModelTest*) shmat(shmid,(void*)0,0);

    std::cout << "a1 = " << str[0].Assembly << std::endl;
    std::cout << "a1 = " << str[0].Cpp << std::endl;
    std::cout << "a1 = " << str[0].JavaScript << std::endl;
    std::cout << "a1 = " << str[0].QML << std::endl;
    std::cout << "a1 = " << str[0].OpenGL << std::endl;

    std::cout << "a1 = " << str[1].Assembly << std::endl;
        std::cout << "a1 = " << str[1].Cpp << std::endl;
        std::cout << "a1 = " << str[1].JavaScript << std::endl;
        std::cout << "a1 = " << str[1].QML << std::endl;
        std::cout << "a1 = " << str[1].OpenGL << std::endl;

    //detach from shared memory
    shmdt(str);

    // destroy the shared memory
    shmctl(shmid,IPC_RMID,NULL);
    return 1;


//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication application(argc, argv);

//    QQmlApplicationEngine engine;

//    AppMain app;
//    app.initContext(engine.rootContext());

//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

//    return application.exec();
}
