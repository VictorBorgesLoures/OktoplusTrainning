#include <bits/stdc++.h>
using namespace std;

int main()
{

    string n;
    getline(cin >> ws, n);
    string cp = n;
    int best = INT_MAX;
    int c = 0;
    int nTam = n.size();
    while (c < nTam-2 && n[c] == n[c + 1])
        c++;
        
    sort(cp.begin()+c, cp.end());
    if (!strcmp(n.c_str(), cp.c_str()))
    {
        if(n.size() > 1) {
            int i = 1;
            while(cp[n.size() - i] == cp[n.size() - (i+1)] && i < n.size()-1) {
                i++;
            }
            swap(cp[n.size() - (i)], cp[n.size() - (i+1)]);
        }
    }
    else
    {
        for (int i = c; i < n.size(); i++)
        {
            string cpSorted = cp;
            sort(cpSorted.begin() + i, cpSorted.end());
            if (best == INT_MAX)
            {
                int j = i + 1;
                while (j < n.size())
                {
                    swap(cpSorted[i], cpSorted[j]);
                    if (cpSorted < n)
                    {
                        swap(cpSorted[i], cpSorted[j]);
                    }
                    else
                    {
                        best = stoi(cpSorted);
                        cp = cpSorted;
                        break;
                    }
                    j++;
                }
            }
            else
            {
                if (cpSorted > n && stoi(cpSorted) < best)
                {
                    cp = cpSorted;
                    break;
                }
            }
        }
    }
    cout << (!strcmp(n.c_str(), cp.c_str()) ? "0" : (cp < n ? "0" : cp)) << endl;

    return 0;
}