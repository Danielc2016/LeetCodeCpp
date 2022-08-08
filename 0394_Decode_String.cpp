class Solution {
public:
    string decodeString(string s) {
        int lengthS = s.length();
        string str = "";
        //int rep = 0;
        stack<char> st;
        for(int i = 0; i < lengthS; i++)
        {
            if(s[i] != ']')
                st.push(s[i]);
            else
            {
                string temp = "";
                string num = "";
                while(st.top() != '[')
                {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop(); // pop '['
                while(!st.empty() && isdigit(st.top()))
                {
                    num = st.top() + num;
                    st.pop();
                }
                int rep = stoi(num);
                while(rep--)
                {
                    for(int p = 0; p < temp.size() ; p++)
                    {
                        st.push(temp[p]);
                    }
                    // st.push(temp); can't just push string
                }
            }
        }
        while(!st.empty())
        {
            str = st.top() + str;
            st.pop();
        }
        return str;

    }
};
