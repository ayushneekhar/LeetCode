#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s2, string s1) {
        if(s2.length() > s1.length()) return false;
        
        vector<int> s1_char(26, 0);
        vector<int> s2_char(26, 0);
        
        int left = 0;
        int right = 0;
        
        for(; right < s2.length(); ++right){
            s2_char[s2[right] - 'a']++;
            s1_char[s1[right] - 'a']++;
        }
        
        if(s2_char == s1_char) return true;
        
        for(; right < s1.size(); ++right, ++left){
            s1_char[s1[right] - 'a']++;
            s1_char[s1[left] - 'a']--;
            
            if(s1_char == s2_char) return true;
        }
        
        return false;
    }
};