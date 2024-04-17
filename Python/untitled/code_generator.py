import collections
non_terminals = set()
rules = {}
tab = "    "


def prediction_string(pred):
    ans = ""
    for elem in pred:
        ans += "\"{}\", ".format(elem)
    return ans[0:-2]

def generate_code():
    fout = open("generated_parser.py", "w")
    f1 = open("start.py")
    f2 = open("end.py")
    for line in f1:
        print >>fout, line[:-1]
    print >>fout
    print >> fout
    for k, v in rules.iteritems():
        print >>fout, "def {}():".format(k)
        print >>fout, "{}token = getNextToken()[0]".format(tab)
        cnt = 1
        for rule in v:
            pred = prediction_string(rule[1])
            print >>fout, "{}pred{:d} = [{}]".format(tab, cnt, pred)
            cnt += 1
        cnt = 1
        first = True
        param = ""
        if k == "PROC":
            param = ", True"
        for rule in v:
            type = "if" if first else "elif"
            print >> fout, "{}{} token in pred{:d}:".format(tab, type, cnt)
            first = False
            for elem in rule[0]:
                if elem in non_terminals:
                    print >> fout, "{}{}()".format(tab*2, elem)
                elif elem == "EPSILON":
                    print >> fout, "{}return".format(tab * 2)
                else:
                    print >> fout, "{}match(\"{}\")".format(tab * 2, elem)
            cnt += 1
        sets = ""
        for i in range(1, cnt):
            sets += "pred{:d}+".format(i)
        print >> fout, "{}else:\n{}syntax_error(set({}){})".format(tab, tab*2, sets[:-1], param)
        print >>fout
        print >> fout
    for line in f2:
        print >>fout, line[:-1]



f = open("prediction_sets.out")

for line in f:
    sides = map(str.strip,line.split("->"))
    nt = sides[0]
    non_terminals.add(nt)
    if nt not in rules:
        rules[nt] = []
    split1 = map(str.strip, sides[1].split(";"))
    rule = map(str.strip, split1[0].split(" "))
    prediction_set = map(str.strip, split1[1].split(","))
    rules[nt].append((rule, prediction_set))

rules = collections.OrderedDict(sorted(rules.items()))
generate_code()