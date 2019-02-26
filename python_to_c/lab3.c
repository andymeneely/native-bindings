#include <stdio.h>
#include <stdlib.h>

// For Python Bindings use: 
// gcc -shared -o lab3.so -fPIC lab3.c
// python3 main.py

int multiply(int, int);

int multiply(int num1, int num2) {
    return num1 * num2;
}
