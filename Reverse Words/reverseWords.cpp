#include <bits/stdc++.h>

using namespace std;
class Solutions
{
public:
    string reverseWords(string s)
    {
        istringstream ss(s);
        vector<string> word;
        string w;
        while (ss >> w)
            word.push_back(w);

        for (int i = 0; i < word.size(); ++i)
        {
            int left = 0;
            int right = word[i].size() - 1;
            while (right > left)
                swap(word[i][right--], word[i][left++]);
        }

        w = "";
        for (auto it : word)
            w += " " + it;

        w.erase(0, 1);
        return w;
    }
};

int main()
{
    string str = "Let's take LeetCode contest";
    Solutions s;
    s.reverseWords(str);
}