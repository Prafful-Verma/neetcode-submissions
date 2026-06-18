class Solution {
public:
    int operate(int a, int b, string op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b; // assume b != 0 in RPN
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (string &t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();

                int res = operate(a, b, t);
                s.push(res);
            } 
            else {
                s.push(stoi(t));
            }
        }

        return s.top();
    }
};