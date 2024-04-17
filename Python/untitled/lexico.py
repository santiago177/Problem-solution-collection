import sys

#diccionario de operadores y simbolos especiales
token = {"~":"neg","=":"igual","<-":"asig", "<>":"dif", "<":"menor", ">":"mayor", "<=":"menor_igual",
         ">=":"mayor_igual", "+":"mas", "-":"menos", "/":"div", "*":"mul", "%":"mod",";":"pyc",":":"dosp",
         "(":"par_izq",")":"par_der","[":"cor_izq","]":"cor_der","|":"o","&":"y",",":"coma","^":"pot"}

number_row = 1
number_column = 1
line=sys.stdin.readline().strip()
while line != "":
    line = line+" "
    while number_column <= len(line)-1:
        cad = str(line[number_column-1])+str(line[number_column])
        if cad in token.keys():
            print ("<token_"+token[cad]+","+str(number_row)+","+str(number_column)+">")
            number_column+=2
        else:
            if str(line[number_column-1]) in token.keys():
                print ("<token_"+token[str(line[number_column-1])]+","+str(number_row)+","+str(number_column)+">")
                number_column+=1
            else:
                if str(line[number_column-1]) == " ":
                    number_column+=1
                else:
                    break
    number_column=1
    number_row+=1
    line=sys.stdin.readline()
