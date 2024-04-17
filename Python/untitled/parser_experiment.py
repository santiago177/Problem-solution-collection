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
        return "EOL", line_number+1, pos+1
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
    newset = []
    for it in _set:
        newset.append(it if it not in print_token else print_token[it])
    newset = sorted(newset)
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
            format(line, col, token[0], set_to_string(prediction_set))
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


def ARGL():
    token = getNextToken()[0]
    pred1 = ["id"]
    if token in pred1:
        match("id")
        L1()
    else:
        syntax_error(set(pred1))


def ARGS():
    token = getNextToken()[0]
    pred1 = ["token_par_izq"]
    pred2 = ["leer", "para", "definir", "escribir", "segun", "mientras", "si", "finfuncion", "finsubproceso", "finsubalgoritmo", "borrar", "esperar", "repetir", "id", "dimension"]
    if token in pred1:
        match("token_par_izq")
        T2()
    elif token in pred2:
        return
    else:
        syntax_error(set(pred1+pred2))


def ARRAY():
    token = getNextToken()[0]
    pred1 = ["dimension"]
    if token in pred1:
        match("dimension")
        match("id")
        match("token_cor_izq")
        EXPR()
        match("token_cor_der")
        L2()
    else:
        syntax_error(set(pred1))


def ASIG():
    token = getNextToken()[0]
    pred1 = ["token_asig"]
    if token in pred1:
        match("token_asig")
        EXPR()
    else:
        syntax_error(set(pred1))


def ASIGCALL():
    token = getNextToken()[0]
    pred1 = ["id"]
    if token in pred1:
        match("id")
        T4()
    else:
        syntax_error(set(pred1))


def BLOCK():
    token = getNextToken()[0]
    pred1 = ["finproceso", "finsubalgoritmo", "finsi", "finpara", "finalgoritmo", "caso", "de", "hasta", "sino", "finfuncion", "finmientras", "finsubproceso", "finsegun"]
    pred2 = ["leer", "para", "definir", "escribir", "segun", "mientras", "si", "borrar", "esperar", "repetir", "id", "dimension"]
    if token in pred1:
        return
    elif token in pred2:
        STORCOM()
        L5()
    else:
        syntax_error(set(pred1+pred2))


def CALL():
    token = getNextToken()[0]
    pred1 = ["token_par_izq"]
    pred2 = ["token_igual", "token_mayor", "token_mas", "escribir", "token_mayor_igual", "milisegundos", "minutos", "token_y", "mientras", "finfuncion", "finmientras", "finsubproceso", "borrar", "token_pot", "leer", "para", "finalgoritmo", "token_mod""token_o", "definir", "si", "id", "token_dosp", "token_dif", "token_pyc", "finsi", "token_menor", "token_menos", "entonces", "finpara", "token_mul", "finsubalgoritmo", "token_div", "segun", "repetir", "hacer", "finproceso", "sino", "caso", "finsegun", "token_cor_der", "hasta", "de", "token_coma", "token_menor_igual", "segundos", "token_par_der", "esperar", "dimension", "con"]
    if token in pred1:
        match("token_par_izq")
        OPEXPR()
        L3()
        match("token_par_der")
    elif token in pred2:
        return
    else:
        syntax_error(set(pred1+pred2))


def CASEL():
    token = getNextToken()[0]
    pred1 = ["finsegun"]
    pred2 = ["caso"]
    if token in pred1:
        return
    elif token in pred2:
        match("caso")
        EXPR()
        match("token_dosp")
        BLOCK()
        L4()
        DEFAULT()
    else:
        syntax_error(set(pred1+pred2))


def CLS():
    token = getNextToken()[0]
    pred1 = ["borrar"]
    if token in pred1:
        match("borrar")
        match("pantalla")
    else:
        syntax_error(set(pred1))


def COM():
    token = getNextToken()[0]
    pred1 = ["esperar", "leer", "definir", "borrar", "escribir", "dimension", "id"]
    if token in pred1:
        COMID()
        match("token_pyc")
    else:
        syntax_error(set(pred1))


