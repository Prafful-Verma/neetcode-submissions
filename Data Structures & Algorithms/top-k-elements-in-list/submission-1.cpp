class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int size = nums.size();
        unordered_map<int, int> freq;
        if (size < 2) return nums;
        for (int x : nums) {
            freq[x]++;
        }
        sort(nums.begin(), nums.end(),
            [&](int a, int b) {
                if (freq[a] == freq[b])
                    return a < b;
                return freq[a] < freq[b];
            });
        for(int i=size-1; i>=0; i--) {
            if (ans.size() >= k) break;
            if (i==0){
                ans.push_back(nums[i]);
                break;
            }
            if (nums[i]!=nums[i-1]){
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};
