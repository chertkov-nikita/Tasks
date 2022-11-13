# В первой строке дано три числа, соответствующие некоторой дате date -- год, месяц и день.
# Во второй строке дано одно число days -- число дней.
# Вычислите и выведите год, месяц и день даты, которая наступит,
# когда с момента исходной даты date пройдет число дней, равное days.

import datetime

if __name__ == '__main__':
    date_list = list(map(int, input().split()))
    date = datetime.date(date_list[0], date_list[1], date_list[2])

    delta_day = int(input())
    days = datetime.timedelta(days=delta_day)
    result_date = date + days
    print(result_date.year, result_date.month, result_date.day)
