// class Solution {
// public:
//     int gcdOfOddEvenSums(int n) {
//         int sumo = 0;
//         int sume = 0 ;

//         for(int i=0 ; i<n ; i++){
//             sumo += (2*i) + 1 ;
//             sume += (2*i) + 2 ;
//         }
//         int ans = 0;

//         for(int i=1 ; i<=min(sumo,sume) ; i++){
//                 if(sumo%i ==0 && sume % i == 0) ans = i ;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};