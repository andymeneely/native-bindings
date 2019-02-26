from ctypes import *

#load the shared object file
c_lib = CDLL('./lab3.so')

#Find sum of integers
print(c_lib.multiply(4, 5))
