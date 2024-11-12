#include "TimeSeriesDataset.h"

TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain)
    : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

void TimeSeriesDataset::zNormalizeSeries(vector<double>& series) {
    double mean = accumulate(series.begin(), series.end(), 0.0) / series.size();
    double sq_sum = inner_product(series.begin(), series.end(), series.begin(), 0.0);
    double stdev = sqrt(sq_sum / series.size() - mean * mean);

    for (double& value : series) {
        value = (value - mean) / stdev;
    }
}

void TimeSeriesDataset::addSeries(const vector<double>& series, int label) {
    vector<double> normalizedSeries = series;

    if (znormalize) {
        zNormalizeSeries(normalizedSeries);
    }

    data.push_back(normalizedSeries);
    labels.push_back(label);
    maxLength = max(maxLength, static_cast<int>(series.size()));
    numberOfSamples++;
}

const vector<vector<double>>& TimeSeriesDataset::getData() const {
    return data;
}

const vector<int>& TimeSeriesDataset::getLabels() const {
    return labels;
}

int TimeSeriesDataset::getMaxLength() const {
    return maxLength;
}

int TimeSeriesDataset::getNumberOfSamples() const {
    return numberOfSamples;
}