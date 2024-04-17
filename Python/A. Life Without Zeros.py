def toList(n):
    l = []
    while n != 0:
        l.append(n%10)
        n /= 10
    return l

def noZero(list):
    n = 0
    sum = 0
    pow = 0
    while n < len(list):
        if list[n] != 0:
            sum += list[n]*(10**pow)
            pow += 1
        n += 1
    return sum

a = int(raw_input())
b = int(raw_input())
c = a+b
a = noZero(toList(a))
b = noZero(toList(b))
c = noZero(toList(c))

if a + b == c:
    print "YES"
else:
    print "NO"


