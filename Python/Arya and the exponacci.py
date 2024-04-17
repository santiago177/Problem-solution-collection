mod = (10**9)+7
list = [1, 1]
def fill():
    for e in range(2, 100000):
        list.append(list[e-1] + list[e-2])

def mod_pow(base, exp):  
    res = 1
    while exp > 0:
        if exp % 2 == 1:
            res = (res * base) % mod
        exp = exp >> 1
        base = (base * base) % mod
    return res

def fibonacci(n):
        for e in range(5000001, n):
            p = (list[1] + list[0]) % mod
            list[0] = list[1] % mod
            list[1] = p
        return list[1]
    
def exponacci(n):
    if n == 0:
        return 1
    else:
        if(n-1 <= 100000):
            a = list[n-1]
        else:
            a = fibonacci(n-1)
        #print "fib = ", a
        return mod_pow(2, a)
        
        

n = int(raw_input())
fill()
print n
while n > 0:
    a = int(raw_input())
    print exponacci(a)
    n -= 1
