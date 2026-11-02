class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();

        int l=0 , r=0;
        int ans =0;
        int len =0;

        vector<int>last(256,-1);

        while(r<n){

            if(last[s[r]] != -1){
                if(last[s[r]] >= l)
                {l = last[s[r]]+1;}
            }

             last[s[r]] = r;


             len = r-l+1;

             ans = max(ans,len);

             r++;

            
        }

        return ans;
    }
};