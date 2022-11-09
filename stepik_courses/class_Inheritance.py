# Задание 1. Промоделировать процесс наследования классов и понять существует ли путь от одного класса до другого.
def create_class(count):
    class_tree = {}
    for __ in range(count):
        string_class_creating = input()
        if len(string_class_creating.split()) == 1:
            key = string_class_creating
            value = []
        else:
            key, value = string_class_creating.split(' : ')
            value = value.split(' ')
        class_tree[key] = value

    not_obvious_classes = list(set(sum([val for val in class_tree.values()], [])))

    print(not_obvious_classes)
    for cl in not_obvious_classes:
        if cl not in class_tree.keys():
            class_tree[cl] = []

    return class_tree


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


def first_task():
    n = int(input())
    tree = create_class(n)
    print(tree)
    answers = []
    q = int(input())
    for __ in range(q):
        string_request = input().split(' ')
        if check_parent(tree, string_request[0], string_request[1]):
            answers.append('Yes')
        else:
            answers.append('No')
    for answer in answers:
        print(answer)


# ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

# Задание 2. Реализуйте структуру данных, представляющую собой расширенную структуру стек.
# Необходимо поддерживать добавление элемента на вершину стека, удаление с вершины стека,
# и необходимо поддерживать операции сложения, вычитания, умножения и целочисленного деления.


class ExtendedStack(list):
    def sum(self):
        self[-1] = list.pop(self) + self[-1] if len(self) >= 2 else self[-1]

    def sub(self):
        self[-1] = list.pop(self) - self[-1] if len(self) >= 2 else self[-1]

    def mul(self):
        self[-1] = list.pop(self) * self[-1] if len(self) >= 2 else self[-1]

    def div(self):
        self[-1] = list.pop(self) // self[-1] if len(self) >= 2 else self[-1]


def second_task():
    ex_stack = ExtendedStack([1, 2, 3])
    print(ex_stack)
    ex_stack.div()
    print(ex_stack)


# ////////////////////////////////////////////////////////////////////////////////////

# Задание 3. Реализуйте класс LoggableList, отнаследовав его от классов list и Loggable таким образом,
# чтобы при добавленииэлемента в список посредством метода append в лог отправлялось сообщение,
# состоящее из только что добавленного элемента.


import time


class Loggable:
    def log(self, msg):
        print(str(time.ctime()) + ": " + str(msg))


class LoggableList(list, Loggable):
    def append(self, item):
        list.append(self, item)
        Loggable.log(self, item)


def third_task():
    log_list = LoggableList()
    log_list.append(1)
    log_list.append(2)
    print(log_list)


def main():
    # first_task()
    # second_task()
    third_task()


if __name__ == '__main__':
    main()
