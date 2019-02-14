from ctypes import *

#load the shared object file
c_lib = CDLL('./lab3.so')

#Find sum of integers
def multiply(x, y):
    return c_lib.multiply(x, y)

def hammingDist(num1, num2):
    return c_lib.hammingDistance(num1, num2)