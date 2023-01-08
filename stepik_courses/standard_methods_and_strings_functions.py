# 1. Вашей программе на вход подаются три строки s, a, b, состоящие из строчных латинских букв.
# За одну операцию вы можете заменить все вхождения строки a в строку s на строку b.
# Необходимо узнать, после какого минимального количества операций в строке s не останется вхождений строки a.
# Если операций потребуется более 1000, выведите Impossible.

def first_task():
    s = input()
    a = input()
    b = input()

    if a == b and s.find(a) != -1:
        return "Impossible"
    for i in range(1000):
        s_copy = s
        s = s.replace(a, b)
        if s_copy == s:
            return i
    return "Impossible"


# //////////////////////////////////////////////////////////////////////////////////////////
# 2. Вашей программе на вход подаются две строки s и t, состоящие из строчных латинских букв.
# Выведите одно число – количество вхождений строки t в строку s.

def second_task(string, substring):
    count = 0
    i = -1
    while True:
        i = string.find(substring, i + 1)
        if i == -1:
            return count
        count += 1


def main():
    print(first_task())
    print(second_task(input(), input()))


if __name__ == '__main__':
    main()
