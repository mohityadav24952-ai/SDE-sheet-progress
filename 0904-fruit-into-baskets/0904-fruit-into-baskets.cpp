class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int l=0 ; int r=0 ; int maxl = 0;
        int n = fruits.size();
        while(r<n){
            mp[fruits[r]]++;

            if(mp.size() > 2){

                while(mp.size()>2){
                    mp[fruits[l]]--;
                    if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                    l++;
                }


            }

            if(mp.size()<=2){
                maxl = max(maxl , r-l+1);
            }

            r++;
        }

        return maxl ;

    }
};