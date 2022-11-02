#include "AppMain.h"
#include "QDebug"
AppMain::AppMain(QObject *parent) : QObject(parent)
{
    initModel();
    m_service = new HmiService();
//    connect(m_service, SIGNAL(finished()),m_service, SLOT(deleteLater()));
    m_service->start();
}

void AppMain::initContext(QQmlContext *context)
{
    if(context != nullptr){
        m_filterProxy.setSourceModel(&m_model);
        m_filterProxy.setFilterRole(ListModel::nameRole);
        m_filterProxy.setFilterCaseSensitivity(Qt::CaseInsensitive);
        context->setContextProperty("listModel",&m_filterProxy);
        context->setContextProperty("appMain",this);
    }
}

void AppMain::initModel()
{
    QList<Model> *list = m_model.getListModel();
    list->append(Model("lamdao111", 1, 2, 3, 4, 5));
    list->append(Model("tai2ho", 1, 2, 3, 4, 5));
    list->append(Model("phinguyen", 1, 2, 3, 4, 5));
    list->append(Model("hautruong", 1, 2, 3, 4, 5));
    list->append(Model("hoangmap", 1, 2, 3, 4, 5));
    list->append(Model("vietmap", 1, 2, 3, 4, 5));
    list->append(Model("truvu", 1, 2, 3, 4, 5));
    list->append(Model("luan1pham", 1, 2, 3, 4, 5));
    list->append(Model("hoannguyen", 1, 2, 3, 4, 5));
    list->append(Model("nam2traN", 1, 2, 3, 4, 5));
}

void AppMain::requestRefesh()
{
    qDebug() << __FUNCTION__ << __LINE__;
}

void AppMain::requestUpdateItem(int index)
{
    qDebug() << __FUNCTION__ << __LINE__;
    Model mol = m_model.getListModel()->at(index);
}
