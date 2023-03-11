#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    // Iniciando P: quantidade de jogadores, M: quantidade de cartas para cada jogador, N: quantidade total de cartas no jogo
    int P, M, N;
    cin >> P >> M >> N;

    // Se for um jogo válido
    while (P != 0 && M != 0 && N != 0)
    {
        // players: armazenará os jogadores com suas cartas
        vector<vector<pair<int, char>>> players;

        // montando as mãos de cada jogador
        for (int i = 0; i < P; i++)
        {
            vector<pair<int, char>> playerHand;
            cout << endl << i + 1 << ": ";
            for (int c = 0; c < M; c++)
            {
                pair<int, char> card;
                cin >> card.first >> card.second;
                playerHand.push_back(card);
            }
            players.push_back(playerHand);
        }

        // deck:
        queue<pair<int, char>> deck;
        stack<pair<int, char>> discart;

        cout << "---" << endl;
        // montando o baralho
        for (int i = 0; i < N - (P * M); i++)
        {
            pair<int, char> card;
            cin >> card.first >> card.second;
            deck.push(card);
        }

        cout << "---" << endl;

        // removendo a primeira carta que foi inserida no deck e inserindo no monte de descarte
        discart.push(deck.front());
        deck.pop();

        cout << "Discart Top: " << discart.top().first << " " << discart.top().second << endl;
        cout << "Deck Front: " << deck.front().first << " " << deck.front().second << endl;

        // variáveis de controle do jogo
        bool isPlaying = true;
        bool clockWise = true;
        bool cardPowerUsed = false;
        int playerPlaying = 0;

        // Se alguem ainda não zerou as cartas na mão, então ainda estará jogando
        while (isPlaying)
        {
            pair<int, char> card;
            for (int i = 0; i < P; i++)
            {
                if(players[i].size() == 0) {
                    isPlaying = false;
                    playerPlaying = i;
                    continue;
                }
            }
            // discartTop: armazena a carta presente no topo do monte de descarte
            pair<int, char> discartTop = discart.top();
            
            cout << " --------- " << endl;
            cout << "Discart Top: " << discartTop.first << " " << discartTop.second << endl;
            cout << "Current Player: " << playerPlaying + 1 << endl;
            cout << "Hand: ";
            for (int i = 0; i < players[playerPlaying].size(); i++)
            {
                card = players[playerPlaying][i];
                cout << card.first << " " << card.second << " , ";
            }
            cout << endl;
            
            /*
            Indepente se for na primeira jogada ou depois, se houver uma carta no monte de descarte que possui poder então este poder será ativado.
            Sempre que inicia uma jogada de algum jogador é feita esta verificação
            */
            if (!cardPowerUsed)
            {
                // Se o poder ainda não foi usado, então verificar qual carta está no topo e aplicar o poder
                if (discartTop.first == 1)
                {
                    // Às: jogador compra uma carta e passa a vez ( não há direito de descarte ).
                    players[playerPlaying].push_back(deck.front());
                    deck.pop();
                    cardPowerUsed = true;
                }
                else if (discartTop.first == 7)
                {
                    // Sete: jogador compra duas carta e passa a vez ( não há direito de descarte ).
                    players[playerPlaying].push_back(deck.front());
                    deck.pop();
                    players[playerPlaying].push_back(deck.front());
                    deck.pop();
                    cardPowerUsed = true;
                }
                else if (discartTop.first == 11)
                {
                    // Valete: jogador passa a vez ( não há direito de descarte ).
                    cardPowerUsed = true;
                }
                else if (discartTop.first == 12)
                {
                    // Dama: inverte-se o sentido do jogo, mas o jogador não perde a vez.
                    clockWise = !clockWise;
                    cardPowerUsed = true;
                }
                // Checa-se se algum dos poderes foi ativado e não é dama, pois neste caso haverá a necessidade de mudar o jogador que estará jogando, ou seja, passa-se a vez.
                if (cardPowerUsed && discartTop.first != 12)
                {
                    
                    cout << "New Hand: ";
                    for (int i = 0; i < players[playerPlaying].size(); i++)
                    {
                        card = players[playerPlaying][i];
                        cout << card.first << " " << card.second << " , ";
                    }
                    cout << endl;
                    
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

                    
                    cout << "Current Player: " << playerPlaying + 1 << endl;
                    cout << "Hand: ";
                    for (int i = 0; i < players[playerPlaying].size(); i++)
                    {
                        card = players[playerPlaying][i];
                        cout << card.first << " " << card.second << " , ";
                    }
                    cout << endl;
                    
                }
            }

            
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
                // Não há carta para descartar, deve-se comprar uma nova carta e descartá-la se possível
                pair<int, char> frontCard = deck.front();
                cout << "Bought card: " << frontCard.first << " " << frontCard.second << endl;
                deck.pop();
                if (frontCard.first == discartTop.first || frontCard.second == discartTop.second)
                {
                    // Descarta-se a carta
                    discart.push(frontCard);
                    cardPowerUsed = false;
                    cout << "Discarting card: " << frontCard.first << " " << frontCard.second << endl;
                }
                else
                    players[playerPlaying].push_back(frontCard);
            }
            else
            {
                //Jogador está descartando uma carta
                //Se o jogador zerou as cartas ( size - 1 ), logo, isPlaying é setado para false e volta no loop while e checa-se esta variável através do continue
                //Assim, o jogo parará e a pessoa na posição playerPlaying será o vencedor
                if (size - 1 == 0)
                {
                    cout << "Discarting card: " << players[playerPlaying][size - 1].first << " " << players[playerPlaying][size - 1].second << endl;
                    isPlaying = false;
                    continue;
                }
                else if (size - 1 != indexCardToDiscart)
                {
                    //Caso a carta não esteja na posição final da mao devemos salvar a última carta na posição da carta que será removida
                    players[playerPlaying][indexCardToDiscart].first = players[playerPlaying][size - 1].first;
                    players[playerPlaying][indexCardToDiscart].second = players[playerPlaying][size - 1].second;
                }
                //Remove-se a última carta na mão da pessoa, insere no topo do monte de descarte
                players[playerPlaying].resize(size - 1);
                discart.push(cardToDiscart);
                cardPowerUsed = false;
                cout << "Discarting card: " << cardToDiscart.first << " " << cardToDiscart.second << endl;
            }

            /*
            pair<int, char> cardToDiscartSameNaipe;
            int cardToDiscartIndexSameNaipe = 0;
            cardToDiscartSameNaipe.first = 0;
            cardToDiscartSameNaipe.second = 'A';

            pair<int, char> cardToDiscartSameNumber;
            int cardToDiscartSameNumberIndex = 0;
            cardToDiscartSameNumber.first = 0;
            cardToDiscartSameNumber.second = 'A';

            int size = players[playerPlaying].size();

            for (int i = 0; i < size; i++)
            {
                card = players[playerPlaying][i];
                if (card.first == discartTop.first)
                {
                    if (card.second > cardToDiscartSameNumber.second)
                    {
                        cardToDiscartSameNumber = card;
                        cardToDiscartSameNumberIndex = i;
                    }
                }

                if (card.second == discartTop.second)
                    if (card.first > cardToDiscartSameNaipe.first)
                    {
                        cardToDiscartSameNaipe = card;
                        cardToDiscartIndexSameNaipe = i;
                    }
            }

            if (cardToDiscartSameNaipe.first == 0)
            {
                if (cardToDiscartSameNumber.first == 0)
                {
                    pair<int, char> frontCard = deck.front();
                    // cout << "Bought card: " << frontCard.first << " " << frontCard.second << endl;
                    deck.pop();
                    if (frontCard.first == discartTop.first || frontCard.second == discartTop.second)
                    {
                        discart.push(frontCard);
                        cardPowerUsed = false;
                        // cout << "Discarting card: " << frontCard.first << " " << frontCard.second << endl;
                    }
                    else
                        players[playerPlaying].push_back(frontCard);
                }
                else
                {
                    if (size - 1 == 0)
                    {
                        // cout << "Discarting card: " << players[playerPlaying][size - 1].first << " " << players[playerPlaying][size - 1].second << endl;
                        isPlaying = false;
                        continue;
                    }

                    if(size - 1 != cardToDiscartSameNumberIndex) {
                        pair<int, char> temp = players[playerPlaying][size - 1];
                        players[playerPlaying][cardToDiscartSameNumberIndex] = temp;
                    }

                    players[playerPlaying].resize(size - 1);
                    discart.push(cardToDiscartSameNumber);
                    cardPowerUsed = false;
                    // cout << "Discarting card: " << cardToDiscartSameNumber.first << " " << cardToDiscartSameNumber.second << endl;
                }
            }
            else
            {
                if (size - 1 == 0)
                {
                    // cout << "Discarting card: " << players[playerPlaying][size - 1].first << " " << players[playerPlaying][size - 1].second << endl;
                    isPlaying = false;
                    continue;
                }

                pair<int, char> cardToDiscartTemp = cardToDiscartSameNaipe;
                int indexToDiscartTemp = cardToDiscartIndexSameNaipe;

                if (cardToDiscartSameNumber.first != 0 && indexToDiscartTemp != cardToDiscartSameNumberIndex)
                {
                    if (cardToDiscartSameNumber >= cardToDiscartTemp)
                    {
                        cardToDiscartTemp = cardToDiscartSameNumber;
                        indexToDiscartTemp = cardToDiscartSameNumberIndex;
                    }
                }

                if(indexToDiscartTemp != size - 1) {
                    pair<int, char> temp = players[playerPlaying][size - 1];
                    players[playerPlaying][indexToDiscartTemp] = temp;
                }

                players[playerPlaying].resize(size - 1);
                discart.push(cardToDiscartTemp);
                cardPowerUsed = false;
                // cout << "Discarting card: " << cardToDiscartTemp.first << " " << cardToDiscartTemp.second << endl;
            }
            */

            //Checa-se o sentido da mesa e passa para a próxima pessoa
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