def COMID():
    token = getNextToken()[0]
    pred1 = ["definir"]
    pred2 = ["id"]
    pred3 = ["escribir"]
    pred4 = ["leer"]
    pred5 = ["dimension"]
    pred6 = ["borrar"]
    pred7 = ["esperar"]
    if token in pred1:
        DEF()
    elif token in pred2:
        ASIGCALL()
    elif token in pred3:
        WRITE()
    elif token in pred4:
        READ()
    elif token in pred5:
        ARRAY()
    elif token in pred6:
        CLS()
    elif token in pred7:
        WAIT()
    else:
        syntax_error(set(pred1+pred2+pred3+pred4+pred5+pred6+pred7))


def DEF():
    token = getNextToken()[0]
    pred1 = ["definir"]
    if token in pred1:
        match("definir")
        match("id")
        L1()
        match("como")
        TIPO()
    else:
        syntax_error(set(pred1))


def DEFAULT():
    token = getNextToken()[0]
    pred1 = ["de"]
    pred2 = ["finsegun"]
    if token in pred1:
        match("de")
        match("otro")
        match("modo")
        match("token_dosp")
        BLOCK()
    elif token in pred2:
        return
    else:
        syntax_error(set(pred1+pred2))


def DOWHILE():
    token = getNextToken()[0]
    pred1 = ["repetir"]
    if token in pred1:
        match("repetir")
        BLOCK()
        match("hasta")
        match("que")
        EXPR()
    else:
        syntax_error(set(pred1))


def ELIF():
    token = getNextToken()[0]
    pred1 = ["sino"]
    pred2 = ["finsi"]
    if token in pred1:
        match("sino")
        BLOCK()
    elif token in pred2:
        return
    else:
        syntax_error(set(pred1+pred2))


def ENDPROC():
    token = getNextToken()[0]
    pred1 = ["finproceso"]
    pred2 = ["finalgoritmo"]
    if token in pred1:
        match("finproceso")
    elif token in pred2:
        match("finalgoritmo")
    else:
        syntax_error(set(pred1+pred2))


def ENDSUBPROC():
    token = getNextToken()[0]
    pred1 = ["finsubproceso"]
    pred2 = ["finsubalgoritmo"]
    pred3 = ["finfuncion"]
    if token in pred1:
        match("finsubproceso")
    elif token in pred2:
        match("finsubalgoritmo")
    elif token in pred3:
        match("finfuncion")
    else:
        syntax_error(set(pred1+pred2+pred3))


def EXPR():
    token = getNextToken()[0]
    pred1 = ["token_real", "token_neg", "verdadero", "token_entero", "token_cadena", "id", "falso"]
    pred2 = ["token_par_izq"]
    if token in pred1:
        TOK()
        L6()
    elif token in pred2:
        match("token_par_izq")
        EXPR()
        match("token_par_der")
    else:
        syntax_error(set(pred1+pred2))


def FOR():
    token = getNextToken()[0]
    pred1 = ["para"]
    if token in pred1:
        match("para")
        ASIG()
        match("hasta")
        EXPR()
        STEP()
        match("hacer")
        BLOCK()
        match("finpara")
    else:
        syntax_error(set(pred1))


def IF():
    token = getNextToken()[0]
    pred1 = ["si"]
    if token in pred1:
        match("si")
        EXPR()
        match("entonces")
        BLOCK()
        ELIF()
        match("finsi")
    else:
        syntax_error(set(pred1))


def L1():
    token = getNextToken()[0]
    pred1 = ["token_coma"]
    pred2 = ["token_par_der", "token_pyc", "como"]
    if token in pred1:
        match("token_coma")
        match("id")
        L1()
    elif token in pred2:
        return
    else:
        syntax_error(set(pred1+pred2))


def L2():
    token = getNextToken()[0]
    pred1 = ["token_coma"]
    pred2 = ["token_pyc"]
    if token in pred1:
        match("token_coma")
        match("id")
        match("token_cor_izq")
        EXPR()
        match("token_cor_der")
        L2()
    elif token in pred2:
        return
    else:
        syntax_error(set(pred1+pred2))


def L3():
    token = getNextToken()[0]
    pred1 = ["token_coma"]
    pred2 = ["token_par_der", "token_pyc"]
    if token in pred1:
        match("token_coma")
        EXPR()
        L3()
    elif token in pred2:
        return
    else:
        syntax_error(set(pred1+pred2))


