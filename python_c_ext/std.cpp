#include "std.h"

#include <vector>
#include <numeric>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <thread>
#include <chrono>
#include <iostream>

const int NUM_THREADS = 8;

stddev::stddev(std::vector<double> v) {
    vs = v;
}

void stddev::calc(const std::vector<double> *v, int start, int end, double &sum, double &squaredSum) {
    double th_sum = 0;
    double th_squaredSum = 0;

    for (int i = start; i < end; i++) {
        double it = (*v).at(i);

        th_sum += it;
        th_squaredSum += it * it;
    }

    sum += th_sum;
    squaredSum += th_squaredSum;
}

double stddev::standardDeviation() {
    auto m1_1 = std::chrono::steady_clock::now();

    // If you use a pointer, you can improve performance.
    std::vector<double> v = vs;

    auto m1_2 = std::chrono::duration_cast<std::chrono::milliseconds>
            (std::chrono::steady_clock::now() - m1_1);
    std::cout << "[C++] std::vector loading: " << m1_2.count() << " ms" << std::endl;

    std::vector<std::thread> ths;

    double sum = 0;
    double squaredSum = 0;

    std::cout << "[C++] NUM_THREADS: " << NUM_THREADS << std::endl;

    auto m2_1 = std::chrono::steady_clock::now();

    // Start threads.
    for (int i = 0; i < NUM_THREADS; ++i) {
        int start = i * round(v.size() / NUM_THREADS);
        int end = (i == NUM_THREADS - 1) ? v.size() : (i + 1) * round(v.size() / NUM_THREADS);

        ths.push_back(std::thread(&stddev::calc, this, &v, start, end, std::ref(sum), std::ref(squaredSum)));
    }

    // Waiting for threads to finish.
    for (auto &t : ths) {
        t.join();
    }
    auto m2_2 = std::chrono::duration_cast<std::chrono::milliseconds>
            (std::chrono::steady_clock::now() - m2_1);
    std::cout << "[C++] thread execution elapsed: " << m2_2.count() << " ms" << std::endl;

    double mean = sum / v.size();
    return sqrt(squaredSum / v.size() - mean * mean);
}
