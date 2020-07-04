#ifndef INIT_STD_H
#define INIT_STD_H

#include <vector>

class stddev {
private:
    std::vector<double> vs;
public:
    stddev(std::vector<double>);

    void calc(const std::vector<double> *, int, int, double &, double &);

    double standardDeviation();
};

#endif
