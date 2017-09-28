import fnmatch
import os
import pip
import shutil

try:
    from Cython.Build import cythonize
except:
    pip.main(["install", "Cython"])
    from Cython.Build import cythonize


from distutils.core import setup
from distutils.extension import Extension

setup(
    ext_modules = cythonize([Extension("hello", ["hello.pyx"])]),
)

shutil.rmtree("./build/")
for f in os.listdir("."):
    if fnmatch.fnmatch(f, "hello.*.so"):
        os.rename(f, "hello.so")