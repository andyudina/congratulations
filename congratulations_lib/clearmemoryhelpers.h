#ifndef CLEARMEMEMORYHELPERS_H
#define CLEARMEMEMORYHELPERS_H

#include <QHash>
#include <QList>
#include "listelement.h"

//вспомогательные функции для очистки памяти
template <class T>
void CONGRATULATIONS_LIBSHARED_EXPORT clearQList(QList<T*>*& list) {
    if (list == nullptr)
        return;

    for (int inner_iter = 0; inner_iter < list->size(); ++inner_iter) {
        delete list->at(inner_iter);
    }

    delete list;
    list = nullptr;
}

template <class T>
void CONGRATULATIONS_LIBSHARED_EXPORT clearQHash(QHash<int, QList<T*>*>*& hash) {
    if (hash == nullptr)
        return;
    QList<QList<AbstractListEntry*>*> updatedList = hash->values();
    for (int iter = 0; iter < updatedList.size(); ++iter) {
        QList<AbstractListEntry*>* list = updatedList.at(iter);
        if (list != nullptr) {
            clearQList<T>(list);
        }
    }
    delete hash;
    hash = nullptr;
}


#endif // CLEARMEMEMORYHELPERS_H
