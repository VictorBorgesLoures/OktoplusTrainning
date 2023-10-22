#include <bits/stdc++.h>

using namespace std;

class FanFailure {
    public:
        vector<int> getRange(vector<int> capacities, int minCooling);
};

vector<int> FanFailure::getRange(vector<int> capacities, int minCooling) {
    vector<int> mf;
    mf.push_back(0);
    mf.push_back(0);
    sort(capacities.rbegin(), capacities.rend());
    int maxSum = 0;
    for (int i = 0; i < capacities.size(); i++) {
        maxSum += capacities[i];
    }

    while(maxSum >= minCooling) {
        maxSum -= capacities[mf[1]];
        mf[1]++;
    }
    mf[1]--;
    maxSum = 0;
    while(maxSum < minCooling) {
        maxSum += capacities[mf[0]];
        mf[0]++;
    }

    mf[0] = capacities.size() - mf[0];
   
    return mf;
}