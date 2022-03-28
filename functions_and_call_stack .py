def closest_mod_5(x):
    if x % 5 == 0:
        return x
    y = x + 1
    while y % 5 != 0:
        y += 1
    return y


def C(n, k):
    if k > n:
        return 0
    elif k == 0:
        return 1
    else:
        return C(n - 1, k) + C(n - 1, k - 1)


print(closest_mod_5(5))
n, k = map(int, input().split())
print(C(n, k))
