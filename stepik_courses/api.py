import requests
import json
from identifiers import client_id, client_secret


# 1. Вам дается набор чисел. Для каждого из чисел необходимо узнать,
# существует ли интересный математический факт об этом числе.
def first_task(list_of_numbers):
    for number in list_of_numbers:
        url = f"http://numbersapi.com/{number}/math?json=true"
        response = requests.get(url)
        if response.status_code == 200:
            if response.json()['found']:
                print("Interesting")
            else:
                print("Boring")


# //////////////////////////////////////////////////////////////////////////////////////////////
# 2. Вам даны идентификаторы художников в базе Artsy.
# Для каждого идентификатора получите информацию о имени художника и годе рождения.
# Выведите имена художников в порядке неубывания года рождения.
# В случае если у художников одинаковый год рождения, выведите их имена в лексикографическом порядке.
def get_information_from_artsy(token, list_of_ids):
    information = {}
    for id in list_of_ids:
        headers = {"X-Xapp-Token": token}
        url = f"https://api.artsy.net/api/artists/{id}"
        response = requests.get(url, headers=headers)
        response.encoding = "utf-8"
        if response.status_code == 200:
            information[response.json()['sortable_name']] = response.json()['birthday']
    return sorted(information.items(), key=lambda x: (x[1], x[0]))


def second_task(list_of_id):
    # инициируем запрос на получение токена
    r = requests.post("https://api.artsy.net/api/tokens/xapp_token",
                      data={
                          "client_id": client_id,
                          "client_secret": client_secret
                      })
    # разбираем ответ сервера
    j = json.loads(r.text)
    # достаем токен
    token = j["token"]
    # получаем информацию о имени художника
    information = get_information_from_artsy(token, list_of_id)
    # выводим информацию о имени художника
    for name, birthday in information:
        print(name)


def main():
    # first_task([992, 995, 900, 996, 936, 968, 942, 943, 976, 982, 919, 921, 955, 925, 991])
    with open("dataset.txt", "r") as f:
        list_of_ids = f.read().splitlines()
    print(list_of_ids)
    second_task(list_of_ids)


if __name__ == '__main__':
    main()
