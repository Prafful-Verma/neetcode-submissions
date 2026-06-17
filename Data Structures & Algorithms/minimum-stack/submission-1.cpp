class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    void push(int val) {
        st.push(val);

        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (st.empty()) return;

        if (st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }

    int top() {
        if (st.empty()) return -1;
        return st.top();
    }

    int getMin() {
        if (minSt.empty()) return -1;
        return minSt.top();
    }

    bool empty() {
        return st.empty();
    }
};
