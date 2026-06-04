class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> m;
        vector<int> ans;
        int size = nums.size();
        for(int i=0; i<size; i++) {
            if (m.find(target-nums[i]) == m.end()) {
                m[nums[i]] = i;
            } else {
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
        }
    }
};
