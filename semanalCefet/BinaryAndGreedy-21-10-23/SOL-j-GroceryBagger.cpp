#include <bits/stdc++.h>

using namespace std;

class GroceryBagger {
    public:
        int minimumBags(int strength, vector<string> itemType);
};

int GroceryBagger::minimumBags(int strength, vector<string> itemType) {
    int size = itemType.size();
    if(strength == 1)
        return size;
    map<string, int> items;
    for (int i = 0; i < size; i++)
        items[itemType[i]]++; 
    int bags = 0;
    for (auto &it : items)
    {
        bags += (it.second%strength > 0 ? 1 : 0);
        bags += it.second/strength;
    }
    return bags;    
}