import pandas as pd
from json import loads


# 1. Вам необходимо узнать тип преступления, которое было зафиксировано максимальное
# число раз в 2015 году.
def first_task(year):
    data = pd.read_csv('Crimes.csv')
    data = data[['Date', 'Primary Type']]
    data['Date'] = pd.to_datetime(data['Date'])
    data = data[data['Date'].dt.to_period("Y") == year]
    return data['Primary Type'].value_counts().to_frame().idxmax()


# /////////////////////////////////////////////////////////////////////////////////////////
# 2. Вам дано описание наследования классов в формате JSON.
# Описание представляет из себя массив JSON-объектов, которые соответствуют классам.
# У каждого JSON-объекта есть поле name, которое содержит имя класса, и поле parents,
# которое содержит список имен прямых предков.
# Для каждого класса вычислите предком скольких классов он является и выведите эту информацию.
def get_parents_list(class_name, data):
    for obj in data:
        if obj['name'] == class_name:
            return obj['parents']
    return []


def check_in_parents_list(from_class_name, to_class_name, data):
    for parent in get_parents_list(from_class_name, data):
        if parent == to_class_name:
            return True
        else:
            ancestor = check_in_parents_list(parent, to_class_name, data)
            if ancestor:
                return ancestor
    return False


def second_task():
    data = loads(input())
    result_dict = {}
    for parent in data:
        for child in data:
            if child['name'] not in result_dict:
                result_dict[child['name']] = 1
            if parent['name'] != child['name'] and check_in_parents_list(parent['name'],
                                                                         child['name'],
                                                                         data):
                result_dict[child['name']] += 1

    result_lst = [{"name": name, "value": result_dict[name]} for name in result_dict]
    for el in sorted(result_lst, key=lambda obj: obj['name']):
        print(f"{el['name']} : {el['value']}")


def main():
    print(first_task('2015'))
    second_task()


if __name__ == '__main__':
    main()
