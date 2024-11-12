#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class TimeSeriesDataset {
private:
    bool znormalize;
    bool isTrain;
    vector<vector<double>> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;

    void zNormalizeSeries(vector<double>& series);

public:
    TimeSeriesDataset(bool znormalize = false, bool isTrain = true);

    void addSeries(const vector<double>& series, int label);
    const vector<vector<double>>& getData() const;
    const vector<int>& getLabels() const;
    int getMaxLength() const;
    int getNumberOfSamples() const;
};

#endif