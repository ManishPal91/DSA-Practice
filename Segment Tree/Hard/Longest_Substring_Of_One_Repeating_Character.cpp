// Leetcode 2213 Longest Substring of One Repeating Character
// https://leetcode.com/problems/longest-substring-of-one-repeating-character/description/
class Solution {
public:
    struct Node{
        int maxLen = 0;
        int pre = 0;
        int suff = 0;
        char leftChar = 0;
        char rightChar = 0;
    };
    int n; 
    vector<Node> segTree;
    Node merge(Node& L, Node& R, int leftLen, int rightLen){
        Node res; 
        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;
        res.pre = L.pre;
        if(L.pre == leftLen && L.rightChar == R.leftChar){
            res.pre = L.pre + R.pre;
        }
        res.suff = R.suff;
        if(R.suff == rightLen && L.rightChar == R.leftChar){
            res.suff = L.suff + R.suff;
        }
        res.maxLen = max(L.maxLen, R.maxLen);
        if(L.rightChar == R.leftChar){
            res.maxLen = max(res.maxLen, L.suff + R.pre);
        }
        return res;
    }
    void buildSegmentTree(int i, int l, int r, string& s){
        if(l==r){
            segTree[i] = {1,1,1,s[l],s[l]};
            return;
        }
        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1, l, mid, s);
        buildSegmentTree(2*i+2, mid+1, r, s);
        segTree[i] = merge(segTree[2*i+1], segTree[2*i+2], mid-l+1, r-mid);
        return;
    }
    void update(int i, int l, int r, int pos, char ch){
        if(l==r){
            segTree[i] = {1,1,1,ch, ch};
            return;
        }
        int mid = l+(r-l)/2;
        if(pos <= mid){
            update(2*i+1, l, mid, pos, ch);
        }
        else update(2*i+2, mid+1, r, pos, ch);
        segTree[i] = merge(segTree[2*i+1], segTree[2*i+2],mid-l+1, r-mid);
        return;
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.size();
        segTree.assign(4*n, Node());
        buildSegmentTree(0,0,n-1,s);
        int k = queryCharacters.size();
        vector<int> result(k);
        for(int i = 0; i < k; i++){
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            update(0,0,n-1,pos,ch);
            result[i] = segTree[0].maxLen;
        }
        return result;
    }
};