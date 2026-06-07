class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> fill;
        int ans = 1;
        if (nums.size()==0) return 0;
        for(int i : nums) {
            fill.insert(i);
        }
        for (int i : fill) {
            int count =1;
            if (fill.count(i-1)) continue;
            int j=i+1;
            while(fill.count(j)) {
                j++;
                count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
