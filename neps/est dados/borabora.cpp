#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int P, M, N;
    cin >> P >> M >> N;

    while (P != 0 && M != 0 && N != 0)
    {
        vector<vector<pair<int, char>>> players;

        for (int i = 0; i < P; i++)
        {
            vector<pair<int, char>> playerHand;
            for (int c = 0; c < M; c++)
            {
                pair<int, char> card;
                cin >> card.first >> card.second;
                playerHand.push_back(card);
            }
            players.push_back(playerHand);
        }

        queue<pair<int, char>> deck;
        stack<pair<int, char>> discart;

        for (int i = 0; i < N - (P * M); i++)
        {
            pair<int, char> card;
            cin >> card.first >> card.second;
            deck.push(card);
        }

        discart.push(deck.front());
        deck.pop();

        bool isPlaying = true;
        bool clockWise = true;
        bool cardPowerUsed = false;
        int playerPlaying = 0;

        while (isPlaying)
        {
            
            pair<int, char> discartTop = discart.top();
            if (!cardPowerUsed)
            {
                if (discartTop.first == 1)
                {
                    players[playerPlaying].push_back(deck.front());
                    deck.pop();
                    cardPowerUsed = true;
                }
                else if (discartTop.first == 7)
                {
                    players[playerPlaying].push_back(deck.front());
                    deck.pop();
                    players[playerPlaying].push_back(deck.front());
                    deck.pop();
                    cardPowerUsed = true;
                }
                else if (discartTop.first == 11)
                {
                    cardPowerUsed = true;
                }
                else if (discartTop.first == 12)
                {
                    clockWise = !clockWise;
                    cardPowerUsed = true;
                }
                if (cardPowerUsed && discartTop.first != 12)
                {
                    if (clockWise)
                    {
                        playerPlaying++;
                        if (playerPlaying == P)
                            playerPlaying = 0;
                    }
                    else
                    {
                        playerPlaying--;
                        if (playerPlaying == -1)
                            playerPlaying = P - 1;
                    }
                }
            }

            pair<int, char> card;
            pair<int, char> cardToDiscart;
            int indexCardToDiscart = -1;
            cardToDiscart.first = 0;
            cardToDiscart.second = 'A';
            int size = players[playerPlaying].size();

            for (int i = 0; i < size; i++)
            {
                card = players[playerPlaying][i];
                if (card.first == discartTop.first || card.second == discartTop.second)
                {
                    if (card > cardToDiscart)
                    {
                        cardToDiscart = card;
                        indexCardToDiscart = i;
                    }
                }
            }

            if (indexCardToDiscart == -1)
            {
                pair<int, char> frontCard = deck.front();
                deck.pop();
                if (frontCard.first == discartTop.first || frontCard.second == discartTop.second)
                {
                    discart.push(frontCard);
                    cardPowerUsed = false;
                }
                else
                    players[playerPlaying].push_back(frontCard);
            }
            else
            {
                if (size - 1 == 0)
                {
                    isPlaying = false;
                    continue;
                }
                else if (size - 1 != indexCardToDiscart)
                {
                    pair<int, char> temp = players[playerPlaying][size - 1];
                    players[playerPlaying][indexCardToDiscart] = temp;
                }

                players[playerPlaying].resize(size - 1);
                discart.push(cardToDiscart);
                cardPowerUsed = false;
            }

            if(discart.top().first == 12 && !cardPowerUsed) {
                clockWise = !clockWise;
                cardPowerUsed = true;
            }

            if (clockWise)
            {
                playerPlaying++;
                if (playerPlaying == P)
                    playerPlaying = 0;
            }
            else
            {
                playerPlaying--;
                if (playerPlaying == -1)
                    playerPlaying = P - 1;
            }
        }

        cout << playerPlaying + 1 << endl;
        cin >> P >> M >> N;
    }

    return 0;
}