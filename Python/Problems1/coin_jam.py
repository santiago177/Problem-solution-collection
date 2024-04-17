__author__ = 'Santiago'
import random

inf = open("coin.in", "r")
outf = open("coin.out", "w")
bitmask = [0]*33
valid = {}
'''def init():
    strings[0] = ""
    strings[1] = "1"
    for i in range(1, 32):
        s = "1"
        for j in range(1, i):
            s += "0"
        s+="1"
        strings[i+1] = s'''


def init():
    bitmask[0] = 0
    for i in range(32):
        k = 1<<i
        k |= 1
        bitmask[i+1] = k


def modexp(base, exp, mod):
    exp = int(exp)
    if mod == 1:
        return 0
    ans = 1
    base %= mod
    while exp > 0:
        if exp % 2 == 1:
            ans = (ans*base) % mod
        exp >>= 1
        base = (base*base) % mod
    return ans


def get_d_r(n):
    #print("randoms for", n)
    d = n-1
    r = 0
    while d % 2 == 0:
        d /= 2
        r += 1
    d = int(d)
    return d, r


def get_random(max):
    random.seed()
    return int((random.random()*(max-4))+2)


def composite_test(a, d, r, n):
    x = modexp(a, d, n)
    if x == 1 or x == n-1:
        return False
    for i in range(0, r):
        x = (x * x) % n
        if x == 1:
            return False
    return True


def rabin_miller(n):  # True means that n is probably prime, False means that n is composite
    d, r = get_d_r(n)
    for z in range(0, 10):
        a = get_random(n)
        if composite_test(a, d, r, n):
            return False
    return True


def get_div(n):
    for i in range(3, int(n/2)+1):
        if i > 100000:
            return 0
        if n % i == 0:
            return i


def cast_to(n, base):
    ans = 0
    pw = 0
    for i in reversed(n):
        ans += pow(base, pw)*(ord(i)-ord('0'))
        pw += 1

    return ans


def not_prime_for_all(n):  # False means that a probably prime number was found
    ans = []
    #print("testing", n)
    for i in range(2, 11):
        k = cast_to(bin(n)[2:], i)
        ans.append(k)
        if rabin_miller(k):
            return []
    #print("to get div")
    for i in range(0, len(ans)):
        ans[i] = get_div(ans[i])
        if ans[i] == 0:
            return []
    return ans


def generate(n):
    ans = []
    while True:
        #print("current n", bin(n)[2:])
        ans = not_prime_for_all(n)
        if len(ans) > 0:
            break
        n += 2
    return n, ans

def print_list(l):
    s = " "
    for i in l:
        s += str(i)+" "
    outf.write(s+"\n")


C = int(inf.readline())
for w in range(C):
    outf.write("Case #%d:\n"%(w+1))
    N, J = [int(x) for x in inf.readline().split()]
    init()
    #print(bitmask)
    #print(bin(bitmask[N])[2:])
    # print(len(bin(5)), bin(5), bin(5)[2:])

    current = bitmask[N]
    for z in range(J):
        n = generate(current)
        current = n[0]+2
        outf.write(bin(n[0])[2:])
        print_list(n[1])



#print("cast", cast_to(35, 2))
#print("div", get_div(513))

'''

l = [5, 13, 17, 23, 31, 101, 27, 99, 41, 57, 81, 97]
print("tests")
for i in l:
    ans = rabin_miller(i)
    print("%d is %s"%(i, "True" if ans else "False")) '''