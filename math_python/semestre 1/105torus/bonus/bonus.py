#!/usr/bin/env python3

from math import *
import math
from operator import *
import sys

debut = 0.5 
debut2 = 0   
fin = 1
max_iter = 200
param = [3,-1,0,6,-5,1,8,0.2]
precision = 10 ** - (param[6])
opt=param[0]
print ('Pour bonus, exemple avec equation de degré 5)')
print ('precision: ', (precision))

def f(x):
    return param[7]*x**5 + param[5]*x**4+param[4]*x**3+param[3]*x**2+param[2]*x+param[1]

def df(x):
    return  5*param[7]*x**4 + 4*param[5]*x**3+3*param[4]*x**2+2*param[3]*x+param[2]

def bisection(debut,fin,precision):
    
    print('\n*Bisection method*')
    print ( 'x = ', str(float(debut)))
    if (f(debut)*f(fin))>0:
        print ('No solution between limits') 
        return
    x0 = debut
    x1 = fin
    for n in range(0,max_iter) :
        x2 = (x0 + x1) / 2
        print ( 'x = ',round(x2,6))
        if f(x0) * f(x2) < 0 :
          x1 = x2
          if abs(f(x1)) < precision :
            return  
        else:
          x0 = x2
    return  None
def newton(debut, fin, precision):
    xn = debut
    if (f(debut)*f(fin))>0:
        print ('No solution between limits') 
        return

    for n in range(0,max_iter):
        fxn = f(xn)
        print ('x= ',round(xn,12))
        #print (("x = %.12f")%(xn))
        if abs(fxn) < precision:
            print('Found solution after',n,'iterations.')
            return xn
        dfxn = df(xn)
        if dfxn == 0:
            print('Zero derivative. No solution found.')
            return None
        xn = xn - fxn/dfxn
    print('Exceeded maximum iterations. No solution found.')
    return None
   

def secant(debut, fin, precision):
    print('\n*Secant method*')
    a_n = debut
    b_n = fin
    print ('x= ',a_n)
    for n in range(0,max_iter):
      
        m_n = a_n - f(a_n)*(b_n - a_n)/(f(b_n) - f(a_n))
        f_m_n = f(m_n)
        pt=round(m_n,8)
        #print (pt)
        print ('x= ',round(m_n,8))
        #print (("x = %.8f")%(m_n))
        if abs(f_m_n)<precision:
            return None
        if f(a_n)*f_m_n < 0:
            a_n = a_n
            b_n = m_n
        elif f(b_n)*f_m_n < 0:
            a_n = m_n
            b_n = b_n
        elif f_m_n == 0:
            print("Found exact solution.")
            return m_n
        else:
            print("Secant method fails.")
            return None
    return a_n - f(a_n)*(b_n - a_n)/(f(b_n) - f(a_n))
    return
#fin des definitions, début du programme principal
# Checking Correctness of initial guess values and bisecting
if f(debut) * f(fin) > 0.0:
    print('Given guess values do not bracket the root.')
else:
    if opt==1:
        bisection(debut,fin,precision)
    elif opt==2:
        newton(debut, fin ,precision)
    elif opt==3:
        secant(debut, fin, precision)
    else:
        print((opt),' is an invalid option')
       

    



