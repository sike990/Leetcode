class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s){
            if(ch == ')' || ch == '}' ||ch == ']'){
                if(st.empty())return false;
                else{

                    char up = st.top();
                    st.pop();
                    if(!((up == '(' && ch == ')') || (up == '[' && ch == ']') || (up == '{' && ch == '}')))return false;
                }

            }
            else {
                st.push(ch);
            }
        }

        return (st.size() > 0)?false:true;
    }
};