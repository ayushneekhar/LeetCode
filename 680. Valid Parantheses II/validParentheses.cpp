#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length() < 2) return false;
        
        stack<char> par;
        
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') par.push(s[i]);
            else if((s[i] == ')' || s[i] == '}' || s[i] == ']'))
                if (!par.empty() && s[i] == ')' && par.top() == '(') par.pop();
                else if (!par.empty() && s[i] == '}' && par.top() == '{') par.pop();
                else if (!par.empty() && s[i] == ']' && par.top() == '[') par.pop();
                else return false;
        }        
        
        if(par.empty()) return true;
        else return false;
        
    }
};
