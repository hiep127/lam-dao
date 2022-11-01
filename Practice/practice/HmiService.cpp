#include "hmiservice.h"
#include <QDebug>

struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} messageReceived;

HmiService::HmiService()
{

    // ftok to generate unique key
    key = ftok("progfile", 65);

    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);
}

HmiService::~HmiService()
{
    // to destroy the message queue
    msgctl(msgid, IPC_RMID, NULL);
}

void HmiService::run()
{
    while(true) {
        qDebug() << "a";
        // msgrcv to receive message
        msgrcv(msgid, &messageReceived, sizeof(messageReceived), 1, 0);
        // display the message
        qDebug() << "Data Received is" << messageReceived.mesg_text;
    }
}
