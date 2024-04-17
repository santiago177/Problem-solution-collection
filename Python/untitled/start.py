# -*- coding: utf-8 -*-
import sys
import codecs
import fileinput
import io
from string import ascii_letters


lines = []
words = []
word_len_sum = []
word_cnt = 0
current_line = ""
line_number = 0
pos = 0
keyWords = ["proceso", "caso", "algoritmo", "entero","definir", "real", "mientras", "finsi", "finproceso",
                "como", "caracter", "si", "entonces", "sino", "para", "paso", "hacer", "finpara",
                "finmientras", "subproceso", "repetir", "escribir", "leer", "dimension", "borrar", "pantalla",
                "limpiar", "esperar", "tecla", "segundos", "milisegundos", "segun",
                "de", "otro", "modo", "finsegun", "funcion", "subalgoritmo", "finsubproceso","hasta","que",
                "finsubalgoritmo", "finfuncion", "logico", "verdadero", "falso", "numerico", "numero",
                "finalgoritmo","texto","cadena","con"]

token = {"~": "neg", "=": "igual", "<-": "asig", "<>": "dif", "<": "menor", ">": "mayor", "<=": "menor_igual",
         ">=": "mayor_igual", "+": "mas", "-": "menos", "/": "div", "*": "mul", "%": "mod", ";": "pyc", ":": "dosp",
         "(": "par_izq", ")": "par_der", "[": "cor_izq", "]": "cor_der", "|": "o", "&": "y", ",": "coma", "^": "pot",
         "y": "y", "o": "o", "no": "neg", "mod": "mod"}

print_token = { "id" : "identificador", "token_asig" : "<-",  "token_cadena" : "valor_cadena", "token_coma" : "," ,  "token_cor_der" : "]", "token_cor_izq" : "[" ,  "token_dif" : "<>", "token_div" : "/",
 "token_dosp" : ":", "token_entero" : "valor_entero", "token_igual" : "=", "token_mas" : "+", "token_mayor" : ">", "token_mayor_igual" : ">=", "token_menor" : "<",  "token_menor_igual" : "<=", "token_menos" : "-", "token_mod" : "%", "token_mul" : "*", "token_neg" : "~", "token_o" : "|", "token_par_der" : ")", "token_par_izq" : "(", "token_pot" : "^", "token_pyc" : ";", "token_real" : "valor_real", "token_y": "&"}




process = ["proceso", "algoritmo"]
end_process = ["finproceso", "finalgoritmo"]
subprocess = ["subproceso", "funcion", "subalgoritmo"]
end_subprocess = ["finsubproceso", "finfuncion", "finsubalgoritmo"]

binary_operator = ["token_igual","token_dif","token_menor","token_mayor","token_menor_igual","token_mayor_igual","token_mas","token_menos","token_div","token_mul","token_mod""token_o","token_y","token_coma","token_pot"]

ambig = ["y", "o", "no", "mod"]

stop = [" ", "\t", "\n", "\r"]

space_cnt = []
error_flag = False

tokenlist = []
tokenindex = 0

def getNextToken():
    global tokenindex
    if tokenindex >= len(tokenlist):
        return "EOF", line_number+1, pos+1
    else:
        return tokenlist[tokenindex]

def valid_char(c):
    return c in ascii_letters or c.isdigit() or c == "_"


def my_print(args, col=0, row=0, str=False):
    if not str:
        args = args.lower()
    m_col = 0 if col > 0 else 1
    m_row = 0 if row > 0 else 1
    if args.__contains__(","):
        tokenlist.append( (args.split(",")[0],args.split(",")[1],(((line_number + 1) * m_row) + row),((pos + 1) * m_col) + col) )
    else:
        tokenlist.append( (args,(((line_number + 1) * m_row) + row),((pos + 1) * m_col) + col) )
    #print("<{},{:d},{:d}>".format(args, (((line_number + 1) * m_row) + row), ((pos + 1) * m_col) + col))


def quotation_test(c):
    return c == '"' or c == "'"


def error(col=0, row=0):
    m_col = 0 if col > 0 else 1
    m_row = 0 if row > 0 else 1
    global error_flag
    error_flag = True
    print(">>> Error lexico (linea: {:d}, posicion: {:d})".format((((line_number + 1)*m_row)+row), ((pos + 1)*m_col + col)))


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
            my_print("token_cadena,{}".format(content.encode("utf-8")), str=True, col=start_col, row=start_line)
            flag = False
        pos += 1
        content += c


def num_print(content, point, col=0):
    if content[-1] == ".":
        my_print("token_entero,{}".format(content[0:-1]), col=col)
        error(col=pos)
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
                num_print(content, point, col=start_col)
                error(col=start_col)
                break
            else:
                point = True
                content += c
        elif c.isdigit():
            content += c
        else:
            num_print(content, point, col=start_col)
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
            alpha_print(content, col=start_col)
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
        elif c.isdigit():
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


def set_to_string(_set):
    ans = ""
    _set = sorted(_set)
    newset = []
    for it in _set:
        newset.append(it if it not in print_token else print_token[it])
    for it in newset:
        ans += "\"{}\", ".format(it)
    return ans[0:-2]


def syntax_error(prediction_set, special=False):
    if special:
        if "proceso" in prediction_set:
            print "Error sintactico: falta proceso"
    else:
        token = getNextToken()
        line = 0
        col = 0
        val = token[0]
        if len(token) > 3:
            line = token[2]
            col = token[3]
        else:
            line = token[1]
            col = token[2]
        print "<{:d},{:d}> Error sintactico: se encontro: \"{}\"; se esperaba: {}.".\
            format(line, col, token[0] if token[0] not in print_token else print_token[token[0]], set_to_string(prediction_set))
    sys.exit()


def match(str):
    global tokenindex
    temp = getNextToken()[0]
    if isinstance(str, list):
        if temp in str:
            tokenindex += 1
            return
    else:
        if temp == str:
            tokenindex += 1
            return
    syntax_error(set([str]))

#-----------------------------------------------
