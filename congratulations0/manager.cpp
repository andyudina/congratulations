#include "manager.h"
Manager::Manager(QObject *parent):
        QAbstractListModel(parent), dbManager(nullptr), listEntries(nullptr) {}

Manager::~Manager() {
    if (dbManager != nullptr)
        delete dbManager;

    if (listEntries != nullptr) {
        clearQList(listEntries);
    }
}

void Manager::initialize(QmlApplicationViewer& viewer, const QString& modelName) {
    //зарегистрировать модель для работы с QML
    viewer.rootContext()->setContextProperty(modelName, this);
    QObject::connect(this, SIGNAL(deleteElement(int)), this, SLOT(onDeleteElement(int)));
    //нициализировать список модели
    if (listEntries == nullptr)
        listEntries = dbManager->getAllElements(&firstDisplayedElement);
}

int Manager::rowCount(const QModelIndex &parent) const {
    if (listEntries != nullptr)
        return listEntries->size();
    else
        return 0;
}

int  Manager::getFirstDisplayedElement() {
    return firstDisplayedElement;
}



