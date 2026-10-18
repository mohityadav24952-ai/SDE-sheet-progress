class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();

        if(m!=n) return false;

        vector<int>v(26,0);

        for(int i=0 ; i<m ; i++){
            v[s[i]-'a']++;
        }

        
        for(int i=0 ; i<n ; i++){
            v[t[i]-'a']--;
        }

        for(int i=0 ;i<26 ;i++){
            if(v[i]!=0) return false;
        }


        return true;


    }
};