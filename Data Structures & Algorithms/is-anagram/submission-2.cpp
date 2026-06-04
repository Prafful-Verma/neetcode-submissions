class Solution {
public:
    void printArr(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

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
};
