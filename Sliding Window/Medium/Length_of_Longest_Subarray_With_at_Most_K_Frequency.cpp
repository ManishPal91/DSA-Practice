// Leetcode 2958 Length of Longest Subarray With at Most K Frequency
// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/

class Solution {
public:
int maxSubarrayLength(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int i = 0;
    int n = nums.size();
    int len = 0;
    int maxLen = 0;
    for(int j = 0; j < n; j++){
        mp[nums[j]]++;
        len++;
        while(mp[nums[j]] > k){
            mp[nums[i]]--;
            i++;
            len--;
        }
        maxLen = max(maxLen, len);
    }
    return maxLen;
}
};