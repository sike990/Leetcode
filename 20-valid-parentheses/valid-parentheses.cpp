class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        st.push(s[0]);

        for(int i = 1; i < s.length() ; i++){

            if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(st.empty())return false;
                
                char tel = st.top();
                st.pop();
                if((s[i] == ')' && tel != '(') || (s[i] == '}' && tel != '{') || (s[i] == ']' && tel != '[')){
                    return false;
                }
            
            }
            else{
                st.push(s[i]);
            }
            

        }

        return (st.size() > 0)?false:true;
    }
};