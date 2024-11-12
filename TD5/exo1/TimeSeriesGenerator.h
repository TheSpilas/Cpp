#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include <vector>

using namespace std;

class TimeSeriesGenerator {
protected:
    int seed;

public:
    TimeSeriesGenerator() : seed(0) {}
    TimeSeriesGenerator(int seed) : seed(seed) {}

    virtual double generateTimeSeries(int) = 0;
    static void printTimeSeries(const vector<double>& timeSeries);
};

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;
    double stddev;

    double boxMullerTransform();

public:
    GaussianGenerator(double mean, double stddev, int seed = 0);

    double generateTimeSeries(int size) override;
};

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator(int seed = 0);

    double generateTimeSeries(int size) override;
};

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double amplitude;
    double frequency;
    double phase;

public:
    SinWaveGenerator(double amplitude, double frequency, double phase, int seed = 0);

    double generateTimeSeries(int size) override;
};

#endif