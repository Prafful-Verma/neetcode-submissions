class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n<2) return n;
        int max_ans = 0;
        for(int i=0; i<n; i++) {
            unordered_set<char> ss;
            int ans = 0;
            for(int j=i; j<n; j++) {
                if (ss.count(s[j])){
                    break;
                }
                ss.insert(s[j]);
                ans++;
                max_ans = max(ans, max_ans);
            }
        }
        return max_ans;
    }
};
