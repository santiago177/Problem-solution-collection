import sys
import codecs
from string import ascii_letters

lines = []
words = []
word_len_sum = []
word_cnt = 0
current_line = ""
line_number = 0
pos = 0
keyWords = ["proceso", "algoritmo", "entero","definir", "real", "mientras", "finsi", "finproceso",
                "como", "caracter", "si", "entonces", "sino", "para", "paso", "hacer", "finpara",
                "finmientras", "subproceso", "repetir", "escribir", "leer", "dimension", "borrar", "pantalla",
                "limpiar", "esperar", "tecla", "segundos", "milisegundos", "segun",
                "de", "otro", "modo", "finsegun", "funcion", "subalgoritmo", "finsubproceso","hasta","que",
                "finsubalgoritmo", "finfuncion", "logico", "verdadero", "falso", "numerico", "numero",
                "finalgoritmo","texto","cadena","con"]

token = {"~": "neg", "=": "igual", "<-": "asig", "<>": "dif", "<": "menor", ">": "mayor", "<=": "menor_igual",
         ">=": "mayor_igual", "+": "mas", "-": "menos", "/": "div", "*": "mul", "%": "mod", ";": "pyc", ": ": "dosp",
         "(": "par_izq", ")": "par_der", "[": "cor_izq", "]": "cor_der", "|": "o", "&": "y", ",": "coma", "^": "pot",
         "y": "y", "o": "o", "no": "neg", "mod": "mod"}

ambig = ["y", "o", "no", "mod"]

stop = [" ", "\t", "\n", "\r"]

space_cnt = []
error_flag = False


def valid_char(c):
    return c in ascii_letters or c.isnumeric() or c == "_"


def my_print(args, col=0, row=0, str=False):
    if not str:
        args = args.lower()
    m_col = 0 if col > 0 else 1
    m_row = 0 if row > 0 else 1
    print("<{},{:d},{:d}>".format(args, (((line_number + 1) * m_row) + row), ((pos + 1) * m_col) + col))


def quotation_test(c):
    return c == '"' or c == "'"


def error(col=0, row=0):
    m_col = 0 if col > 0 else 1
    m_row = 0 if row > 0 else 1
    global error_flag
    error_flag = True
    print(">>> Error lexico(linea: {:d}, posicion: {:d})".format((((line_number + 1)*m_row)+row), ((pos + 1)*m_col + col)))


def str_test():
    global pos, line_number
    start_col = pos+1
    start_line = line_number+1
    content = ""
    pos += 1
    flag = True
    while flag:
        c = get_char()
        if c is None:
            error(col=start_col, row=start_line)
            break
        if c == "\n":
            content += c
            line_number += 1
            pos = 0
            continue
        if quotation_test(c):
            my_print("token_cadena,{}".format(content), str=True, col=start_col, row=start_line)
            flag = False
        pos += 1
        content += c


def num_print(content, point, col=0):
    if content[-1] == ".":
        error()
    else:
        if point:
            my_print("token_real,{}".format(content), col=col)
        else:
            my_print("token_entero,{}".format(content), col=col)


def num_test():
    global pos, line_number
    content = ""
    point = False
    start_col = pos+1
    while True:
        c = get_char()
        if c is None or quotation_test(c) or (c in token and c not in ambig) or c in stop:
            num_print(content, point, col=start_col)
            break
        if c == ".":
            if point:
                error(col=start_col)
                break
            else:
                point = True
                content += c
        elif c.isnumeric():
            content += c
        else:
            error(col=start_col)
            break
        pos += 1


def alpha_print(content, col=0):
    content = content.lower()
    if content in keyWords:
        my_print(content, col=col)
    elif content in token:
        my_print("token_{}".format(token[content]), col=col)
    else:
        my_print("id,{}".format(content), col=col)


def alpha_test():
    global pos
    content = ""
    start_col = pos+1
    while True:
        c = get_char()
        if c is None or quotation_test(c) or (c in token and c not in ambig) or c in stop:
            alpha_print(content, col=start_col)
            break
        if valid_char(c):
            content += c
        else:
            error()
            break
        pos += 1


def composite_test(c):
    less_than_follow = ["-", ">", "="]
    if c[0] == "<":
        if c[1] in less_than_follow:
            my_print("token_{}".format(token[c]))
            return True
    else:
        if c[1] == "=":
            my_print("token_{}".format(token[c]))
            return True
    return False


def get_char():
    global pos
    global line_number, current_line
    if line_number >= len(lines):
        return None
    if current_line != lines[line_number]:
        current_line = lines[line_number]
    if pos >= len(current_line):
        return "\n"
    return current_line[pos]


def token_proc(w, start):
    global pos, line_number
    composite = False
    inc = 1
    if pos + 1 < len(w) and w[pos + 1] == "/" and w[pos] == "/":
        line_number += 1
        pos = 0
        return inc, start, True
    if pos + 1 < len(w) and (w[pos] == "<" or w[pos] == ">"):
        composite = composite_test(w[pos] + w[pos + 1])
        if composite:
            inc = 2
    if not composite:
        my_print("token_{}".format(token[w[pos]]), col=pos + 1)
        start = pos + 2
    else:
        start = pos + 3
    return inc, start, False


def analex():
    global line_number, pos, current_line
    line_number = 0
    pos = 0
    current_line = lines[0]
    start = 1
    # w = words[word_cnt]
    flag = True
    while flag:
        inc = 1
        if error_flag:
            return
        #print("pos {:d} line {:d}".format(pos, line_number))
        c = get_char()
        #print(c, pos)
        w = current_line
        if c == "\r":
            pos += inc
            continue
        if c is None:
            break
        # print("c is "+c)
        if c == "\n":
            line_number += 1
            pos = 0
            start = 1
            continue
        elif c in token and c not in ambig:
            tup = token_proc(w, start)
            inc = tup[0]
            start = tup[1]
            if tup[2]:
                continue
            pos += inc
        elif quotation_test(c):
            str_test()
            continue
        elif c.isnumeric():
            num_test()
        elif c.isalpha():
            alpha_test()
        elif c == " " or c == "\t":
            #print("c is "+c)
            pos += inc
        else:
            error(col=pos+1)
            return
    return False


def comment():
    w = words[word_cnt]
    if len(w) > 1 and w[0] == "/" and w[1] == "/":
        return True
    else:
        return False

# f = sys.stdin
f = codecs.open("input.in", "r", encoding="utf-8")
#f = open("input.in")
for line in f:
    lines.append(line)

analex()
