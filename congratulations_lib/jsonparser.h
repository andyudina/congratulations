#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "listelement.h"
#include <QJsonObject>

class JSONParser
{
public:
    JSONParser();
    //принимает JSON бъект с инфой о друзях - возвращает список друзей
    QList<AbstractListEntry*> parseJSON(const QJsonObject&);
};

#endif // JSONPARSER_H
