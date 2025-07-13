class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int fir = 0 , sec = 0;
        unordered_set<char> st;
        int n = s.length();
        int len = 0;
        for(; fir < n && sec < n ;){

            if(st.find(s[sec]) == st.end()){
                st.insert(s[sec]);
            }
            else{
                char tocross = s[sec];
                while(s[fir] != tocross){
                    st.erase(s[fir]);
                    fir++;
                }
                fir++;
            }
            len = max((sec-fir+1) , len);
            sec++;
        }
        return len;
    }
};