s = raw_input()
n = int(raw_input())
for z in range(0 , n):
    a, b = int(raw_input()), int(raw_input())
    cont = 0
    lb = a-1;
    ub = b-1;
    while lb < ub:
        if s[lb] == s[lb+1]:
            cont += 1;
        lb += 1
    print cont
        
