#include "employee.h"

TEmployee::TEmployee()
{

}

TEmployee::TEmployee(int num)
{
    id = num;
}

int TEmployee::get_id()
{
    return id;
}
