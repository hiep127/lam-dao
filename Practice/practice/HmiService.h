#ifndef HMISERVICE_H
#define HMISERVICE_H
#include <QThread>
#include <sys/ipc.h>
#include <sys/msg.h>

class HmiService : public QThread
{
    Q_OBJECT
public:
    HmiService();
    ~HmiService();
    void run() override;

private:
    key_t key;
    int msgid;
};

#endif // HMISERVICE_H
