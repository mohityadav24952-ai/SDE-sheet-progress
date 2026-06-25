class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int size = flowerbed.size();

        for(int i = 0; i < size; i++) {

            int left = 0;
            int right = 0;

            if(i > 0)
                left = flowerbed[i - 1];

            if(i < size - 1)
                right = flowerbed[i + 1];

            // current, left aur right sab empty hone chahiye
            if(flowerbed[i] == 0 && left == 0 && right == 0) {

                flowerbed[i] = 1;   // flower plant kar diya
                n--;

                if(n == 0)
                    return true;
            }
        }

        return n <= 0;
    }
};