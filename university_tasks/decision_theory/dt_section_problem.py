from cvxopt import matrix, glpk
import math

c = matrix([0, 0, 0, 0, -1], tc="d")
G = matrix([[-1, 0, 0, 0, 4],
            [0, -2, -1, 0, 1],
            [-1, 0, -2, -5, 1],
            [-1, 0, 0, 0, 0],
            [0, -1, 0, 0, 0],
            [0, 0, -1, 0, 0],
            [0, 0, 0, -1, 0],
            [0, 0, 0, 0, -1]], tc="d")
h = matrix([0, 0, 0, 0, 0, 0, 0, -1], tc="d")
A = matrix([[1, 1, 1, 1, 0]], tc="d")
b = matrix([50], tc="d")
(status, x) = glpk.ilp(c, G.T, h, A.T, b, I=set([0, 1, 2, 3, 4]))
print(status)
print(*x)


print("\n")
print("Second point")
c = matrix([90, 10, 60, 0, 0], tc="d")
h = matrix([0, 0, 0, 0, 0, 0, 0, -11], tc="d")
(status, x) = glpk.ilp(c, G.T, h, A.T, b, I=set([0, 1, 2, 3, 4]))
print(status)
print(*x)


print("\n")
ls = []
c = matrix([0, 0, 0, 0, -1], tc="d")
G = matrix([[-1, 0, 0, 0, 4],
            [0, -2, -1, 0, 1],
            [-1, 0, -2, -5, 1],
            [-1, 0, 0, 0, 0],
            [0, -1, 0, 0, 0],
            [0, 0, -1, 0, 0],
            [0, 0, 0, -1, 0],
            [0, 0, 0, 0, -1]], tc="d")
h = matrix([0, 0, 0, 0, 0, 0, 0, -1], tc="d")
A = matrix([[1, 1, 1, 1, 0]], tc="d")


for k in range(1, 11):
    ls.append([0, 0, 0, 0, 0])
    db = matrix([50 + k], tc="d")
    (status, x) = glpk.ilp(c, G.T, h, A.T, db, I=set([0, 1, 2, 3, 4]))
    ls[k - 1][0] = x[0]
    ls[k - 1][1] = x[1]
    ls[k - 1][2] = x[2]
    ls[k - 1][3] = x[3]
    ls[k - 1][4] = x[4]

print("\n")
print("Third point")
for i in range(len(ls)):
    print(*ls[i])
