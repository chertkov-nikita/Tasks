#ifndef TCASHBOX_H
#define TCASHBOX_H

#include "employee.h"

class TCashbox
{
    int number;
    TEmployee *queue;
    int queue_len;

public:
    TCashbox();

    void add_in_queue();
    void delete_from_queue();
    void close_cashbox();

    int get_len();
};

#endif // TCASHBOX_H
