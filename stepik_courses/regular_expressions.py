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


# ////////////////////////////////////////////////////////////////////////////////////////
# 6. В каждой строке замените все вхождения подстроки "human" на подстроку "computer" и выведите полученные строки.
def sixth_task(string):
    pattern = r"human"
    print(string.replace(pattern, "computer"))


# ////////////////////////////////////////////////////////////////////////////////////////
# 7. В каждой строке замените первое вхождение слова,
# состоящего только из латинских букв "a" (регистр не важен), на слово "argh".
def seventh_task(string):
    print(re.sub(r"\ba+\b", "argh", string, count=1, flags=re.IGNORECASE))


# ////////////////////////////////////////////////////////////////////////////////////////
# 8. В каждой строке поменяйте местами две первых буквы в каждом слове, состоящем хотя бы из двух букв.
def eighth_task(string):
    print(re.sub(r"\b(\w)(\w)(\w*)\b", r"\2\1\3", string))


# ////////////////////////////////////////////////////////////////////////////////////////
# 9. В каждой строке замените все вхождения нескольких одинаковых букв на одну букву.
def ninth_task(string):
    print(re.sub(r"(\w)\1+", r"\1", string))


def main():
    for line in sys.stdin:
        line = line.rstrip()
        first_task(line)
        second_task(line)
        third_task(line)
        fourth_task(line)
        fifth_task(line)
        sixth_task(line)
        seventh_task(line)
        eighth_task(line)
        ninth_task(line)


if __name__ == '__main__':
    main()