def L4():
    token = getNextToken()[0]
    pred1 = ["caso"]
    pred2 = ["de", "finsegun"]
    if token in pred1:
        match("caso")
        EXPR()
        match("token_dosp")
        BLOCK()
        L4()
    elif token in pred2:
        return
    else:
        syntax_error(set(pred1+pred2))


def L5():
    token = getNextToken()[0]
    pred1 = ["leer", "para", "definir", "escribir", "segun", "mientras", "si", "borrar", "esperar", "repetir", "id", "dimension"]
    pred2 = ["hasta", "finsubalgoritmo", "finsi", "finpara", "finalgoritmo", "caso", "de", "finproceso", "sino", "finfuncion", "finmientras", "finsubproceso", "finsegun"]
    if token in pred1:
        STORCOM()
        L5()
    elif token in pred2:
        return
    else:
        syntax_error(set(pred1+pred2))


def L6():
    token = getNextToken()[0]
    pred1 = ["token_mas", "token_mayor_igual", "token_mod""token_o", "token_dif", "token_menos", "token_pot", "token_y", "token_mul", "token_coma", "token_menor_igual", "token_div", "token_menor", "token_mayor", "token_igual"]
    pred2 = ["minutos", "escribir", "milisegundos", "finproceso", "mientras", "finfuncion", "finmientras", "finsubproceso", "id", "leer", "para", "finalgoritmo", "definir", "hacer", "token_pyc", "finsi", "de", "segun", "finpara", "sino", "finsubalgoritmo", "token_dosp", "entonces", "repetir", "borrar", "caso", "finsegun", "token_cor_der", "hasta", "si", "token_coma", "segundos", "token_par_der", "esperar", "dimension", "con"]
    if token in pred1:
        OP()
        TOK()
        L6()
    elif token in pred2:
        return
    else:
        syntax_error(set(pred1+pred2))


def OP():
    token = getNextToken()[0]
    pred1 = ["token_igual"]
    pred2 = ["token_dif"]
    pred3 = ["token_menor"]
    pred4 = ["token_mayor"]
    pred5 = ["token_menor_igual"]
    pred6 = ["token_mayor_igual"]
    pred7 = ["token_mas"]
    pred8 = ["token_menos"]
    pred9 = ["token_div"]
    pred10 = ["token_mul"]
    pred11 = ["token_mod""token_o"]
    pred12 = ["token_y"]
    pred13 = ["token_coma"]
    pred14 = ["token_pot"]
    if token in pred1:
        match("token_igual")
    elif token in pred2:
        match("token_dif")
    elif token in pred3:
        match("token_menor")
    elif token in pred4:
        match("token_mayor")
    elif token in pred5:
        match("token_menor_igual")
    elif token in pred6:
        match("token_mayor_igual")
    elif token in pred7:
        match("token_mas")
    elif token in pred8:
        match("token_menos")
    elif token in pred9:
        match("token_div")
    elif token in pred10:
        match("token_mul")
    elif token in pred11:
        match("token_mod""token_o")
    elif token in pred12:
        match("token_y")
    elif token in pred13:
        match("token_coma")
    elif token in pred14:
        match("token_pot")
    else:
        syntax_error(set(pred1+pred2+pred3+pred4+pred5+pred6+pred7+pred8+pred9+pred10+pred11+pred12+pred13+pred14))


def OPEXPR():
    token = getNextToken()[0]
    pred1 = ["token_neg", "verdadero", "token_entero", "token_par_izq", "falso", "token_real", "token_cadena", "id"]
    pred2 = ["token_par_der", "token_coma"]
    if token in pred1:
        EXPR()
    elif token in pred2:
        return
    else:
        syntax_error(set(pred1+pred2))


def PROC():
    token = getNextToken()[0]
    pred1 = ["proceso"]
    pred2 = ["algoritmo"]
    if token in pred1:
        match("proceso")
    elif token in pred2:
        match("algoritmo")
    else:
        syntax_error(set(pred1+pred2))


def READ():
    token = getNextToken()[0]
    pred1 = ["leer"]
    if token in pred1:
        match("leer")
        match("id")
        L1()
    else:
        syntax_error(set(pred1))


