#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T > 0)
    {
        int u, v;
        map<int, set<int>> Adj;
        bool found = false;
        for (int i = 0; i < T; i++)
        {
            cin >> u >> v;
            Adj[u - 1].insert(v - 1);
            if (!found && u != v)
            {
                if (Adj[v - 1].find(u - 1) != Adj[v - 1].end())
                {
                    cout << "YES\n";
                    found = true;
                }
            }
        }

        if (!found)
            cout << "NO\n";
        cin >> T;
    }

    return 0;
}