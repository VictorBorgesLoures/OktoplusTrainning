#include <bits/stdc++.h>

using namespace std;

struct chessPos {
    int l, c;
};

long long countPossibleKnightPositions(int k, chessPos knight) {
    int count = 0;
    if(knight.l > 1 && knight.l < k-2 && knight.c > 1 && knight.c < k-2) {
        count = 8;
    } else {
        int mL = knight.c == 0 ? 0 : (knight.c >= 2 ? 2 : 1);
        int mR = k-1-knight.c == 0 ? 0 : (k-1-knight.c >= 2 ? 2 : 1);
        int mS = knight.l == 0 ? 0 : (knight.l >= 2 ? 2 : 1);
        int mI = k-1-knight.l == 0 ? 0 : (k-1-knight.l >= 2 ? 2 : 1);
        if(mL == 1) {
            if(mS == 2)
                count++;
            if(mI == 2)
                count++;
        }
        if(mL == 2) {
            if(mS == 1)
                count++;
            else if(mS == 2)
                count += 2;
            if(mI == 1)
                count++;
            else if(mI == 2)
                count+=2;
        }

        if(mR == 1) {
            if(mS == 2)
                count++;
            if(mI == 2)
                count++;
        }
        if(mR == 2) {
            if(mS == 1)
                count++;
            else if(mS == 2)
                count += 2;
            if(mI == 1)
                count++;
            else if(mI == 2)
                count+=2;
        }
        /*
        for (int i = (knight.l-2 < 0 ? 0 : knight.l-2); i <= (knight.l+2 > k-1 ? k-1 : knight.l+2); i++)
            for (int j = (knight.c-2 < 0 ? 0 : knight.c-2); j <= (knight.c+2 > k-1 ? k-1 : knight.c+2); j++)
            {
                if((i == knight.l-2 && (j == knight.c-1 || j == knight.c+1)) 
                || (i == knight.l-1 && (j == knight.c-2 || j == knight.c+2)) 
                || (i == knight.l+1 && (j == knight.c-2 || j == knight.c+2)) 
                || (i == knight.l+2 && (j == knight.c-1 || j == knight.c+1))
                )
                    count++;
            }
        */
    }
    return (k*k-1-count);  
}

int main() {

    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k = i+1;
        if(k == 1) {
            cout << "0" << endl;
            continue;
        }
        long long sum = 0;
        for (int l = 0; l < k; l++)
        {
            for (int c = 0; c < k; c++)
            {
                chessPos k1;
                k1.l = l;
                k1.c = c;
                sum += countPossibleKnightPositions(k, k1);
            }
        }
        cout << sum / 2 << endl;
    }   

    return 0;
}