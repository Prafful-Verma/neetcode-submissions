class Solution {
   public:
    bool isMatch(char c1, char c2) {
        if (c1 == '{' && c2 == '}') return true;
        if (c1 == '[' && c2 == ']') return true;
        if (c1 == '(' && c2 == ')') return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '{' || c == '[' || c == '(')
                st.push(c);
            else {
                if (st.empty()) return false;
                char ch = st.top();
                st.pop();
                if (!isMatch(ch, c)) return false;
            }
        }
        return st.empty();
    }
};
