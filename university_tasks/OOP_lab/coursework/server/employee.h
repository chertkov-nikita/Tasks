#ifndef TEMPLOYEE_H
#define TEMPLOYEE_H


class TEmployee
{
    int id;
    char first_name[10];
    char second_name[15];
    double salary;

public:
    TEmployee* next;
    TEmployee* prev;

    TEmployee();
    TEmployee(int);
    int get_id();
};

#endif // TEMPLOYEE_H
