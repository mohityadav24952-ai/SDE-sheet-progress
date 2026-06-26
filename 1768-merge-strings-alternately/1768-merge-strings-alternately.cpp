class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        int l=0; int r=0;
        int c = 1 ;
        string s="";

        while(l<n1 && r<n2){
            if(c>0){
                s += word1[l];
                l++ ;              
            }
            else{
                s += word2[r];
                r++ ;           
            }
             c *= -1 ;
        }

        while(l<n1){
            s += word1[l] ;
            l++ ;
        }

         while(r<n2){
            s += word2[r] ;
            r++ ;
        }

        return s;
        
    }
};