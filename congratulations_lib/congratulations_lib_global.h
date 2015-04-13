#ifndef CONGRATULATIONS_LIB_GLOBAL_H
#define CONGRATULATIONS_LIB_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QObject>
#include <QList>
#include <QStringList>
#include <initializer_list>

#if defined(CONGRATULATIONS_LIB_LIBRARY)
#  define CONGRATULATIONS_LIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CONGRATULATIONS_LIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CONGRATULATIONS_LIB_GLOBAL_H
