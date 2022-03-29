#include "cashbox.h"

TCashbox::TCashbox()
{
   queue_len = 0;
   queue = nullptr;
}

void TCashbox::add_in_queue()
{
    TEmployee *newstr1 = new TEmployee;
    TEmployee *d = queue;
    if (queue_len == 0)
    {
        queue = newstr1;
        queue->next = nullptr;
    }
    else
    {
        for (int i = 0; i < queue_len; i++)
        {
            if (i == queue_len - 1)
            {
                d->next = newstr1;
                newstr1->prev = d;
                newstr1->next = nullptr;
            }
            else
            {
                d = d->next;
            }
        }
    }
    queue_len++;
}

void TCashbox::delete_from_queue()
{
    TEmployee *d = queue;

    queue = d->next;
    delete d;
    queue_len--;
}

void TCashbox::close_cashbox()
{
    TEmployee* d = queue;
    TEmployee* save = d;

    while (save != nullptr)
    {
        d = d->next;
        delete save;
        save = d;
    }
    queue = nullptr;
    queue_len = 0;
}

int TCashbox::get_len()
{
    return queue_len;
}
