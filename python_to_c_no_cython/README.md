# Binding C to Python without Cython

This method follows the turorial on [this page](https://docs.python.org/3/extending/extending.html) to create a Python module that can be imported in Python. The build produces a .so file that can be installed in a python install (therefore it might not work on Nitron, sorry :/)

## Dependencies

Python 3

```
$ sudo apt install python3
```

Make

```
$ sudo apt install make
```

Python3 Development pacakge

```
$ sudo apt install python3-dev
```

## Running

To run this example, simply run. 

```
$ make
$ sudo make install
$ python3 run.py
```

For details about the build process, check out these docs:

* [Building on Linux](https://docs.python.org/3/extending/building.html#building)
* [Building on Windows](https://docs.python.org/3/extending/windows.html#building-on-windows)

## Implementation Details

`cModule.c` has comments explaining every step to write a function in C, and define a module that can be compiled for Python.

`setup.py` contains the code to compile the module.

`run.py` demonstrates how to use the module.

