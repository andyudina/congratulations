#ifndef LISTELEMENT_H
#define LISTELEMENT_H

#include "congratulations_lib_global.h"
#include "settingsheader.h"

struct CONGRATULATIONS_LIBSHARED_EXPORT AbstractListEntry {
    int id;

    AbstractListEntry(): id(0) {}
    explicit AbstractListEntry(int id_): id(id_) {}

    virtual ~AbstractListEntry() {}

    static bool idIsLess(AbstractListEntry* entry1, AbstractListEntry* entry2) {
        return entry1->id < entry2->id;
    }
};

struct CONGRATULATIONS_LIBSHARED_EXPORT FriendEntry : public AbstractListEntry {
    QString photo;
    QString name;
    QString date;
    bool isDeleted;
    bool isMissed;
    QString templateText;
    QList<int> templateIds;

    explicit FriendEntry(QString photo_,
                         QString name_,
                         QString date_,
                         bool isDeleted_,
                         bool isMissed_,
                         const QList<int>& templateIds_,
                         int id_=0,
                         QString templateText_ = QString()): AbstractListEntry(id_), photo(photo_), name(name_),date(date_),
                                                             isDeleted(isDeleted_),
                                                             isMissed(isMissed_),
                                                             templateText(templateText_),
                                                             templateIds(templateIds_){}

    static bool nameIsLess(AbstractListEntry* entry1, AbstractListEntry* entry2) {
        return reinterpret_cast<FriendEntry*>(entry1)->name < reinterpret_cast<FriendEntry*>(entry2)->name;
    }

};

struct CONGRATULATIONS_LIBSHARED_EXPORT SettingsEntry: public AbstractListEntry {
    QString text;
    int state;
    virtual void editSettings(int){}

    SettingsEntry(QString text_, int id_ = 0):  AbstractListEntry(id_), text(text_), state(HEADER){}
    SettingsEntry(QString text_, int state_ , int id_ = 0):  AbstractListEntry(id_),
        text(text_), state(state_) {}

};

struct CONGRATULATIONS_LIBSHARED_EXPORT ListSettingsEntry: public SettingsEntry {
    QStringList optionsList;
    int selectedOption;

    virtual void editSettings(int option) {
        selectedOption = option;
    }

    ListSettingsEntry(QString text_,
                      const QStringList& optionsList_,
                      int selectedOption_,
                      int id_=0):
        SettingsEntry(text_, LIST_ENTRY_STATE, id_),
        optionsList(optionsList_),
        selectedOption(selectedOption_) {}


};

struct CONGRATULATIONS_LIBSHARED_EXPORT OffOnSettingsEntry : public SettingsEntry {
    bool isOn;
    OffOnSettingsEntry(QString text_,
                       bool isOn_,
                       int id_=0):

        SettingsEntry(text_, OFF_ON_ENTRY_STATE, id_),
        isOn(isOn_) {}

    virtual void editSettings(int option) {
        isOn = (option != 0);
    }
};

struct CONGRATULATIONS_LIBSHARED_EXPORT BdayEntry: public AbstractListEntry
{
    QString photo;
    QString color;
    QString borderColor;
    QString textColor;
    QString name;
    QString date;
    bool isMissed;

    explicit BdayEntry(QString photo_,
                       QString color_,
                       QString borderColor_,
                       QString textColor_,
                       QString name_,
                       QString date_,
                       bool isMissed_,
                       int id_=0): AbstractListEntry(id_), photo(photo_), color(color_), borderColor(borderColor_), textColor(textColor_), name(name_), date(date_), isMissed(isMissed_)
    {}

    static bool dateIsLess(AbstractListEntry* entry1, AbstractListEntry* entry2) {
        return reinterpret_cast<BdayEntry*>(entry1)->date < reinterpret_cast<BdayEntry*>(entry2)->date;
    }


};

struct CONGRATULATIONS_LIBSHARED_EXPORT TemplateEntry : public AbstractListEntry
{
    QString title;
    QString text;

    explicit TemplateEntry(QString title_,
                           QString text_,
                           int id_=0): AbstractListEntry(id_), title(title_), text(text_)
    {}

};


#endif // LISTELEMENT_H
