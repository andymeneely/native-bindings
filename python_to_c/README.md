# Build & Run

Cython takes python-like code and compiles it to C code. It does this using a special syntax. Inside `hello.pyx` you will see some functions and variables declared with the `cdef` keyword; `cdef` tells Cython that these functions and variables are C functions and variables, not python ones. Cython is powerful because it lets you take an existing python function and, with a few minor tweaks, compile it to C.

To build the C code, run `python3 setup.py build_ext --inplace`. That's it! If you didn't get any error messages, you can now run `python3 main.py` and see the expected output!

# Notes

* `hello.pyx` contains functions written in python, but modified to use the `cdef` keyword.
* `setup.py` runs a few commands to tell Cython to compile your C code. It will install Cython for you if you don't have it installed already. You will need `sudo` for this.
* `hello.c` is one of the files that gets created when you run `setup.py`. It contains all of the C code that you would have had to write in order to do what Cython does for you. Take a look at the code and imagine how much time you just saved!
* `hello.so` is the other file created by `setup.py`. You should notice that this file is an executable which contains dynamic libraries.

# Resources
These are helpful sites to guide you through what's happening here:

* [Cython Documentation](http://cython.org/)
* [Python Docs on setup.py](https://docs.python.org/3.5/distutils/setupscript.html)
* [Python Docs on Extensions](https://docs.python.org/3.5/distutils/setupscript.html#extension-source-files)
* [Hello World! in Cython](http://cython.readthedocs.io/en/latest/src/tutorial/cython_tutorial.html)
