class Solution {
public:
    bool allzero(vector<int>&counter){
        for(int i : counter){
            if(i!=0) return false ;
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<int>counter(26,0);

        for(int i=0 ; i<n ; i++){
            char ch = p[i];
            counter[ch-'a']++;
        }

        int i=0 ; int j=0; vector<int>res;

        while(j<m){
            counter[s[j]-'a']--;

            if(j-i+1==n){

                if(allzero(counter)) res.push_back(i);
            

            counter[s[i]-'a']++;
            i++;
            }
            j++;
        }

        return res ;

    }
};