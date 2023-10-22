#include <bits/stdc++.h>

using namespace std;

int binnary_search_lb(vector<int> v, int k)
{
    int beg = 0, end = v.size()-1, resp = -1, h;
    while (beg <= end)
    {
        h = beg + (end - beg) / 2;
        /*
        if(v[h].second && end >= 0) {
            end--;
            continue;
        }
        */
        if (v[h] <= k)
        {
            resp = h;
            beg = h + 1;
        }
        else
            end = h - 1;
    }
    /*
    if (resp != -1)
    {
        if (v[resp].second)
        {
            while (resp >= 0 && v[resp].second)
                resp--;
        }
    }
    */
    return resp;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    multiset<int, greater<int>> t;
    int b;
    for (int i = 0; i < n; i++) {
        cin >> b;
        t.insert(b);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b;
        multiset<int>::iterator s = t.lower_bound(b);
        if(s == t.end()) {
            cout << "-1" << '\n';   
        }
        else {
            cout << (*s) << '\n';
            t.erase(s);
        }          
    }
    return 0;
}