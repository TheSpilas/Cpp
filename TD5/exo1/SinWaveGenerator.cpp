#include "TimeSeriesGenerator.h"

SinWaveGenerator::SinWaveGenerator(double amplitude, double frequency, double phase, int seed)
    : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase) {}

double SinWaveGenerator::generateTimeSeries(int size) {
    vector<double> timeSeries;

    for (int i = 0; i < size; ++i) {
        double value = amplitude * sin(frequency * i + phase);
        timeSeries.push_back(value);
    }

    printTimeSeries(timeSeries);
    return 0;
}