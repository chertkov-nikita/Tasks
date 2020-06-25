# 2.1 Вывести символы в нижнем регистре, которые окружают 1 или более символа в верхнем регистре.
# Решить задачу двумя способами: с помощью re и без. Пример: 'advDjKOlP' >> 'jl'

# 2.2 Вывести символы в верхнем регистре, которые окружают ровно два символа в нижнем регистре слева и
# два символа в верхнем регистре справа.
# Решить задачу двумя способами: с помощью re и без. Пример: 'advDjdKOPppDDD' >> 'KD'

# 2.3 Записать исходную строку в 5 разных файлов (1-й символ в первый, второй во второй и т.д.),
# имеющих названия 'file_1', 'file_2' и т.д.

import re

line = 'mtMmEZUOmcqWiryMQhhTxqKdSTKCYEJlEZCsGAMkgAYEOmHBSQsSUHKvSfbmxULaysmNOGIPHpEMujalpPLNzRWXfwHQqwksrFeipEUlTLec' \
       'lMwAoktKlfUBJHPsnawvjPhfgewVzKTUfSYtBydXaVIpxWjNKgXANvIoumesCSSvjEGRJosUfuhRRDUuTQwLlJJJDdkVjfSAHqnLxooisBDW' \
       'uxIhyjJaXDYwdoVPnsllMngNlmkpYOlqXEFIxPqqqgAWdJsOvqppOfyIVjXapzGOrfinzzsNMtBIOclwbfRzytmDgEFUzxvZGkdOaQYLVBfs' \
       'GSAfJMchgBWAsGnBnWetekUTVuPluKRMQsdelzBgLzuwiimqkFKpyQRzOUyHkXRkdyIEBvTjdByCfkVIAQaAbfCvzQWrMMsYpLtdqRltXPqc' \
       'SMXJIvlBzKoQnSwPFkapxGqnZCVFfKRLUIGBLOwhchWCdJbRuXbJrwTRNyAxDctszKjSnndaFkcBZmJZWjUeYMdevHhBJMBSShDqbjAuDGTT' \
       'rSXZywYkmjCCEUZShGofaFpuespaZWLFNIsOqsIRLexWqTXsOaScgnsUKsJxiihwsCdBViEQBHQaOnLfBtQQShTYHFqrvpVFiiEFMcIFTrTk' \
       'IBpGUflwTvAzMUtmSQQZGHlmQKJndiAXbIzVkGSeuTSkyjIGsiWLALHUCsnQtiOtrbQOQunurZgHFiZjWtZCEXZCnZjLeMiFlxnPkqfJFbCf' \
       'KCuUJmGYJZPpRBFNLkqigxFkrRAppYRXeSCBxbGvqHmlsSZMWSVQyzenWoGxyGPvbnhWHuXBqHFjvihuNGEEFsfnMXTfptvIOlhKhyYwxLnq' \
       'OsBdGvnuyEZIheApQGOXWeXoLWiDQNJFaXiUWgsKQrDOeZoNlZNRvHnLgCmysUeKnVJXPFIzvdDyleXylnKBfLCjLHntltignbQoiQzTYwZA' \
       'iRwycdlHfyHNGmkNqSwXUrxgc'


def form_string_surrounded_by_upper_case_letters(string):  # Task 2.1
    final_str_re = ''.join(re.findall(r'[A-Z][a-z][A-Z]', string))

    final_str = ''
    i = 1
    while i < len(string) - 1:
        if string[i - 1:i + 2: 2].isupper() and string[i].islower():
            final_str += string[i]
        i += 1

    return final_str_re, final_str


def form_string_surrounded_by_upper_and_lower_case_letters(string):  # Task 2.2
    final_str_re = ''.join(re.findall(r'[a-z]*2[A-Z][A-Z]*2', string))

    final_str = ''
    i = 2
    while i < len(string) - 2:
        if string[i - 2:i].islower() and string[i:i+3].isupper():
            final_str += string[i]
        i += 1

    return final_str_re, final_str


def write_in_files(file_name, string):  # Task 2.3
    for i in range(1, 6):
        f = open(file_name + str(i) + '.txt', 'w')
        j = i - 1
        while j < len(string):
            f.write(string[j])
            j += 5
        f.close()


