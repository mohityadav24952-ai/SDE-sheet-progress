class Solution {
public:
    string minWindow(string s, string t) {
         int n = s.length();
         int m = t.length();

         int hash[256]={0};
         int si= 0;
         int minl = INT_MAX;


         for(int i=0 ;i<m ; i++) hash[t[i]]++;

         int l = 0 ,r=0;
         int cnt = 0;

         while(r<n){

                if(hash[s[r]] > 0) cnt++ ;
                hash[s[r]]--;

                while(cnt == m){

                   if(r-l+1 < minl){
                     minl = r-l+1;
                     si = l;
                    
                   }

                     hash[s[l]]++;

                     if(hash[s[l]]>0) {
                        cnt--;
                        
                     }

                      l++; 
                     
                  

                }
            r++;
         }
        

         return minl == INT_MAX ? "" : s.substr(si, minl);
    }
};