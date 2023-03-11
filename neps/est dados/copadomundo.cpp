#include <iostream>
#include <queue>

using namespace std;

struct jogo
{
    int golEsq, golDir;
};

char getWinner(int i)
{
    switch (i)
    {
    case 0:
        return 'A';
    case 1:
        return 'B';
    case 2:
        return 'C';
    case 3:
        return 'D';
    case 4:
        return 'E';
    case 5:
        return 'F';
    case 6:
        return 'G';
    case 7:
        return 'H';
    case 8:
        return 'I';
    case 9:
        return 'J';
    case 10:
        return 'K';
    case 11:
        return 'L';
    case 12:
        return 'M';
    case 13:
        return 'N';
    case 14:
        return 'O';
    case 15:
        return 'P';
    default:
        return 'Z';
    }
}

int main()
{

    int tam = 15;
    jogo jogos[tam];
    queue<int> vencedores;

    for (int i = 0; i < tam; i++)
    {
        cin >> jogos[i].golEsq >> jogos[i].golDir;
    }

    int qtdInit = 8;
    for (int i = 0; i < qtdInit; i++)
    {
        if (jogos[i].golEsq > jogos[i].golDir) {
            vencedores.push(i*2);
        }
        else {
            vencedores.push(i*2 + 1);
        }
    }

    int qtdQuartas = 4;
    for (int i = qtdInit; i < qtdInit + qtdQuartas; i++)
    {
        if (jogos[i].golEsq > jogos[i].golDir)
        {
            vencedores.push(vencedores.front());
            vencedores.pop();
            vencedores.pop();
        }
        else
        {
            vencedores.pop();
            vencedores.push(vencedores.front());
            vencedores.pop();
        }
    }

    int qtdSemi = 2;

    for (int i = qtdInit + qtdQuartas; i < qtdInit + qtdQuartas + qtdSemi; i++)
    {
        if (jogos[i].golEsq > jogos[i].golDir)
        {
            vencedores.push(vencedores.front());
            vencedores.pop();
            vencedores.pop();
        }
        else
        {
            vencedores.pop();
            vencedores.push(vencedores.front());
            vencedores.pop();
        }
    }

    if (jogos[tam-1].golEsq > jogos[tam-1].golDir)
    {
        vencedores.push(vencedores.front());
    }
    else
    {
        vencedores.pop();
        vencedores.push(vencedores.front());
    }

    cout << getWinner(vencedores.front()) << endl;

    return 0;
}