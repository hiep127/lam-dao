#ifndef APPMAIN_H
#define APPMAIN_H
#include "Model/ListModel.h"
#include <QQmlContext>
#include <QSortFilterProxyModel>
#include <QObject>
#include "HmiService.h"

class AppMain : public QObject
{
    Q_OBJECT
public:
    AppMain(QObject *parent = nullptr);

    void initContext(QQmlContext *context);
    void initModel();

private:
    ListModel m_model;
    QSortFilterProxyModel m_filterProxy;
    HmiService* m_service;
};

#endif // APPMAIN_H
