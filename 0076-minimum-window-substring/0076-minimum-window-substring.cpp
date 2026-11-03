class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        int l=0;
        int r=0;
        int cnt =0;
        int minlen =INT_MAX;

        int startind =-1;

        unordered_map<char,int>st;

        for(auto ch:t){
            st[ch]++;
        }

        while(r<m){

            if(st.find(s[r])!=st.end()){

                if(st[s[r]]>0){
                    cnt++;
                }

                st[s[r]]--;
            }

            

            while(cnt == t.length()){
                
                if(st.find(s[l])!=st.end()){
                      

                        st[s[l]]++;

                        if(st[s[l]]>0){
                            cnt--; // Agar required count 0 se bada ho gaya, tabhi cnt kam karo
                        }
                }

                if(minlen>r-l+1){
                minlen = r-l+1;
                startind = l;
            }


                l++;
            }


         
            r++;

        }

        if(startind == -1) return "";
        return s.substr(startind,minlen);
    }
};