#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>
#include "Model.h"
#include <QList>
class ListModel : public QAbstractListModel
{
public:
    ListModel(QObject *parent = nullptr);

    enum itemRole{
        nameRole = Qt::UserRole +1,
        assemblyRole ,
        cppRole,
        javaScriptRole,
        qmlRole,
        openGlRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    QList<Model>* getListModel();

private:
    QList<Model> m_listModel;
    QHash<int, QByteArray> roleNames() const override;
};

#endif // LISTMODEL_H
