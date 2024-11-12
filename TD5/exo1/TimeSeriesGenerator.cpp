#include "TimeSeriesGenerator.h"

void TimeSeriesGenerator::printTimeSeries(const vector<double>& timeSeries) {
    for (double value : timeSeries) {
        cout << value << " ";
    }
    cout << endl;
}

GaussianGenerator::GaussianGenerator(double mean, double stddev, int seed)
    : TimeSeriesGenerator(seed), mean(mean), stddev(stddev) {}

double GaussianGenerator::boxMullerTransform() {
    static mt19937 generator(seed); //initalise un génerateur de nombre
    uniform_real_distribution<double> distribution(0.0, 1.0);

    double u1 = distribution(generator);
    double u2 = distribution(generator);

    double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return z0 * stddev + mean;
}

double GaussianGenerator::generateTimeSeries(int size) {
    vector<double> timeSeries;
    for (int i = 0; i < size; ++i) {
        timeSeries.push_back(boxMullerTransform());
    }
    printTimeSeries(timeSeries);
    return 0;
}