def RET():
    token = getNextToken()[0]
    pred1 = ["id"]
    if token in pred1:
        match("id")
        T1()
    else:
        syntax_error(set(pred1))


def S():
    token = getNextToken()[0]
    pred1 = ["subproceso", "subalgoritmo", "funcion"]
    pred2 = ["proceso", "algoritmo"]
    if token in pred1:
        SUBPR()
        PROC()
        match("id")
        BLOCK()
        ENDPROC()
    elif token in pred2:
        PROC()
        match("id")
        BLOCK()
        ENDPROC()
    else:
        syntax_error(set(pred1+pred2))


def STATEMENT():
    token = getNextToken()[0]
    pred1 = ["si"]
    pred2 = ["mientras"]
    pred3 = ["repetir"]
    pred4 = ["segun"]
    pred5 = ["para"]
    if token in pred1:
        IF()
    elif token in pred2:
        WHILE()
    elif token in pred3:
        DOWHILE()
    elif token in pred4:
        SWITCH()
    elif token in pred5:
        FOR()
    else:
        syntax_error(set(pred1+pred2+pred3+pred4+pred5))


def STEP():
    token = getNextToken()[0]
    pred1 = ["con"]
    pred2 = ["hacer"]
    if token in pred1:
        match("con")
        match("paso")
        EXPR()
    elif token in pred2:
        return
    else:
        syntax_error(set(pred1+pred2))


def STORCOM():
    token = getNextToken()[0]
    pred1 = ["mientras", "si", "repetir", "para", "segun"]
    pred2 = ["borrar", "esperar", "leer", "definir", "escribir", "id", "dimension"]
    if token in pred1:
        STATEMENT()
    elif token in pred2:
        COM()
    else:
        syntax_error(set(pred1+pred2))


def SUBPR():
    token = getNextToken()[0]
    pred1 = ["subproceso", "subalgoritmo", "funcion"]
    if token in pred1:
        SUBPROC()
        RET()
        ARGS()
        BLOCK()
        ENDSUBPROC()
    else:
        syntax_error(set(pred1))


def SUBPROC():
    token = getNextToken()[0]
    pred1 = ["subproceso"]
    pred2 = ["subalgoritmo"]
    pred3 = ["funcion"]
    if token in pred1:
        match("subproceso")
    elif token in pred2:
        match("subalgoritmo")
    elif token in pred3:
        match("funcion")
    else:
        syntax_error(set(pred1+pred2+pred3))


def SWITCH():
    token = getNextToken()[0]
    pred1 = ["segun"]
    if token in pred1:
        match("segun")
        EXPR()
        match("hacer")
        CASEL()
        match("finsegun")
    else:
        syntax_error(set(pred1))


def T1():
    token = getNextToken()[0]
    pred1 = ["token_asig"]
    pred2 = ["para", "token_par_izq", "segun", "mientras", "finfuncion", "finsubproceso", "finsubalgoritmo", "borrar", "repetir", "id", "leer", "definir", "escribir", "si", "esperar", "dimension"]
    if token in pred1:
        match("token_asig")
        match("id")
    elif token in pred2:
        return
    else:
        syntax_error(set(pred1+pred2))


def T2():
    token = getNextToken()[0]
    pred1 = ["token_par_der"]
    pred2 = ["id"]
    if token in pred1:
        match("token_par_der")
    elif token in pred2:
        ARGL()
        match("token_par_der")
    else:
        syntax_error(set(pred1+pred2))


def T3():
    token = getNextToken()[0]
    pred1 = ["tecla"]
    pred2 = ["token_neg", "verdadero", "token_entero", "token_par_izq", "falso", "token_real", "token_cadena", "id"]
    if token in pred1:
        match("tecla")
    elif token in pred2:
        EXPR()
        TIME()
    else:
        syntax_error(set(pred1+pred2))


def T4():
    token = getNextToken()[0]
    pred1 = ["token_pyc", "token_par_izq"]
    pred2 = ["token_asig"]
    if token in pred1:
        CALL()
    elif token in pred2:
        ASIG()
    else:
        syntax_error(set(pred1+pred2))


