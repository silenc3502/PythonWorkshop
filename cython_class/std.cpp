#include "std.h"

#include <vector>
#include <numeric>
#include <iterator>
#include <cmath>

stddev::stddev(std::vector<double> v) {
    vs = v;
}

double stddev::standardDeviation() {
    std::vector<double> v = vs;

    double sum = std::accumulate(v.begin(), v.end(), 0.0);
    double mean = sum / v.size();

    double squareSum = std::inner_product(v.begin(), v.end(), v.begin(), 0.0);
    return sqrt(squareSum / v.size() - mean * mean);
}
