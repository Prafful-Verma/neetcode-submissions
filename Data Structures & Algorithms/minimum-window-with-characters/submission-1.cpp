class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size() || t=="") return "";
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char c : t)
            need[c]++;
        int required = need.size();
        int formed = 0;

        int left = 0;
        int bestLen = INT_MAX;
        int bestStart = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            window[c]++;

            if (need.count(c) &&
                window[c] == need[c]) {
                formed++;
            }

            while (formed == required) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestStart = left;
                }

                char remove = s[left];
                window[remove]--;

                if (need.count(remove) &&
                    window[remove] < need[remove]) {
                    formed--;
                }

                left++;
            }
        }

        return bestLen == INT_MAX
                   ? ""
                   : s.substr(bestStart, bestLen);
    }
};