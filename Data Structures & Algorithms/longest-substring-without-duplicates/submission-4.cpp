class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ss;
        int i=0,j=0, n=s.size(), max_ans = 0;
        while(j<n) {
            while(ss.count(s[j])){
                ss.erase(s[i]);
                i++;
            }
            ss.insert(s[j]);
            max_ans = max(max_ans, j-i+1);
            j++;
        }
        return max_ans;
    }
};
