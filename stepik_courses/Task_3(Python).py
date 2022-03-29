# 3.1 Вывести числа от 1 до 100 включительно. Если число делится на 3 то вместо него вывести Foo.
# Если делится на 5 то вывести Bar. Если делится на 3 и на 5 то вывести FooBar.

# 3.2 Hard mode, optional: Реализовать фабрику декораторов, инициализируемую с натуральным числом n,
# производящую умножение результата декорируемой функции на n если операция применима, иначе возвращающих None.


def form_interesting_list():  # Task 3.3
    final_list = []

    for el in range(1, 101):
        if el // 3 == 0 and el // 5 == 0:
            final_list.append('FooBar')

        elif el // 3 == 0:
            final_list.append('Foo')

        elif el // 5 == 0:
            final_list.append('Bar')

        else:
            final_list.append(el)

        return final_list


def multiplication_by_n(n):  # Task 3.2
    def wrapper(func):
        if type(func) == int or type(func) == float:
            return func() * n

    return wrapper


@multiplication_by_n(n=5)
def take_number():
    return int(input('Write number:'))


print(form_interesting_list())
