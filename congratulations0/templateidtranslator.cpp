#include "templateidtranslator.h"
#define INVALID_INDEX -1

//TemplateIdTranslator::TemplateIdTranslator(){}

void TemplateIdTranslator::initialize(int capacity ) {
    for (int index = 0; index < capacity; ++index) {
        ids.append(index);
    }

}

TemplateIdTranslator::TemplateIdTranslator(int capacity) {
    initialize(capacity);
}

int TemplateIdTranslator::deleteRealIndex(int realIndex) {
    if (realIndex < 0)
        return INVALID_INDEX;
    int friendsTemplateIndex = ids.indexOf(realIndex);
    if (friendsTemplateIndex >= 0) {
        ids[friendsTemplateIndex] = INVALID_INDEX;
        //удалить шаблон из основного массива
    }

    for (int iter = friendsTemplateIndex + 1; iter < ids.size(); ++iter) {
        if  (ids[iter] > 0)
            --ids[iter];
    }
    return friendsTemplateIndex;
}

int  TemplateIdTranslator::addWithRealIndex(int realIndex) {
    ids.append(realIndex);
    return ids.size() - 1;
}

int TemplateIdTranslator::getRealIndex(int friendTemplateIndex) {
    if (friendTemplateIndex < 0 || friendTemplateIndex >= ids.size()) {
        return INVALID_INDEX;
    }
    return ids[friendTemplateIndex];
}

int TemplateIdTranslator::getFriendIndex(int realIndex) {
    return ids.indexOf(realIndex);
}
