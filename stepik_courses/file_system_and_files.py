import os
import os.path


# 1. Вам дается текстовый файл, содержащий некоторое количество непустых строк.
# На основе него сгенерируйте новый текстовый файл, содержащий те же строки в обратном порядке.

def first_task():
    str_list = []

    with open("input.txt", 'r') as i_f:
        for line in i_f.readlines():
            line = line.rstrip()
            str_list.append(line)

    str_list.reverse()

    with open("output.txt", 'w') as o_f:
        o_f.write("\n".join(str_list))


# //////////////////////////////////////////////////////////////////////////////////////////////////

# 2. Вам необходимо распаковать архив, и затем найти в файловой структуре все директории,
# в которых есть хотя бы один файл с расширением ".py".
def second_task():
    list_dirs = []
    for current_dir, dirs, files in os.walk("./main"):
        for filename in files:
            if filename.endswith(".py"):
                list_dirs.append(current_dir[2:])
                break
    list_dirs.sort()
    print('\n'.join(list_dirs))


def main():
    first_task()
    second_task()


if __name__ == "__main__":
    main()
