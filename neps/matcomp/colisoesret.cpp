#include <iostream>

using namespace std;

struct ponto {
    int x,y;
};

int solve(ponto Ai, ponto Af, ponto Bi, ponto Bf);

int main() {

    ponto pA, pB, pC, pD;

    cin >> pA.x >> pA.y;
    cin >> pB.x >> pB.y;
    cin >> pC.x >> pC.y;
    cin >> pD.x >> pD.y;

    cout << solve(pA, pB, pC, pD) << endl;

    return 0;
}

int solve(ponto pA, ponto pB, ponto pC, ponto pD) {

    int hasColision = 0;

    if(pA.x <= pD.x && pA.x >= pC.x && pB.y <= pD.y && pB.y >= pC.y)
        hasColision = 1;
    
    if(pD.y <= pB.y && pD.y >= pA.y && pC.x <= pB.x && pC.x >= pA.x)
        hasColision = 1;

    if(pA.y <= pC.y && pB.y >= pC.y && pC.x <= pB.x && pC.x >= pA.x)
        hasColision = 1;

    if(pA.y <= pD.y && pB.y >= pD.y && pD.x <= pB.x && pD.x >= pA.x)
        hasColision = 1;

    if(pB.y <= pD.y && pB.y >= pC.y && pB.x <= pD.x && pB.x >= pC.x)
        hasColision = 1;

    if(pA.y <= pD.y && pA.y >= pC.y && pA.x <= pD.x && pA.x >= pC.x)
        hasColision = 1;

    return hasColision;
}