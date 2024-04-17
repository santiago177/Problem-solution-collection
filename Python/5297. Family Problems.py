list = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V', 'W', 'X', 'Y', 'Z']

while True:
    s = raw_input()
    if s == None:
        break
    s = int(s)
    cont = s
    top = 1
    while cont > 1:
        p = 0
        while p <= top:
            p += 1
            cont -= 1
        top += 1
    print list[(top%26)-1]
