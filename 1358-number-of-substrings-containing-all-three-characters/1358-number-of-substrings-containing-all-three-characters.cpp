class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.length();

        int cnt = 0;

        // Last index jaha a, b, c dikhe the
        // Initially kisi bhi character ko nhi dekha
        int lastSeen[3] = {-1, -1, -1};

        for (int i = 0; i < n; i++) {

            // Current character ka latest index update krdo
            lastSeen[s[i] - 'a'] = i;

            // Agar a, b, c teeno atleast ek baar mil chuke hain
            if (lastSeen[0] != -1 &&
                lastSeen[1] != -1 &&
                lastSeen[2] != -1) {

                /*
                    Teeno me se jo sabse pehle aaya tha (minimum index)

                    Usse pehle ya uske equal jitne bhi starting points honge,
                    un sabse substring banaoge to usme a,b,c teeno aa jayenge.

                    Count = minIndex + 1
                */

                cnt += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }

        return cnt;
    }
};