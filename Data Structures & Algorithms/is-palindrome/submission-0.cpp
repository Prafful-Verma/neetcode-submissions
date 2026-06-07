class Solution {
public:
    char toLowerIfUpper(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A'); // convert to lowercase
        }
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        return c;
        return 'F';
    }
    bool isPalindrome(string s) {

        string hash1, hash2;
        int size = s.size();
        for (int i=1; i<=size; i++) {
            char start = toLowerIfUpper(s[i-1]);
            char end = toLowerIfUpper(s[size-i]);
            if (start != 'F') hash1+=start;
            if(end != 'F') hash2 +=end;
        }
        return hash1 == hash2;
    }
};
