#include <bits/stdc++.h>

using namespace std;

bool oneChangeBit(string b1, string b2)
{
    int dif = 0;
    for (int i = 0; i < b1.size(); i++)
    {
        if (b1[i] != b2[i])
            dif++;
        if (dif > 1)
            return false;
    }
    return true;
}

string convertToBinary(int number, int n)
{
    string bit = "";
    while ((float)number / 2 > 0)
    {
        int resto = number % 2;
        number /= 2;
        bit += (char)(resto + '0');
    }
    while (bit.size() < n)
    {
        bit += '0';
    }
    string finalBit = "";
    for (int i = bit.size() - 1; i >= 0; i--)
        finalBit += bit[i];

    return finalBit;
}

int main()
{

    int n;
    cin >> n;

    int qtd = pow(2, n);
    set<string> bits;
    for (int i = 0; i < qtd; i++)
        bits.insert(convertToBinary(i, n));
    
    string prev;
    prev = *bits.begin();
    cout << prev << endl;
    bits.erase(bits.begin());
    set<string> removeds;
    while(!bits.empty()) {
        string current = *bits.begin();
        if(!oneChangeBit(prev, current)) {
            bits.erase(bits.begin());
            removeds.insert(current);
            bool found = true;
            while(found) {
                found = false;
                for (auto i = removeds.begin(); i != removeds.end(); i++)
                    if(oneChangeBit(prev, *i)) {
                        found = true;
                        cout << *i << endl;
                        prev = *i;
                        removeds.erase(removeds.begin(), i);
                    }                
            }            
        } else {
            prev = current;
            cout << prev << endl;
            bits.erase(bits.begin());
        }
        if(bits.empty()) {
            while(!removeds.empty()) {
                bits.insert(*removeds.begin());
                removeds.erase(removeds.begin());
            }
            removeds.empty();
        }
    }
    /*
    for(auto it = removeds.begin();it!= removeds.end(); it++) {
        cout << *it << endl;
    }
    */
    /*
    string prev = convertToBinary(0, n);
    cout << prev << endl;
    stack<string> bits;
    for (int i = 1; i < qtd; i++)
    {
        if (bits.size() > 0)
        {
            while (bits.size() > 0 && oneChangeBit(prev, bits.top()))
            {
                cout << bits.top() << endl;
                prev = bits.top();
                bits.pop();
            }
        }
        string currentBit = convertToBinary(i, n);
        if (!oneChangeBit(prev, currentBit))
        {
            bits.push(currentBit);
        }
        else
        {
            cout << currentBit << endl;
            prev = currentBit;
        }
    }
    if (bits.size() > 0)
    {
        stack<string> sBitStack;
        prev = bits.top();
        cout << prev << endl;
        bits.pop();
        while (!bits.empty())
        {
            if (sBitStack.size() > 0)
            {
                while (sBitStack.size() > 0 && oneChangeBit(prev, sBitStack.top()))
                {
                    cout << sBitStack.top() << endl;
                    prev = sBitStack.top();
                    sBitStack.pop();
                }
            }
            string currentBit = bits.top();
            if (!oneChangeBit(prev, currentBit))
            {
                sBitStack.push(currentBit);
            }
            else
            {
                cout << currentBit << endl;
                prev = currentBit;
            }
            bits.pop();
        }
    }
    */

    return 0;
}