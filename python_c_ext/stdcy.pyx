from libcpp.vector cimport vector

cdef extern from "std.h":
    cdef cppclass stddev:
        stddev(vector[double]) except +
        vector[double] vs
        double standardDeviation()


cdef class pystd:
    cdef stddev *thisptr;

    def __init__(self, vector[double] v):
        self.thisptr = new stddev(v)

    def __del__(self):
        del self.thisptr

    def standard_dev(self):
        return self.thisptr.standardDeviation()
