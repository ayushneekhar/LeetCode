#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compareVersion(string v1, string v2) {
        for(int i = 0, j = 0; i < v1.length() || j < v2.length(); ++i, ++j){
            string s1 = "";
            string s2 = "";
            
            while(i < v1.length() && v1[i] != '.'){
                if(v1[i] == '0' && s1.size() == 0){
                    ++i;
                    continue;
                }
                s1 += v1[i++];
            }
            
            while(j < v2.length() && v2[j] != '.'){
                if(v2[j] == '0' && s2.size() == 0){
                    ++j;
                    continue;
                }
                s2 += v2[j++];
            }
            
            if(s1.length() > s2.length()) return 1;
            else if(s2.length() > s1.length()) return -1;
            
            int ans = s1.compare(s2);
            if(ans < 0) return -1;
            else if(ans > 0) return 1;
        }
        return 0;
    }
};