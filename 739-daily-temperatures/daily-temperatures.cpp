class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n = temp.size();
        stack<int> st;
        st.emplace(n-1);
        vector<int> ans(n , 0);
        for(int i = n-2 ; i >= 0 ; i--){

            //if(!st.empty()){
                int curr = temp[i];
                while(!st.empty() && temp[st.top()] <= curr){
                    st.pop();
                }
                if(!st.empty()){
                    int index = st.top();
                    ans[i] = index - i;
                }
                st.emplace(i);
            //}
        }

        return ans;
    }
};