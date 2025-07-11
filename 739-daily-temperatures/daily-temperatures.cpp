class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n = temp.size();
        stack<pair<int,int>> st;
        st.emplace(temp[n-1] , n-1);
        vector<int> ans(n , 0);
        for(int i = n-2 ; i >= 0 ; i--){

            //if(!st.empty()){
                int curr = temp[i];
                while(!st.empty() && st.top().first <= curr){
                    st.pop();
                }
                if(!st.empty()){
                    int index = st.top().second;
                    ans[i] = index - i;
                }
                st.emplace(curr , i);
            //}
        }

        return ans;
    }
};