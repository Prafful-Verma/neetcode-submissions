class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> lb(n), rb(n);
        stack<int> st;

        // Left boundary (previous smaller element)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            lb[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // clear stack for right boundary
        while (!st.empty()) st.pop();

        // Right boundary (next smaller element)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            rb[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int ans = 0;

        // compute max area
        for (int i = 0; i < n; i++) {
            int width = rb[i] - lb[i] - 1;
            int area = width * heights[i];
            ans = max(ans, area);
        }

        return ans;
    }
};
