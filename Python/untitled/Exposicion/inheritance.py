class A:
    def __init__(self):
        pass
    def call(self):
        print "in call A"

class B:
    def __init__(self):
        pass
    def call(self):
        print "in call B"

class C(B, A):
    def __init__(self):
        pass
    pass

example = C()
example.call()