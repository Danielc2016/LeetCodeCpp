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


//Recursion Approach
class Solution {
public:
    string decodeString(string s) {
        int start = 0;
        string str = buildString(start, s);
        return str;
    }
    string buildString(int& i, string s)
    {
        string res = "";
        //string nextIt = "";
        int num = 0;
        for( ; i < s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i] == '[')
            {
                //TODO
                string nextIt = buildString(++i, s);
                for(;num>0;num--) res+=nextIt;
            }
            else if(s[i] == ']')
            {
                return res;
            }
            else
            {
                res += s[i];
            }
        }
        return res;
    }
};
