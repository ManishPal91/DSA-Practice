// LC 3498 - Reverse Degree of a String
// https://leetcode.com/problems/reverse-degree-of-a-string/
class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            int num = s[i]-'a';
            ans += (i+1)*(26-num);
        }
        return ans;
    }
};