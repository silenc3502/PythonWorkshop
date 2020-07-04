from distutils.core import setup, Extension
from Cython.Build import cythonize

ext = Extension('stdcyc',
                sources=[
                    'stdcy.pyx',
                    'std.cpp',
                ],
                language='c++',
                )

setup(name='std_performance_cyc',
      version='1.0',
      description='Module for calculating standard deviation.',
      ext_modules=cythonize(ext))
