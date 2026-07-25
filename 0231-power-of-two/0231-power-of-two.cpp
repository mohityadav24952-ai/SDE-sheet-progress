class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0 ;
        while(n>0){
             cnt ++ ;
           n = ( n & n-1);
          
        }
        return cnt ;
    }

    bool isPowerOfTwo(int n) {
        if ( hammingWeight( n) == 1) return true ;
        else return false ;
    }
};