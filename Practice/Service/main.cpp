//// C Program for Message Queue (Writer Process)
//#include <stdio.h>
//#include <sys/ipc.h>
//#include <sys/msg.h>
//#define MAX 10

//// structure for message queue
//struct mesg_buffer {
//	long mesg_type;
//	char mesg_text[100];
//} message;

//int main()
//{
//    key_t key;
//    int msgid;

//    // ftok to generate unique key
//    key = ftok("progfile", 65);

//    // msgget creates a message queue
//    // and returns identifier
//    msgid = msgget(key, 0666 | IPC_CREAT);
//    message.mesg_type = 1;

//    printf("Write Data : ");
//    fgets(message.mesg_text,MAX,stdin);

//    // msgsnd to send message
//    msgsnd(msgid, &message, sizeof(message), 0);

//    // display the message
//    printf("Data send is : %s \n", message.mesg_text);

//    return 0;
//}


#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include "string.h"
using namespace std;

struct Model{
    int Assembly;
    int Cpp;
    int JavaScript;
    int QML;
    int OpenGL;
};

struct ListModel{
    Model mol[100];
};

int main()
{
    // ftok to generate unique key
    key_t key = ftok("shmfile",65);

    // shmget returns an identifier in shmid
    int shmid = shmget(key,sizeof(ListModel),0666|IPC_CREAT);

    // shmat to attach to shared memory
    ListModel *listModel = (ListModel*) shmat(shmid,(void*)0,0);

    cout<<"Write Data : ";
    ListModel *listModel1 = new ListModel();
    listModel1->mol[0].Assembly = 6;
    listModel1->mol[0].Cpp = 9;

    memcpy(listModel, listModel1, sizeof(ListModel));

    printf("Data written in memory");

    //detach from shared memory
    shmdt(listModel);

    return 0;
}
