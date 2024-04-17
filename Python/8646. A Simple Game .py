cases = int(raw_input())

while cases > 0:
    n = int(raw_input())
    flag = True
    while n > 0:
        if n % 2 == 0:
            n /= 2
        else:
            n -= 1
        flag = not flag
    cases -= 1
    if not flag:
        print "Aayush"
    else:
        print"Akash"
