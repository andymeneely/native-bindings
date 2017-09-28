from libc.stdio cimport printf

cdef void c_say_hello():
    cdef char *str = "Hello, World!";
    printf("%s\n", str);

def say_hello():
    c_say_hello();

cdef int c_multiply(int py_x, int py_y):
    cdef int x = py_x;
    cdef int y = py_y;

    cdef product = x * y;

    return product;

def multiply(py_x, py_y):
    return c_multiply(py_x, py_y);