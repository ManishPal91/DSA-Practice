// Leetcode 3870 Count Commas In Range
// https://leetcode.com/problems/count-commas-in-range/


class Solution {
public:
    int countCommas(int n) {
        string str = to_string(n);
        if(str.size() < 4) return 0;
        return n-999;
    }
};