class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(int asteroid : asteroids) {

            // BHAIII MANKE CHALO CURRENT ASTEROID ABHI TAK ZINDA HAI
            bool destroyed = false;

            // Collision TABHI hoga:
            // Stack Top -> Positive
            // Current   -> Negative

            while(!st.empty() && st.top() > 0 && asteroid < 0) {

                // Current bada hai -> Stack wala udd jayega
                if(abs(asteroid) > st.top()) {
                    st.pop();
                }

                // Dono same size ke -> Dono udd jao
                else if(abs(asteroid) == st.top()) {
                    st.pop();
                    destroyed = true;
                    break;
                }

                // Stack wala bada hai -> Current udd gaya
                else {
                    destroyed = true;
                    break;
                }
            }

            // Agar current asteroid bach gaya to stack me daal do
            if(!destroyed) {
                st.push(asteroid);
            }
        }

        // Stack se answer banao
        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};