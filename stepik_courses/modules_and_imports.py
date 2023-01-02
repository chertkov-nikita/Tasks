# В первой строке дано три числа, соответствующие некоторой дате date -- год, месяц и день.
# Во второй строке дано одно число days -- число дней.
# Вычислите и выведите год, месяц и день даты, которая наступит,
# когда с момента исходной даты date пройдет число дней, равное days.

import datetime

import simplecrypt


def first_task():
    date_list = list(map(int, input().split()))
    date = datetime.date(date_list[0], date_list[1], date_list[2])

    delta_day = int(input())
    days = datetime.timedelta(days=delta_day)
    result_date = date + days
    print(result_date.year, result_date.month, result_date.day)


# ///////////////////////////////////////////////////////////////////////////////////
# Вам необходимо установить библиотеку simple-crypt, и с помощью метода simplecrypt.decrypt узнать, какой из паролей
# служит ключом для расшифровки файла с интересной информацией.

def second_task():
    with open("encrypted.bin", "rb") as inp:
        encrypted = inp.read()
    with open("passwords.txt", "r") as psw:
        passwords = psw.read()
    decrypted = 'Passwords is not available!'
    for key in passwords.split('\n'):
        try:
            decrypted = simplecrypt.decrypt(key, encrypted)
        except simplecrypt.DecryptionException:
            continue
        else:
            print(decrypted.decode('utf-8'))
            with open('answers.txt', 'w') as out:
                out.write(decrypted.decode('utf-8'))
            break


if __name__ == '__main__':
    # first_task()
    second_task()
