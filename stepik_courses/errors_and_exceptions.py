# 1. Вам необходимо написать код, который запускает эту функцию, затем ловит исключения
# ArithmeticError, AssertionError, ZeroDivisionError и выводит имя пойманного исключения.


def foo(first_arg, second_arg):
    return first_arg / second_arg


def first_task():
    try:
        foo(1, 0)
    except ZeroDivisionError:
        print("ZeroDivisionError")
    except ArithmeticError:
        print("ArithmeticError")
    except AssertionError:
        print("AssertionError")


# /////////////////////////////////////////////////////////////////////////////////////////////////////////

# 2. Промоделировать этот процесс, и понять какие из исключений можно и не ловить,
# потому что мы уже ранее где-то поймали их предка.

def create_exceptions(count):
    exceptions_tree = {}
    for _ in range(count):
        string_exceptions_creating = input()
        if len(string_exceptions_creating.split()) == 1:
            key = string_exceptions_creating
            value = []
        else:
            key, value = string_exceptions_creating.split(' : ')
            value = value.split(' ')
        exceptions_tree[key] = value

    not_obvious_classes = list(set(sum([val for val in exceptions_tree.values()], [])))

    print(not_obvious_classes)
    for cl in not_obvious_classes:
        if cl not in exceptions_tree.keys():
            exceptions_tree[cl] = []

    return exceptions_tree


def create_requests(count):
    requests = [input() for _ in range(count)]
    print(requests)
    return requests


def check_parent(tree, parent, child):
    if child not in tree.keys():
        return False
    elif parent in tree[child] or parent == child:
        return True
    elif not tree[child]:
        return False

    for val in tree[child]:
        if check_parent(tree, parent, val):
            return True

    return False


def second_task():
    n = int(input())
    tree = create_exceptions(n)
    print(tree)
    answers = []
    q = int(input())
    requests = create_requests(q)

    for i in range(1, q):
        for request in requests[:i]:
            if check_parent(tree, request, requests[i]) and requests[i] not in answers:
                answers.append(requests[i])

    for answer in answers:
        print(answer)


# ///////////////////////////////////////////////////////////////////////

# 3. Реализуйте класс PositiveList, наследуя его от класса list, для хранения положительных целых чисел.
# Также реализуйте новое исключение NonPositiveError.


def main():
    # first_task()
    second_task()


if __name__ == '__main__':
    main()
