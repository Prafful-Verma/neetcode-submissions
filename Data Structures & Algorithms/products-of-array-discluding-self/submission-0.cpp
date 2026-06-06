class Solution {
   public:
    void printArr(vector<int>& nums) {
        for (int i : nums) cout << i << '-';
        cout << endl;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int allProd = 1;
        int zeroIdx = -1;
        int size = nums.size();
        vector<int> ans;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                if (zeroIdx != -1) {
                    vector<int> _ans(size);
                    return _ans;
                } else
                    zeroIdx = i;
            } else {
                allProd *= nums[i];
            }
        }
        printArr(ans);
        for (int i : nums) {
            if (zeroIdx == -1)
                ans.push_back(allProd / i);
            else {
                if (i == 0) {
                    ans.push_back(allProd);
                } else {
                    ans.push_back(0);
                }
            }
        }
        return ans;
    }
};
