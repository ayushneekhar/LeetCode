#include <bits/stdc++.h>

using namespace std;

class RandomizedSet
{
    vector<int> randSet;

public:
    RandomizedSet()
    {
        randSet = {};
    }

    bool insert(int val)
    {
        if (find(randSet.begin(), randSet.end(), val) == randSet.end())
        {
            randSet.push_back(val);
            return true;
        }
        else
            return false;
    }

    bool remove(int val)
    {
        if (find(randSet.begin(), randSet.end(), val) != randSet.end())
        {
            randSet.erase(find(randSet.begin(), randSet.end(), val));
            return true;
        }
        else
            return false;
    }

    int getRandom()
    {
        return randSet[rand() % randSet.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */