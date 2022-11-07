class MoneyBox:
    def __init__(self, capacity):
        self.money = 0
        self.capacity = capacity

    def can_add(self, value):
        return self.money + value <= self.capacity

    def add(self, value):
        self.money += value


class Buffer:
    def __init__(self):
        self.numbers = []

    def add(self, *args):
        self.numbers.extend(args)
        while len(self.numbers) >= 5:
            print(sum(self.numbers[:5]))
            self.numbers = self.numbers[5:]

    def get_current_part(self):
        return self.numbers


def main():
    buf = Buffer()
    buf.add(1, 2, 3)
    buf.get_current_part()  # вернуть [1, 2, 3]
    buf.add(4, 5, 6)  # print(15) – вывод суммы первой пятерки элементов
    buf.get_current_part()  # вернуть [6]
    buf.add(7, 8, 9, 10)  # print(40) – вывод суммы второй пятерки элементов
    buf.get_current_part()  # вернуть []
    buf.add(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1)  # print(5), print(5) – вывод сумм третьей и четвертой пятерки
    buf.get_current_part()  # вернуть [1]


if __name__ == '__main__':
    main()
