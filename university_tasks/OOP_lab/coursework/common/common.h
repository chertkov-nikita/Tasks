#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum messages
{
    CHANGE_SETTINGS_REQUEST = 1,
    CHANGE_SETTINGS_ANSWER,
    ADD_EMPLOYEE_REQUEST,
    ADD_EMPLOYEE_ANSWER,
    DELETE_EMPLOYEE_REQUEST,
    DELETE_EMPLOYEE_ANSWER,
    GET_DATA_REQUEST,
    GET_DATA_ANSWER,
};

extern const char separator;
QString& operator<< (QString&,const QString&);

#endif // COMMON_H
