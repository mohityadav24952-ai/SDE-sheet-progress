class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char> s1;
        stack<char> s2;

        int n1 = s.length();
        int n2 = t.length();

        // process string s
        for (int i = 0; i < n1; i++) {

            if (s[i] == '#') {

                // backspace -> remove previous character
                if (!s1.empty())
                    s1.pop();
            }
            else {
                s1.push(s[i]);
            }
        }

        // process string t
        for (int i = 0; i < n2; i++) {

            if (t[i] == '#') {

                // backspace -> remove previous character
                if (!s2.empty())
                    s2.pop();
            }
            else {
                s2.push(t[i]);
            }
        }

        // if sizes are different, strings can't be equal
        if (s1.size() != s2.size())
            return false;

        // compare characters from top
        while (!s1.empty() && !s2.empty()) {

            if (s1.top() != s2.top())
                return false;

            s1.pop();
            s2.pop();
        }

        return true;
    }
};