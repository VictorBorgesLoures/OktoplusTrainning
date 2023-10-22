#include <bits/stdc++.h>

using namespace std;

int qtdEated(vector<long long> c, long long e);

int main() {

    /*
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N ; cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n, q; cin >> n >> q;
        long long candles[n];
        for (int c = 0; c < n; c++)
            cin >> candles[c];
        sort(candles, candles+n);
        long long eat;
        for (int c = 0; c < q; c++)
        {
            cin >> eat;
            int init = 0, end = n-1;
            long long sum = 0;
            int candlesEated = 0;
            while(init <= end && sum < eat) {
                sum += candles[end];
                candlesEated++;
                end--;
            }
 
            if(sum >= eat)
                cout << candlesEated << '\n';
            else
                cout << "-1" << '\n';
        }
        
    }
    */
    /*
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N ; cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n, q; cin >> n >> q;
        multiset<long long, greater<long long>> candles;
        long long v;
        for (int c = 0; c < n; c++) {
            cin >> v;
            candles.insert(v);
        }
        long long eat;
        for (int c = 0; c < q; c++)
        {
            cin >> eat;
            long long sum = 0;
            int candlesEated = 0;
            for (auto itr = candles.begin(); itr != candles.end() && sum < eat; itr++)
            {
                sum += (*itr);
                candlesEated++;
            }
            if(sum >= eat)
                cout << candlesEated << '\n';
            else
                cout << "-1" << '\n';
        }
        
        
    }
    */
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N ; cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n, q; cin >> n >> q;
        vector<long long> candles;
        long long v;
        for (int c = 0; c < n; c++) 
        {
            cin >> v;
            candles.push_back(v);
        }

        sort(candles.rbegin(), candles.rend());
        for (int c = 1; c < n; c++)
            candles[c] = candles[c-1] + candles[c];    
        long long eat;
        for (int c = 0; c < q; c++)
        {
            cin >> eat;
            if(candles[n-1] >= eat) {
                int candlesEated = qtdEated(candles, eat);
                cout << candlesEated << '\n';
            } else
                cout << "-1" << '\n';
        }
    }    
    
    return 0;
}

int qtdEated(vector<long long> c, long long e) {
    int beg = 0, end = c.size()-1, h, resp = -1;
    while(beg <= end) {
        h = beg + (end-beg)/2;
        if(c[h] < e) {
            beg = h+1;
        } else {
            resp = h;
            end = h-1;
        }
    }

    return resp+1;
}