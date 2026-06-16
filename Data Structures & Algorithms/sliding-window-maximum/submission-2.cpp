class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int _max = INT_MIN;
        int n = nums.size();
        for (int i = 0; i <= n - k; i++) {
            _max = INT_MIN;
            if (i > 0 && nums[i - 1] == _max) {
                ans.push_back(_max);
                continue;
            }
            for (int j = i; j < k + i; j++) {
                _max = max(_max, nums[j]);
            }
            ans.push_back(_max);
        }
        return ans;
    }
};
