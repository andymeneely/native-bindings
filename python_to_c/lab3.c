#include <stdio.h>
#include <stdlib.h>

// For Python Bindings use: 
// gcc -shared -o lab3.so -fPIC lab3.c
// python3 cPython.py

int multiply(int, int);

char[] helloworld() {
	char str[] = "Hello, World!";
	return str;
}

int multiply(int num1, int num2) {
    return num1 * num2;
}
