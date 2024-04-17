def parse():
    S()
    print "El analisis sintactico ha finalizado exitosamente."


#input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
#f = sys.stdin
#f = fileinput.input()
#f = codecs.open("input.in", "r", encoding="utf-8")
f = open("input.in")
for line in f:
    lines.append(line)

analex()



#TEST

parse()
