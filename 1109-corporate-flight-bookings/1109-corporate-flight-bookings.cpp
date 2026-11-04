class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        int m = bookings.size();
        

        int l=0 , r=0,s=0;

        vector<int>diff(n,0);

        for(int i=0 ;i<m ; i++){

             l = bookings[i][0];
              r = bookings[i][1];
               s = bookings[i][2];

             if(l<=n)  diff[l-1]+=s;

               if(r<n) diff[r]-=s;
        }

        for(int i=1;i<n ; i++){
            diff[i] += diff[i-1];
        }

        return diff;
    }
};