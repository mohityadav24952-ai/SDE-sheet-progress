class Solution {
public:

    struct cmp{

        bool operator()(pair<int,string> &a , pair<int,string> &b){

            // Agar dono words ki frequency same hai
            if(a.first == b.first){

                // Lexicographically chhota word "bada" treat hoga
                // Taki min heap me lexicographically bada word top pe aaye
                // Aur size > k hone par wahi pehle remove ho jaye.
                return a.second < b.second;
            }

            // Frequency kam hogi to uski priority zyada hogi
            // Yani min heap frequency ke basis pe banega.
            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> mpp;

        // Har word ki frequency count kar lo
        for(int i=0 ; i<words.size() ; i++){
            mpp[words[i]]++;
        }

        priority_queue<pair<int,string>,
                       vector<pair<int,string>>,
                       cmp> minh;

        // Heap me {frequency , word} store karenge
        for(auto it : mpp){

            minh.push({it.second,it.first});

            // Sirf top k elements hi rakhne hain
            if(minh.size() > k){
                minh.pop();
            }
        }

        vector<string> ans;

        // Heap se answer nikalo
        while(!minh.empty()){

            ans.push_back(minh.top().second);
            minh.pop();
        }

        // Heap se reverse order me answer milta hai
        reverse(ans.begin(),ans.end());

        return ans;
    }
};