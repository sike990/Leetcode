class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> s = {"*","/","-","+"};
        for(string c : tokens){
            if(s.find(c) != s.end()){
                int el2 = st.top();
                st.pop();
                int el1 = st.top();
                st.pop();
                int curr = 0;
                if(c == "*"){
                    curr = el1*el2;
                }
                else if(c == "+"){
                    curr = el1+el2;
                }
                else if(c == "-"){
                    curr = el1-el2;
                }
                else{
                    curr = el1/el2;
                }
                st.push(curr);
            }
            else{
                int num = stoi(c);
                st.push(num);
            }

        }
        return st.top();
    }
};