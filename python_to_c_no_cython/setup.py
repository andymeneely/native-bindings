from distutils.core import setup, Extension

pythonToCExample = Extension('pythonToCExample',
                    sources = ['cModule.c'])

setup (name = 'PythonToCExample',
       version = '1.0',
       description = 'Native Bindings Lab',
       ext_modules = [pythonToCExample])

