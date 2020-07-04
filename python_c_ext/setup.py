from distutils.core import setup, Extension
from Cython.Build import cythonize

ext = Extension('stdcyt',
                sources=[
                    'stdcy.pyx',
                    'std.cpp',
                ],
                language='c++',
                extra_compile_args=['-std=c++11'],
                )

setup(name='std_performance_cyt',
      version='1.0',
      description='Module for calculating standard deviation.',
      ext_modules=cythonize(ext))
