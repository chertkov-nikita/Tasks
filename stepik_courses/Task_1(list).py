# 1.1 Вывести список уникальных чисел (встречаются только один раз)

# 1.2 Вывести список чисел <= 40, не встречающихся в исходном списке

# 1.3 Вывести данные в формате: (num: num_count), (num: num_count),
# num_count - кол-во num в списке.
# Отсортировать по убыванию num_count, при равенстве num_count по убыванию num.

# 1.4 Рассчитать среднеквадратичное отклонение.


from math import sqrt


data = [13, 29, 37, 49, 29, 7, 25, 5, 50, 2, 18, 0, 14, 16, 14, 4, 6, 14, 2, 5, 41, 27, 10, 11, 33, 6, 7, 47, 35, 35,
        48, 0, 38, 1, 41, 15, 26, 46, 4, 23, 5, 32, 45, 37, 2, 33, 20, 30, 46, 20, 10, 14, 44, 25, 3, 27, 6, 22, 9, 20,
        18, 43, 5, 33, 27, 41, 38, 20, 6, 2, 18, 29, 34, 40, 41, 8, 44, 30, 21, 10, 6, 1, 12, 0, 22, 28, 47, 4, 5, 1,
        11, 21, 1, 44, 24, 42, 42, 41, 14, 24]


def form_list_unique_numbers(numbers_list):  # Task 1.1
    final_list = []

    max_number = max(numbers_list)
    min_number = min(numbers_list)
    for number in range(min_number, max_number + 1):
        if numbers_list.count(number) == 1:
            final_list.append(number)

    return final_list


def form_list_non_occurring_numbers(numbers_list):  # Task 1.2
    final_list = []

    max_number = 40
    min_number = 0
    for number in range(min_number, max_number + 1):
        if not (number in numbers_list):
            final_list.append(number)

    return final_list


def form_sorted_dict(numbers_list):  # Task 1.3
    final_dict = {}

    max_number = max(numbers_list)
    min_number = min(numbers_list)
    for number in range(min_number, max_number + 1):
        final_dict[number] = numbers_list.count(number)

    return sorted(final_dict.keys())


def calculate_standard_deviation(numbers_list):  # Task 1.4
    return sqrt(sum((x - sum(numbers_list) / len(numbers_list)) ** 2 for x in numbers_list) / (len(numbers_list)))


sorted_data = data.copy()
sorted_data.sort()

print(form_list_unique_numbers(sorted_data))
print(form_list_non_occurring_numbers(sorted_data))
print(form_sorted_dict(sorted_data))
print(calculate_standard_deviation(sorted_data))
