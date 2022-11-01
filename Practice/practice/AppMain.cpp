#include "AppMain.h"

AppMain::AppMain(QObject *parent) : QObject(parent)
{
    initModel();
    m_service = new HmiService();
    connect(m_service, SIGNAL(finished()),m_service, SLOT(deleteLater()));
    m_service->start();
}

void AppMain::initContext(QQmlContext *context)
{
    if(context != nullptr){
        m_filterProxy.setSourceModel(&m_model);
        m_filterProxy.setFilterRole(ListModel::nameRole);
        m_filterProxy.setFilterCaseSensitivity(Qt::CaseInsensitive);
        context->setContextProperty("listModel",&m_filterProxy);
    }
}

void AppMain::initModel()
{
    m_model.getListModel()->append(Model("lamdao", 1, 2, 3, 4, 5));
    m_model.getListModel()->append(Model("tai2ho", 1, 2, 3, 4, 5));
    m_model.getListModel()->append(Model("phinguyen", 1, 2, 3, 4, 5));
    m_model.getListModel()->append(Model("hautruong", 1, 2, 3, 4, 5));
    m_model.getListModel()->append(Model("hoangmap", 1, 2, 3, 4, 5));
    m_model.getListModel()->append(Model("vietmap", 1, 2, 3, 4, 5));
    m_model.getListModel()->append(Model("truvu", 1, 2, 3, 4, 5));
    m_model.getListModel()->append(Model("luan1pham", 1, 2, 3, 4, 5));
    m_model.getListModel()->append(Model("hoannguyen", 1, 2, 3, 4, 5));
    m_model.getListModel()->append(Model("nam2traN", 1, 2, 3, 4, 5));
}
