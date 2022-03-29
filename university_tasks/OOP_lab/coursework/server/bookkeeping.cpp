#include "bookkeeping.h"
#include <random>

TBookkeeping::TBookkeeping()
{
    cashbox_count = 1;
    cashbox_list = new TCashbox[cashbox_count];
}

void TBookkeeping::change_cashbox_cnt(int number)
{
    int min_len = number>cashbox_count?cashbox_count:number;

    TCashbox *tmp = new TCashbox [number];

    for (int i = 0 ;i < min_len; i++)
        tmp[i] = cashbox_list[i];
    for (int i = min_len; i < cashbox_count; i++)
        cashbox_list[i].close_cashbox();
    delete [] cashbox_list;
    cashbox_count = number;
    cashbox_list = tmp;
}

void TBookkeeping::add_new_employee()
{
    double summ_len_queues = 0;
    int len = 0;
    if (cashbox_count == 1)
        cashbox_list[0].add_in_queue();
    else
    {
        for (int i = 0; i < cashbox_count; i++)
        {
            len = cashbox_list[i].get_len();
            if (len == 0)
            {
                cashbox_list[i].add_in_queue();
                return;
            }
            else
            {
                summ_len_queues += len;
            }
        }

        double r = ((double)rand()/RAND_MAX);
        int i = 0;
        for (i = 0; i < cashbox_count; i++)
        {
            r -= (1 - cashbox_list[i].get_len()/summ_len_queues)/(cashbox_count - 1);
            if (r <= 0)
            {
                cashbox_list[i].add_in_queue();
                return;
            }
        }
        cashbox_list[i - 1].add_in_queue();
    }
}


void TBookkeeping::delete_employee()
{
    for (int i = 0; i < cashbox_count; i++)
    {
        if (cashbox_list[i].get_len() > 0)
            cashbox_list[i].delete_from_queue();
    }
}
int TBookkeeping::get_cashbox_cnt()
{
    return cashbox_count;
}

TCashbox* TBookkeeping::get_cashbox_list()
{
    return cashbox_list;
}
