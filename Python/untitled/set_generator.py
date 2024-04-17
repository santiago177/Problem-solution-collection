non_terminals = set()
non_terminal_rules = {}
rules = []
first_set = {}
follow_set = {}
prediction_set = []
prediction_set_for = {}
epsilon = "EPSILON"
end = "$"


def first_set_for(non_terminal):
    fset = set()
    rules = non_terminal_rules[non_terminal]
    pending = []
    for rule in rules:
        for i in range(0, len(rule)): # iterando elementos de la regla
            element = rule[i]
            if element == non_terminal:
                pending.append(rule)
                break
            if element in non_terminals: # si es un no terminal
                if element not in first_set:
                    first_set_for(element)
                this_set = set(first_set[element])
                if epsilon in this_set:
                    if i == len(rule)-1:
                        fset.add(epsilon)
                    this_set.remove(epsilon)
                    fset |= this_set
                    continue
                else:
                    fset |= this_set
                    break
            else:
                fset.add(element)
                break
    for rule in pending:
        for i in range(0, len(rule)):
            element = rule[i]
            if element == non_terminal:
                if epsilon not in fset:
                    break
            else:
                if element in non_terminals:
                    this_set = set(first_set[element])
                    if epsilon in this_set:
                        if i == len(rule) - 1:
                            fset.add(epsilon)
                        this_set.remove(epsilon)
                        fset |= this_set
                        continue
                    else:
                        fset |= this_set
                        break
                else:
                    fset.add(element)
                    break
    first_set[non_terminal] = fset

def first_set_for_rule(rule):
    fset = set()
    last = True
    for i in range(0, len(rule)):
        item = rule[i]
        if item not in non_terminals:
            fset.add(item)
            last = False
            break
        else:
            copy = set(first_set[item])
            if epsilon in copy:
                if i == len(rule)-1:
                    fset.add(epsilon)
                copy.remove(epsilon)
            fset |= copy
            if epsilon not in first_set[item]:
                last = False
                break
    if not rule:
        fset.add(epsilon)
    return fset



def all_first_sets():
    for nt in non_terminals:
        if nt not in first_set:
            first_set_for(nt)


def init_follow_set():
    for nt in non_terminals:
        follow_set[nt] = set()


def all_follow_sets():
    init_follow_set()
    something_added = True
    follow_set["S"].add(end)
    while something_added:
        something_added = False
        for nt in non_terminals:
            follow_A = follow_set[nt]
            for rule in rules:
                follow_B = follow_set[rule[0]]
                if nt in rule[1]:
                    pos = rule[1].index(nt)+1
                    subrule = rule[1][pos:]
                    firstof = first_set_for_rule(subrule)
                    #print "nt {} left side {}".format(nt, rule[0]), firstof, subrule
                    for item in firstof:
                        if item != epsilon and item not in follow_A:
                            something_added = True
                            follow_A.add(item)
                    if epsilon in firstof:
                        for item in follow_B:
                            if item not in follow_A:
                                something_added = True
                                follow_A.add(item)


def all_prediction_sets():
    for rule in rules:
        fset = first_set_for_rule(rule[1])
        print "fset", fset, "left side", rule[0]
        if epsilon in fset:
            fset.remove(epsilon)
            prediction_set.append(fset | follow_set[rule[0]])
        else:
            prediction_set.append(fset)
    for i in range(0, len(rules)):
        nt = rules[i][0]
        if nt not in prediction_set_for:
            prediction_set_for[nt] = set()
        for elem in prediction_set[i]:
            prediction_set_for[nt].add(elem)


def rule_tostr(rule):
    ans = ""
    for it in rule:
        ans += it + " "
    return ans.strip()


def set_tostr(iset):
    ans = ""
    for it in iset:
        ans += it+", "
    return ans[:-2]


def print_prediction_sets():
    fout = open("prediction_sets.out", "w")
    for i in range(0, len(rules)):
        rule = rules[i]
        rulestr = rule_tostr(rule[1])
        length = len(rule[0]) + len(rulestr)
        fill = " "*(60-length)
        print >>fout, "{} -> {};{}{}".format(rule[0], rulestr, fill, set_tostr(prediction_set[i]))
        print "{} -> {}{}{}".format(rule[0], rulestr, fill, set_tostr(prediction_set[i]))

f = open("grammar.in")

for line in f:
    sides = line.split("->")
    if sides[0] != "\n":
        l = sides[0].strip()
        r = sides[1].strip().split("|")
        for rule in r :
            temp = rule.split()
            non_terminals.add(l)
            if l not in non_terminal_rules:
                non_terminal_rules[l] = []
            non_terminal_rules[l].append(temp)
            rules.append((l, temp))
            #print "add", l, temp

all_first_sets()
all_follow_sets()

print "first set"

for k, v in first_set.iteritems():
    print k, v

print "\n\n\nfollow set\n"

for k, v in follow_set.iteritems():
    print k, v
all_prediction_sets()


print "\n\n\nprediction sets\n"
print_prediction_sets()

print prediction_set_for