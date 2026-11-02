class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();

        int l=0 , r=0;
        int ans =0;
        int len =0;

        unordered_set<char>st;

        while(r<n){

            while(st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;               
            }

            st.insert(s[r]);

            len = r-l+1;

                     
            ans = max(ans,len);
            r++;
            

        }

        return ans;
    }
};