def factorial(n):
    if n == 1 or n == 0:
        return 1
    else:
        return n * factorial(n-1)

n = input()
n = int(n)

while(n > 0):
    a = int(input())
    print factorial(a)
    n -= 1
