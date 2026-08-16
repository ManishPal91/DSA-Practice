// Leetcode 2029 Stone Game IX
// http://leetcode.com/problems/stone-game-ix/description/
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3,0);
        int n = stones.size();
        for(int i = 0; i < n; i++){
            cnt[stones[i]%3]++;
        }
        if(cnt[0]%2){
            if(abs(cnt[1]-cnt[2]) > 2) return true;
            return false;
        }
        if(cnt[1] > 0 && cnt[2] > 0) return true;
        return false;
    }
};