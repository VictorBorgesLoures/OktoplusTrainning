#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int Q, S;
        cin >> Q >> S;
        vector<string> v;
        int menor = INT_MAX;
        for (int c = 0; c < Q; c++)
        {
            string s; getline(cin >> ws, s);
            if (v.size() > 0)
            {
                int cMenor = INT_MAX;
                for (int k = 0; k < v.size(); k++)
                {
                    int current = 0;
                    for (int l = 0; l < S; l++)
                    {
                        current += abs(s[l] - v[k][l]);   
                    }
                    cMenor = min(cMenor, current);
                }
                menor = min(menor, cMenor);                
            }
            v.push_back(s);
        }    
        cout << menor << endl;    
    }

    return 0;
}