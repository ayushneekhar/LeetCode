#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0;
        int right = 0;
        
        while(left < s.length() && right < t.length()){
            if(t[right] == s[left]){
                left++;
                right++;
            } else
                right++;
        }
        
        return left == s.length() ? true : false;
    }
};