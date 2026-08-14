class Solution {
public:


    int maximumLengthSubstring(string s) {
            int n = s.length();
            int l=0; int r=0;
            unordered_map<char,int>mp;
            int ans = 0;

            while(r<n){

                mp[s[r]]++;

                while(mp[s[r]]>2){

                    
                    mp[s[l]]--;
                    l++;

                     
                    
                }
                ans = max(ans,r-l+1);
             r++;
            }
        return ans;
    }
};