list = []
cont = 0
ans = 0
n = int(raw_input())
cop = n
while n > 0:
    t = int(raw_input())
    list.append(t)
    cont += t
    n -= 1
div = cont / cop
for e in list:
    if e > div:
        ans += e-div
print ans
