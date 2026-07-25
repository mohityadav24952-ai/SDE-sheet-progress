class Solution {
public:
    int maxProduct(int n) {
        int p = 1;
        int ans = 0;
        int maxe = 0;
        int smax = 0 ;

        
        int t = n ;
        while(t){

            int d = t%10 ;
             
             if(d>=maxe){
                smax = maxe ;
                maxe = d ;
             }

             else if (d>smax){
                smax = d ;
             }

             t = t/10;
        }
        return maxe*smax ;

    }
};