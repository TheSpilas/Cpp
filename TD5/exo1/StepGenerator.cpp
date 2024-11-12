#include "TimeSeriesGenerator.h"

StepGenerator::StepGenerator(int seed)
    : TimeSeriesGenerator(seed) {}

double StepGenerator::generateTimeSeries(int size) {
    vector<double> timeSeries;
    timeSeries.push_back(0);

    static mt19937 generator(seed);
    uniform_int_distribution<int> distribution(0, 100);
    uniform_real_distribution<double> probability(0.0, 1.0);

    for (int i = 1; i < size; ++i) {
        if (probability(generator) < 0.5) {
            timeSeries.push_back(distribution(generator));
        } else {
            timeSeries.push_back(timeSeries.back());
        }
    }

    printTimeSeries(timeSeries);
    return 0;
}