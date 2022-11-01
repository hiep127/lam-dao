#include "ListModel.h"
#include <QDebug>

ListModel::ListModel(QObject *parent) : QAbstractListModel(parent)
{
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_listModel.length();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }
    const Model &item = m_listModel[index.row()];

    switch (role) {
        case nameRole:
            return item.getName();
        case assemblyRole:
            return item.getAssembly();
        case cppRole:
            return item.getCpp();
        case javaScriptRole:
            return item.getJavaScript();
        case qmlRole:
            return item.getQML();
        case openGlRole:
            return item.getOpenGL();
        default:
            return QVariant();
    }
}

bool ListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid()){
        return false;
    }
    Model &item = m_listModel[index.row()];

    bool ret = false;
    switch (role) {
        case assemblyRole:
            item.setAssembly(value.toInt());
            ret = true;
            break;
        case cppRole:
            item.setCpp(value.toInt());
            ret = true;
             break;
        case javaScriptRole:
            item.setJavaScript(value.toInt());
            ret = true;
            break;
        case qmlRole:
            item.setQML(value.toInt());
            ret = true;
            break;
        case openGlRole:
            item.setOpenGL(value.toInt());
            ret = true;
            break;
        default:
            ret = false;
            break;
    }

    emit this->dataChanged(index, index);
    return ret;
}

QList<Model>* ListModel::getListModel()
{
    return &m_listModel;
}

QHash<int, QByteArray> ListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[nameRole] = "name";
    roles[assemblyRole] = "assembly";
    roles[cppRole] = "cpp";
    roles[javaScriptRole] = "javaScript";
    roles[qmlRole] = "qml";
    roles[openGlRole] = "openGL";
    return roles;
}
