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
    if len(re.findall(pattern, string)):
        print(string)


def main():
    for line in sys.stdin:
        line = line.rstrip()
        # first_task(line)
        second_task(line)


if __name__ == '__main__':
    main()
