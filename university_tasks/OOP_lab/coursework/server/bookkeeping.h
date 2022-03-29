#ifndef TDATA_H
#define TDATA_H

#include "cashbox.h"

class TBookkeeping
{
    int cashbox_count;
    TCashbox *cashbox_list;

public:
    TBookkeeping();
    void change_cashbox_cnt(int);
    void add_new_employee();
    void delete_employee();
    int get_cashbox_cnt();
    TCashbox* get_cashbox_list();
};

#endif // TDATA_H