def T5():
    token = getNextToken()[0]
    pred1 = ["token_mayor", "token_mas", "escribir", "token_mayor_igual", "milisegundos", "token_par_izq", "con", "token_y", "mientras", "finfuncion", "finmientras", "finsubproceso", "borrar", "token_pot", "leer", "para", "finalgoritmo", "token_mod""token_o", "definir", "si", "id", "token_dosp", "token_dif", "token_pyc", "finsi", "minutos", "token_menos", "entonces", "finpara", "token_mul", "finsubalgoritmo", "token_div", "segun", "repetir", "hacer", "finproceso", "sino", "caso", "finsegun", "token_cor_der", "hasta", "de", "token_coma", "token_menor_igual", "segundos", "token_par_der", "esperar", "token_menor", "dimension", "token_igual"]
    pred2 = ["token_mayor", "token_mas", "escribir", "token_mayor_igual", "milisegundos", "minutos", "con", "token_y", "mientras", "finfuncion", "finmientras", "finsubproceso", "borrar", "token_pot", "leer", "para", "finalgoritmo", "token_mod""token_o", "definir", "si", "id", "token_dosp", "token_menor", "token_pyc", "finsi", "token_dif", "token_menos", "entonces", "finpara", "token_mul", "finsubalgoritmo", "token_div", "segun", "repetir", "hacer", "finproceso", "sino", "caso", "finsegun", "token_cor_der", "hasta", "de", "token_coma", "token_menor_igual", "segundos", "token_par_der", "esperar", "dimension", "token_igual"]
    if token in pred1:
        CALL()
    elif token in pred2:
        return
    else:
        syntax_error(set(pred1+pred2))


def TIME():
    token = getNextToken()[0]
    pred1 = ["minutos"]
    pred2 = ["segundos"]
    pred3 = ["milisegundos"]
    if token in pred1:
        match("minutos")
    elif token in pred2:
        match("segundos")
    elif token in pred3:
        match("milisegundos")
    else:
        syntax_error(set(pred1+pred2+pred3))


def TIPO():
    token = getNextToken()[0]
    pred1 = ["real"]
    pred2 = ["texto"]
    pred3 = ["numerico"]
    pred4 = ["logico"]
    pred5 = ["numero"]
    pred6 = ["cadena"]
    pred7 = ["entero"]
    if token in pred1:
        match("real")
    elif token in pred2:
        match("texto")
    elif token in pred3:
        match("numerico")
    elif token in pred4:
        match("logico")
    elif token in pred5:
        match("numero")
    elif token in pred6:
        match("cadena")
    elif token in pred7:
        match("entero")
    else:
        syntax_error(set(pred1+pred2+pred3+pred4+pred5+pred6+pred7))


def TOK():
    token = getNextToken()[0]
    pred1 = ["token_real"]
    pred2 = ["token_entero"]
    pred3 = ["token_cadena"]
    pred4 = ["id"]
    pred5 = ["verdadero"]
    pred6 = ["falso"]
    pred7 = ["token_neg"]
    if token in pred1:
        match("token_real")
    elif token in pred2:
        match("token_entero")
    elif token in pred3:
        match("token_cadena")
    elif token in pred4:
        match("id")
        T5()
    elif token in pred5:
        match("verdadero")
    elif token in pred6:
        match("falso")
    elif token in pred7:
        UNOP()
        TOK()
    else:
        syntax_error(set(pred1+pred2+pred3+pred4+pred5+pred6+pred7))


def UNOP():
    token = getNextToken()[0]
    pred1 = ["token_neg"]
    if token in pred1:
        match("token_neg")
    else:
        syntax_error(set(pred1))


def WAIT():
    token = getNextToken()[0]
    pred1 = ["esperar"]
    if token in pred1:
        match("esperar")
        T3()
    else:
        syntax_error(set(pred1))


def WHILE():
    token = getNextToken()[0]
    pred1 = ["mientras"]
    if token in pred1:
        match("mientras")
        EXPR()
        match("hacer")
        BLOCK()
        match("finmientras")
    else:
        syntax_error(set(pred1))


def WRITE():
    token = getNextToken()[0]
    pred1 = ["escribir"]
    if token in pred1:
        match("escribir")
        EXPR()
        L3()
    else:
        syntax_error(set(pred1))

#-----------------------------------------------




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
