# 1. Вам необходимо написать код, который запускает эту функцию, затем ловит исключения
# ArithmeticError, AssertionError, ZeroDivisionError и выводит имя пойманного исключения.


def foo(first_arg, second_arg):
    return first_arg/second_arg


def first_task():
    try:
        foo(1, 0)
    except ZeroDivisionError:
        print("ZeroDivisionError")
    except ArithmeticError:
        print("ArithmeticError")
    except AssertionError:
        print("AssertionError")


if __name__ == '__main__':
    first_task()
