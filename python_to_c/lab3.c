#include <stdio.h>
#include <stdlib.h>

// For Python Bindings use: 
// gcc -shared -Wl,-install_name,lab3.so -o lab3.so -fPIC lab3.c
// python3 cPython.py

int multiply(int, int);
int hammingDistance(int, int);

int multiply(int num1, int num2) {
    return num1 * num2;
}

int hammingDistance(int n1, int n2) {
	int x = n1 ^ n2; 
	int setBits = 0; 

	while (x > 0) { 
		setBits += x & 1; 
		x >>= 1; 
	} 

	return setBits; 
}