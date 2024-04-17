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
keyWords = ["proceso", "algoritmo", "entero","definir", "real", "mientras", "finsi", "finproceso",
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
        return "EOL" #end of list
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
    print "set", _set
    if isinstance(_set, str):
        return "\""+_set+"\""
    else:
        for it in _set:
            ans += "\""+it+"\", "
        return ans[0:-2]


def syntax_error(prediction_set):
    token = getNextToken()
    print token
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
    l = [str]
    print "l", l
    syntax_error(l)

#-----------------------------------------------

def L2():
    token = getNextToken()[0]
    #pred = ["token_coma","token_pyc"]
    if token == "token_coma":
        match("token_coma")
        match("id")
        match("cor_der")
        EXPR()
        match("cor_izq")
        L2()
    elif token == "token_pyc":
        return
    else:
        syntax_error()

def IF():
    match("si")
    PAREXPR()
    match("entonces")
    BLOCK()
    ELIF()
    match("finsi")

def ELIF():
    token = getNextToken()[0]
    #pred = ["sino","finsi"]
    if token == "sino":
        match("sino")
        BLOCK()
    elif token == "finsi":
        return
    else:
        syntax_error()

def PAREXPR ():
    token = getNextToken()[0]
    #pred = ["(","token_real", "token_entero", "token_cadena", "id"]
    if token == "(":
        match("(")
        EXPR()
        match(")")
    else:
        EXPR()

def FOR():
    match("para")
    ASIG()
    match("hasta")
    EXPR()
    STEP()
    match("hacer")
    BLOCK()
    match("finpara")

def STEP():
    token = getNextToken()[0]
    #pred = ["con","hacer"]
    if token == "con":
        match("con")
        match("paso")
        EXPR()
    elif token == "hacer":
        return
    else:
        syntax_error()

def WHILE():
    match("mientras")
    EXPR()
    match("hacer")
    BLOCK()
    match("finmientras")

def DOWHILE():
    match("repetir")
    BLOCK()
    match("hasta")
    match("que")
    EXPR()

def SWITCH():
    match("segun")
    EXPR()
    match("hacer")
    CASEL()
    match("finsegun")

def CASEL():
    token = getNextToken()[0]
    #pred = ["finsegun","caso"]
    if token == "caso":
        match("caso")
        EXPR()
        match("token_dosp")
        BLOCK()
        L4()
        DEFAULT()
    elif token == "finsegun":
        return
    else:
        syntax_error()

def DEFAULT():
    token = getNextToken()[0]
    #pred = ["de","finsegun"]
    if token == "de":
        match("de")
        match("otro")
        match("modo")
        match("token_dosp")
        BLOCK()
    elif token == "finsegun":
        return
    else:
        syntax_error()

def L4():
    token = getNextToken()[0]
    #pred = ["caso","de","finsegun"]
    if token == "caso":
        match("caso")
        EXPR()
        match("token_dosp")
        BLOCK()
        L4()
    elif token == "de" or token == "finsegun":
        return
    else:
        syntax_error()

def DEF():
    match("definir")
    match("id")
    L1()
    match("como")
    TIPO()

def L1():
    token = getNextToken()[0]
    print "in l1 token", token, tokenlist[tokenindex:]
    #pred = ["token_coma","como","token_pyc",")"]
    if token == "token_coma":
        match("token_coma")
        match("id")
        L1()
    elif token == "como" or token == "token_pyc" or token == "token_par_der":
        return
    else:
        syntax_error()

def ASIG():
    match("token_asig")
    EXPR()

def CLS():
    match("borrar")
    match("pantalla")

def WAIT():
    match("esperar")
    T3()

def T3():
    token = getNextToken()[0]
    #pred = ["tecla","token_real","token_entero","token_cadena","id"]
    if token == "tecla":
        match("tecla")
    else:
        EXPR()
        TIME()

def TIME():
    token = getNextToken()[0]
    #pred = ["minutos","segundos","milisegundos"]
    if token == "minutos":
        match("minutos")
    elif token == "segundos":
        match("segundos")
    elif token == "milisegundos":
        match("milisegundos")
    else:
        syntax_error()


def UNOP():
    pass


def EXPR():
    token = getNextToken()[0]
    print "in expr token", token, tokenlist[tokenindex:]
    pred = ["token_real", "verdadero", "token_entero", "token_cadena", "id", "falso"]
    if token in pred:
        TOK()
        L6()
    elif token == "token_par_izq":
        match("token_par_izq")
        EXPR()
        match("token_par_der")
    else:
        syntax_error()

def L6():
    token = getNextToken()[0]
    print "in l6 token", token, tokenlist[tokenindex:]
    pred = ["minutos", "milisegundos", "finproceso", "mientras", "finmientras", "finsubproceso", "id", "leer", "para", "finsegun", "definir", "hacer", "token_pyc", "finsi", "de", "segun", "finpara", "sino", "token_dosp", "entonces", "repetir", "borrar", "caso", "escribir", "token_cor_der", "hasta", "si", "token_coma", "segundos", "token_par_der", "esperar", "dimension", "con"]
    pred += end_process + end_subprocess
    if token in binary_operator:
        OP()
        TOK()
        L6()
    elif token in pred:
        return
    else:
        syntax_error()


def T5():
    token = getNextToken()[0]
    print "in t5 token", token, tokenlist[tokenindex:]
    pred = ["minutos", "milisegundos", "finproceso", "mientras", "finmientras", "finsubproceso", "id", "leer", "para", "finsegun", "definir", "token_dosp", "token_pyc", "finsi", "de", "segun", "finpara", "sino", "borrar", "entonces", "repetir", "hacer", "operador", "caso", "escribir", "token_cor_der", "hasta", "si", "token_coma", "segundos", "token_par_der", "esperar", "dimension", "con"]
    pred += binary_operator
    print "pred", pred
    if token == "token_par_izq":
        CALL()
    elif token in pred:
        return
    else:
        syntax_error()

def TOK():
    token = getNextToken()[0]
    print "in tok token", token, tokenlist[tokenindex:]
    #pred = ["token_real","token_entero","token_cadena","id"]
    if token == "token_real":
        match("token_real")
    elif token == "token_entero":
        match("token_entero")
    elif token == "token_cadena":
        match("token_cadena")
    elif token == "id":
        match("id")
        T5()
    elif token == "verdadero":
        match("verdadero")
    elif token == "falso":
        match("falso")
    elif token == "token_neg":
        UNOP()
        TOK()
    else:
        syntax_error()

def OP():
    match(binary_operator)

def TIPO():
    token = getNextToken()[0]
    print "in tipo token", token, tokenlist[tokenindex:]
    #pred = ["real","texto","numerico"]
    if token == "real":
        match("real")
    elif token == "texto":
        match("texto")
    elif token == "numerico":
        match("numerico")
    elif token == "logico":
        match("logico")
    else:
        syntax_error()

#-----------------------------------------------

def T1():
    token = getNextToken()[0]
    pred = ["leer", "para", "token_par_izq", "definir", "escribir", "segun", "mientras", "si", "finsubproceso", "borrar", "esperar", "repetir", "id", "dimension"]
    if token == "token_asig":
        match("token_asig")
        match("id")
    elif token in pred:
        return
    else:
        syntax_error(set(pred + ["token_asig"]))


def RET():
    token = getNextToken()[0]
    print "in ret token", token, tokenlist[tokenindex:]
    if token == "id":
        match("id")
        T1()
    else:
        syntax_error(["id"])


def T2():
    token = getNextToken()[0]
    print "in t2 token", token, tokenlist[tokenindex:]
    pred = ["token_par_der", "id"]
    if token == "token_par_der":
        match("token_par_der")
    elif token == "id":
        ARGL()
        match("token_par_der")
    else:
        syntax_error(pred)

def ARGL():
    token = getNextToken()[0]
    print "in argl token", token, tokenlist[tokenindex:]
    if token == "id":
        match("id")
        L1()
    else:
        syntax_error(["id"])

def ARGS():
    token = getNextToken()[0]
    print "in args token", token, tokenlist[tokenindex:]
    pred = ["leer", "para", "definir", "escribir", "segun", "mientras", "si", "finsubproceso", "borrar", "esperar", "repetir", "id", "dimension"]
    if token == "token_par_izq":
        match("token_par_izq")
        T2()
    elif token in pred:
        return
    else:
        syntax_error(set(pred+["token_par_izq"]))


def SUBPR():
    token = getNextToken()[0]
    print "in subpr token", token, tokenlist[tokenindex:]
    if token in subprocess:
        match(subprocess)
        RET()
        ARGS()
        BLOCK()
        match(end_subprocess)
    else:
        syntax_error(subprocess)



def STATEMENT():
    token = getNextToken()[0]
    if token == "si":
        IF()
    elif token == "mientras":
        WHILE()
    elif token == "segun":
        SWITCH()
    elif token == "repetir":
        DOWHILE()
    elif token == "para":
        FOR()
    else:
        syntax_error(["si", "mientras", "segun", "repetir", "para"])


def CALL():
    token = getNextToken()[0]
    if token == "token_par_izq":
        match("token_par_izq")
        EXPR()
        L3()
        match("token_par_der")
    else:
        syntax_error(["token_par_izq"])


def T4():
    token = getNextToken()[0]
    if token == "token_par_izq":
        CALL()
    elif token == "token_asig":
        ASIG()
    else:
        syntax_error(["token_par_izq", "token_asig"])


def ASIGCALL():
    token = getNextToken()[0]
    pred = ["id"]
    if token == "id":
        match("id")
        T4()
    else:
        syntax_error(set(pred))


def L3():
    token = getNextToken()[0]
    pred = ["token_coma", "token_pyc", "token_par_der"]
    if token == "token_coma":
        match("token_coma")
        EXPR()
        L3()
    elif token == "token_pyc" or token == "token_par_der":
        return
    else:
        syntax_error(set(pred))


def WRITE():
    token = getNextToken()[0]
    print "in write token", token, tokenlist[tokenindex:]
    pred = ["escribir"]
    if token == "escribir":
        match("escribir")
        EXPR()
        L3()
    else:
        syntax_error(set(pred))


def READ():
    token = getNextToken()[0]
    pred = ["leer"]
    if token == "leer":
        match("leer")
        match("id")
        L1()
    else:
        syntax_error(set(pred))


def ARRAY():
    token = getNextToken()[0]
    pred = ["dimension"]
    if token == "dimension":
        match("dimension")
        match("id")
        match("token_cor_izq")
        EXPR()
        match("token_cor_der")
        L2()
    else:
        syntax_error(set(pred))


def COMID():
    token = getNextToken()[0]
    pred = ["definir", "id", "escribir", "leer", "dimension", "borrar", "esperar"]
    if token == "definir":
        DEF()
    elif token == "id":
        ASIGCALL()
    elif token == "escribir":
        WRITE()
    elif token == "leer":
        READ()
    elif token == "dimension":
        ARRAY()
    elif token == "borrar":
        CLS()
    elif token == "esperar":
        WAIT()
    else:
        syntax_error(set(pred))



def COM():
    token = getNextToken()[0]
    print "in com token", token, tokenlist[tokenindex:]
    pred = ["esperar", "leer", "definir", "borrar", "escribir", "dimension", "id"]
    if token in pred:
        COMID()
        match("token_pyc")
    else:
        syntax_error(set(pred))

def STORCOM():
    token = getNextToken()[0]
    print "in storcom token", token, tokenlist[tokenindex:]
    pred1 = ["mientras", "si", "repetir", "para", "segun"]
    pred2 = ["borrar", "esperar", "leer", "definir", "escribir", "id", "dimension"]
    fullpred = set(pred1) | set(pred2)
    if token in pred1:
        STATEMENT()
    elif token in pred2:
        COM()
    else:
        syntax_error(fullpred)


def L5():
    token = getNextToken()[0]
    print "in l5 token", token, tokenlist[tokenindex:]
    pred1 = ["leer", "para", "definir", "escribir", "segun", "mientras", "si", "borrar", "esperar", "repetir", "id", "dimension"]
    pred2 = ["hasta", "finpara", "finsi", "finsegun", "caso", "de", "finproceso", "sino", "finmientras", "finsubproceso"]
    pred2 += end_process + end_subprocess
    fullpred = set(pred1) | set(pred2)
    if token in pred1:
        STORCOM()
        L5()
    elif token in pred2:
        return
    else:
        syntax_error(fullpred)

def BLOCK():
    token = getNextToken()[0]
    print "in block token", token, tokenlist[tokenindex:]
    pred1 = ["finproceso", "finpara", "finsi", "finsegun", "caso", "de", "hasta", "sino", "finmientras", "finsubproceso"]
    pred2 = ["leer", "para", "definir", "escribir", "segun", "mientras", "si", "borrar", "esperar", "repetir", "id", "dimension"]
    intersection = list(set(pred1) & set(pred2))
    fullpred = set(pred1) | set(pred2)
    print "intersection", intersection
    if token in pred1:
        return
    elif token in pred2:
        STORCOM()
        L5()
    else:
        syntax_error(fullpred)

def S():
    token = getNextToken()[0]
    fullpred = set(subprocess) | set(process)
    print "in s token", token
    if token in subprocess:
        SUBPR()
        match(process)
        match("id")
        BLOCK()
        match(end_process)
    elif token in process:
        match(process)
        match("id")
        BLOCK()
        match(end_process)
    else:
        syntax_error(fullpred)



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
for it in tokenlist:
    print it


print isinstance("strs", list)

parse()
