import re
import sys


# 1. Выведите строки, содержащие "cat" в качестве подстроки хотя бы два раза.

def first_task(string):
    pattern = r"cat"
    if len(re.findall(pattern, string)) >= 2:
        print(string)


# ////////////////////////////////////////////////////////////////////////////////////////
# 2. Выведите строки, содержащие "cat" в качестве слова.
def second_task(string):
    pattern = r"\bcat\b"
    if re.search(pattern, string) is not None:
        print(string)


# ////////////////////////////////////////////////////////////////////////////////////////
# 3. Выведите строки, содержащие две буквы "z", между которыми ровно три символа.
def third_task(string):
    pattern = r"z.{3}z"
    if re.search(pattern, string) is not None:
        print(string)


# ////////////////////////////////////////////////////////////////////////////////////////
# 4. Выведите строки, содержащие обратный слеш "\".
def fourth_task(string):
    pattern = r"\\"
    if re.search(pattern, string) is not None:
        print(string)


# ////////////////////////////////////////////////////////////////////////////////////////
# 5. Выведите строки, содержащие слово, состоящее из двух одинаковых частей (тандемный повтор).
def fifth_task(string):
    pattern = r"\b(.+?)\1\b"
    if re.search(pattern, string) is not None:
        print(string)


def main():
    for line in sys.stdin:
        line = line.rstrip()
        first_task(line)
        second_task(line)
        third_task(line)
        fourth_task(line)
        fifth_task(line)


if __name__ == '__main__':
    main()
