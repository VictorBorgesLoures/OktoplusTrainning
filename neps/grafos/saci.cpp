#include <bits/stdc++.h>

using namespace std;

pair<int, bool> solve(short ** lab, int M, int N, int x, int y, bool first);

int main() {
    int M, N, x, y;
    short value;
    cin >> M >> N;
    short **mat;
    mat = (short**)malloc (M * sizeof (short*)) ;
    for (int i = 0; i < N; i++)
        mat[i] = (short*)malloc (N * sizeof (short));    

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> value;
            if(value == 2) {
                x = i;
                y = j;
            }
            mat[i][j] = value;
        }     
    }
    
    cout << solve(mat, M, N, x, y, true).first << '\n';

    for (int i = 0; i < N; i++)
        free(mat[i]);
    free(mat); 

    return 0;
}

pair<int, bool> solve(short ** lab, int M, int N, int x, int y, bool first) {
    pair<int, bool> sum = make_pair(0, false);
    if(x < 0 || x == M || y < 0 || y == N)
        return sum;
    if(lab[x][y] == 3)
        return make_pair(1, true);
    if(!first && lab[x][y] != 1)
        return sum;
    sum.first++;
    lab[x][y] = 0;
    pair<int, bool> move = solve(lab, M, N, x, y+1, false);
    lab[x][y] = 1;

    if(move.second) {
        sum.first += move.first;
        sum.second = move.second;
        return sum;
    }
    lab[x][y] = 0;
    move = solve(lab, M, N, x+1, y, false);
    lab[x][y] = 1;
    if(move.second) {
        sum.first += move.first;
        sum.second = move.second;
        return sum;
    }
    lab[x][y] = 0;
    move = solve(lab, M, N, x, y-1, false);
    lab[x][y] = 1;
    if(move.second) {
        sum.first += move.first;
        sum.second = move.second;
        return sum;
    }
    lab[x][y] = 0;
    move = solve(lab, M, N, x-1, y, false);
    lab[x][y] = 1;
    if(move.second) {
        sum.first += move.first;
        sum.second = move.second;
        return sum;
    }
    return sum;
}