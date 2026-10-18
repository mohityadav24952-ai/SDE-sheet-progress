class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();

        if(m!=n) return false;

       unordered_map<char,int>mp;



    for( auto c : s){
        mp[c]++;
    }

    for(auto c : t){
        mp[c]--;
    }

    for(auto c : mp){
        if((c.second)!=0) return false;
    }

    return true;



    }
};