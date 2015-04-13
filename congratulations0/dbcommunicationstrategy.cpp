#include "dbcommunicationstrategy.h"



PullChangesStrategy::PullChangesStrategy(): lastChangedTimestamp(QDateTime::currentDateTime().toTime_t()) {}

uint PullChangesStrategy::getLastTimestamp() {
    uint timestampToReturn = lastChangedTimestamp;
    lastChangedTimestamp = QDateTime::currentDateTime().toTime_t();
    return timestampToReturn;
}

void PullChangesStrategy::updateCurrentList(QList<AbstractListEntry*>* destList,
                                            QHash<int, QList<AbstractListEntry*>*>* changesHash,
                                            bool (*isLess)(AbstractListEntry*, AbstractListEntry*)) {
    if (changesHash == nullptr || changesHash->empty() || destList == nullptr)
        return;

    QList<AbstractListEntry*>* deleteList = nullptr;
    if (changesHash->contains(DBManager::deletedElements)) {
        deleteList =changesHash->value(DBManager::deletedElements);
    }

    QList<AbstractListEntry*>* instertList = nullptr;
    if (changesHash->contains(DBManager::insertedElements)) {
        instertList = changesHash->value(DBManager::insertedElements);
    }

    QList<AbstractListEntry*>* updateList = nullptr;
    if (changesHash->contains(DBManager::updatedElements)) {
        updateList = changesHash->value(DBManager::updatedElements);
    }


    int deleteIter = (deleteList == nullptr)? -1 : deleteList->size() - 1,
        updateIter = (updateList == nullptr)? -1 : updateList->size() - 1;

    if (deleteIter >= 0 || updateIter >= 0) {
        qSort(destList->begin(), destList->end(), AbstractListEntry::idIsLess);

        for (int iter = destList->size(); iter >= 0; --iter) {
            if (deleteIter >=0 && destList->at(iter)->id == deleteList->at(deleteIter)->id) {
                destList->removeAt(iter);
                --deleteIter;
            }
            if (updateIter >=0  && destList->at(iter)->id == updateList->at(updateIter)->id) {
                destList->removeAt(iter);
                --updateIter;
            }
        }
    }

    if (instertList != nullptr)
        destList->append(*instertList);

    if (updateList != nullptr)
        destList->append(*updateList);

    qSort(destList->begin(), destList->end(), isLess);

}




QList<AbstractListEntry*>* PushUpdatesStrategy::getChangedEntries(QList<AbstractListEntry*>* sourceList, QList<int>* id_list) {
    if (sourceList == nullptr)
        return nullptr;

    if (id_list == nullptr) {
        id_list = &updated_ids;
    }

    QList<AbstractListEntry*>* changed_objects = new QList<AbstractListEntry*>;


    for (int iter = 0; iter < updated_ids.size(); ++ iter) {
        if (id_list->at(iter) >= 0 && id_list->at(iter) < sourceList->size()) {
            changed_objects->append(sourceList->at(id_list->at(iter)));
        }
    }

    return changed_objects;
}

void PushUpdatesStrategy::clearChanges() {
    updated_ids.clear();
}

void PushUpdatesStrategy::addUpdatedId(int id) {
    if (updated_ids.indexOf(id) == -1)
        updated_ids.append(id);
}



QList<AbstractListEntry*>* PushChangesStrategy::getUpdatedEntries(QList<AbstractListEntry*>* sourceList, TemplateIdTranslator * translator) {
    if (sourceList == nullptr || translator == nullptr) {
        return nullptr;
    }

    QList<int>* ids = new QList<int>;

    for (int iter = 0; iter < updated_ids.size(); ++ iter) {
        int realIndex = translator->getRealIndex(updated_ids[iter]);
        if (realIndex >= 0)
            ids->append(realIndex);
    }

    QList<AbstractListEntry*>* result =  getChangedEntries(sourceList, ids);
    delete ids;

    return result;

}

QList<AbstractListEntry*>* PushChangesStrategy::getInsertedEntries(QList<AbstractListEntry*>* sourceList, TemplateIdTranslator * translator) {
    if (sourceList == nullptr || translator == nullptr) {
        return nullptr;
    }

    QList<int>* ids = new QList<int>;
    for (int iter = 0; iter < inserted_ids.size(); ++ iter) {
        int realIndex = translator->getRealIndex(inserted_ids[iter]);
        if (realIndex >= 0)
            ids->append(realIndex);
    }
    QList<AbstractListEntry*>* result =  getChangedEntries(sourceList, ids);

    delete ids;

    return result;
}

QList<int> &PushChangesStrategy::getDeletedIds() {
    return deleted_ids;
}

void PushChangesStrategy::addDeletedId(int id) {
    if (deleted_ids.indexOf(id) == -1)
        deleted_ids.append(id);
}

void PushChangesStrategy::addInsertedId(int id) {
    if (inserted_ids.indexOf(id) == -1)
        inserted_ids.append(id);
}

void PushChangesStrategy::clearChanges() {
    deleted_ids.clear();
    inserted_ids.clear();
    PushUpdatesStrategy::clearChanges();
}

