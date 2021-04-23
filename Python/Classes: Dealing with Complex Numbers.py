import math

class Complex(object):
    def __init__(self, real, imaginary=0):
        self.t = complex(real , imaginary)

    def __add__(self, no):
        temp = complex.__add__(self.t,no.t)
        return Complex(temp.real, temp.imag)

    def __sub__(self, no):
        temp = complex.__sub__(self.t,no.t)
        return Complex(temp.real, temp.imag)

    def __mul__(self, no):
        temp = complex.__mul__(self.t,no.t)
        return Complex(temp.real, temp.imag)

    def __truediv__(self, no):
        temp = complex.__truediv__(self.t,no.t)
        return Complex(temp.real, temp.imag)

    def mod(self):
        temp = complex.__abs__(self.t)
        return Complex(temp.real, temp.imag)

    def __str__(self):
        if self.t.imag== 0:
            result = "%.2f+0.00i" % (self.t.real)
        elif self.t.real == 0:
            if self.t.imag>= 0:
                result = "0.00+%.2fi" % (self.t.imag)
            else:
                result = "0.00-%.2fi" % (abs(self.t.imag))
        elif self.t.imag> 0:
            result = "%.2f+%.2fi" % (self.t.real, self.t.imag)
        else:
            result = "%.2f-%.2fi" % (self.t.real, abs(self.t.imag))
        return result


if __name__ == '__main__':
    c = map(float, input().split())
    d = map(float, input().split())
    x = Complex(*c)
    y = Complex(*d)
    print(*map(str, [x+y, x-y, x*y, x/y, x.mod(), y.mod()]), sep='\n')
