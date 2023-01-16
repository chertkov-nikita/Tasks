import re
import requests


# 1. Вашей программе на вход подаются две строки, содержащие url двух документов A и B.
# Выведите Yes, если из A в B можно перейти за два перехода, иначе выведите No.
def first_task():
    url_a = input()
    url_b = input()

    main_res = requests.get(url_a)
    if main_res.status_code == 200:
        urls = re.findall(r"<a.*href=\"(.*)\"", main_res.text)
        for url_c in urls:
            additional_res = requests.get(url_c)
            if additional_res.status_code == 200:
                if url_b in re.findall(r"<a.*href=\"(.*)\"", additional_res.text):
                    return "Yes"
        return "No"


# //////////////////////////////////////////////////////////////////////////////////////////
# 2. Вашей программе на вход подается ссылка на HTML файл.
# Вам необходимо скачать этот файл, затем найти в нем все ссылки вида <a ... href="..." ... >
# и вывести список сайтов, на которые есть ссылка.
# Сайтом в данной задаче будем называть имя домена вместе с именами поддоменов.
def second_task():
    url = input()
    res = requests.get(url.strip())
    results = []

    if res.status_code == 200:
        url_list = re.findall(r"<a(.*?)href(.*?)=(.*?)(\"|\')(((.*?):\/\/)|(\.\.)|)(.*?)(\/|:|\"|\')(.*)", res.text)
        for url in url_list:
            domain = url[8]
            if domain not in results and domain != '':
                results.append(domain)
        results.sort()
        return results


def main():
    print(first_task())
    for name in second_task():
        print(name)


if __name__ == '__main__':
    main()
