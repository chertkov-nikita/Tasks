# 1. В данной задаче мы просим вас реализовать класс multifilter, который будет выполнять ту же функцию,
# что и стандартный класс filter, но будет использовать не одну функцию, а несколько.

def mul2(x):
    return x % 2 == 0


def mul3(x):
    return x % 3 == 0


def mul5(x):
    return x % 5 == 0


class MultiFilter:
    def judge_half(self, pos, neg):  # допускает элемент, если его допускает хотя бы половина фукнций (pos >= neg)
        return pos >= neg

    def judge_any(self, pos, neg):  # допускает элемент, если его допускает хотя бы одна функция (pos >= 1)
        return pos >= 1

    def judge_all(self, pos, neg):  # допускает элемент, если его допускают все функции (neg == 0)
        return neg == 0

    def __init__(self, iterable, *funcs, judge=judge_any):
        # iterable - исходная последовательность
        # funcs - допускающие функции
        # judge - решающая функция
        self.result_list = []
        for el in iterable:
            pos = 0
            neg = 0
            for func in funcs:
                if func(el):
                    pos += 1
                else:
                    neg += 1

            if judge(self, pos, neg):
                self.result_list.append(el)

    def __iter__(self):  # возвращает итератор по результирующей последовательности
        return iter(self.result_list)


def first_task():
    a = [el for el in range(31)]

    print(list(MultiFilter(a, mul2, mul3, mul5)))
    print(list(MultiFilter(a, mul2, mul3, mul5, judge=MultiFilter.judge_half)))
    print(list(MultiFilter(a, mul2, mul3, mul5, judge=MultiFilter.judge_all)))


# //////////////////////////////////////////////////////////////////////////////////////////////////////////
# 2. Реализуйте функцию-генератор primes,
# которая будет генерировать простые числа в порядке возрастания, начиная с числа 2.

def second_task():
    pass


def main():
    first_task()
    second_task()


if __name__ == '__main__':
    main()
