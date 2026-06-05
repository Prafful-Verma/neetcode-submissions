class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[27] = {0};
        for (char c : s) {
            arr[c-'a']++;
        }
        for (char c : t) {
            arr[c-'a']--;
        }
        for (int i : arr) {
            if (i != 0) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        set<int> s;
        for (int i=0; i<strs.size(); i++) {
            if (s.find(i) != s.end()) {
                continue;
            }
            vector<string> _ans;
            _ans.push_back(strs[i]);
            for (int j=i+1; j<strs.size(); j++) {
                bool isAna = isAnagram(strs[i], strs[j]);
                if (isAna){
                    s.insert(j);
                    _ans.push_back(strs[j]);
                } 
            }
            ans.push_back(_ans);
        }
        return ans;
    }
};
