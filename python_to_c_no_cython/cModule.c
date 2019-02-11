// on linux run 
// sudo apt install python3-dev 
// to get Python.h
#include <Python.h>

// All functions take this signature
PyObject * power (PyObject *self, PyObject *args) {
    int a, b; // Declare any variables you want to take as input parameters

    // PyArg_ParseTuple takes your args(which is a tuple) and splits it into
    // your input parameters. The second parameter is the types, in this case
    // i means int, so ii means two integers. Everything after the colon is used
    // when reporting any exceptions. An additional parameters are the addresses
    // where you want your parameters stored
    if (!PyArg_ParseTuple(args, "ii:power", &a, &b))
        // Returing NULL reports an exception has ocurred
        return NULL;

    // Code your function
    int result = 1;
    if (b > 0) {
        int i;
        for (i = 0; i < b; i++) {
            result = result * a;
        }
    }
    
    // Convert your answer into a PyObject
    return PyLong_FromLong(result);    
}

// Define the method table. This is an array of structs with the format
// - String method name in python
// - function pointer to c function
// - METH_VARARGS to specify how the args is passed into the function
// - String holding documentation for IDEs
// The last element in the array MUST be {NULL, NULL, 0, NULL}
static PyMethodDef PythonToCMethods[] = {
    { "power", power, METH_VARARGS, "Raise a to the power b" },
    { NULL, NULL, 0, NULL}
};

// Define the module definition structure
// The first element of the struct is necessary for standalone modules
// The second is the module name
// The third is for module documentation. I use NULL since I don't have any docs
// The fourth holds the module state. -1 if the state is kept in global variables
// The last is a reference to the method table from above
static struct PyModuleDef pythonToCExampleModule = {
    PyModuleDef_HEAD_INIT,
    "pythonToCExample",
    NULL,
    -1,
    PythonToCMethods
};

// This function is called when the module is initialized. The function name
// MUST be PyInit_<<module name>>(void)
PyMODINIT_FUNC
PyInit_pythonToCExample(void) {
    return PyModule_Create(&pythonToCExampleModule);
}

