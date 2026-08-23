// Leetcode - 1927 Sum Game
// Link - https://leetcode.com/problems/sum-game/description/


class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int leftcount = 0;
        int rightcount = 0;
        int leftsum = 0;
        int rightsum = 0;
        for(int i = 0; i < n; i++){
            if(num[i] == '?'){
                if(i < n/2) leftcount++;
                else rightcount++;
            }
            else{
                if(i < n/2) leftsum += (num[i]-'0');
                else rightsum += (num[i]-'0');
            }
        }
        int totalSum = leftcount + rightcount;
        if(totalSum % 2) return true;
        int left = 2*leftsum + 9*leftcount;
        int right = 2*rightsum + 9*rightcount;
        return (left != right);
    }
};