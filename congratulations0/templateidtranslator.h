#ifndef TEMPLATEIDTRANSLATOR_H
#define TEMPLATEIDTRANSLATOR_H

#include <QList>

//транслирует id шаблонов в списке с учетом удаленных и без учета удаленных
//зачем: чтобы не лазить чуть что в БД
//чтобы не обновлять template_id в списках всех друзей при каждом изменении щаблона
class TemplateIdTranslator
{
public:

    TemplateIdTranslator(int capacity);
    TemplateIdTranslator() = default;
    ~TemplateIdTranslator() = default;

    void initialize(int capacity);

    int deleteRealIndex(int realIndex);

    int  addWithRealIndex(int realIndex);

    int getRealIndex(int friendTemplateIndex);

    int getFriendIndex(int realIndex);

private:
    QList<int> ids; //индекс в списке - id без учета удаления
                    //значение по индексу - реальное значение индекса в списке шаблонов
                    //(с учетом удаления)
};

#endif // TEMPLATEIDTRANSLATOR_H
