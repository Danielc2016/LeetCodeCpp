class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for( auto str : strs)
        {
            int len = str.length();
            res += to_string(len) + "#" + str;
        }
        return res;
        
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int head = 0;
        while(head < s.length())
        {
            int pos = s.find_first_of('#', head);
            int len = stoi(s.substr(head, pos-head));
            head = pos + 1;
            res.push_back( s.substr(head, len) );
            head += len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));


// Chunk encoding
const int HEADER = 4;
class Codec {

private:
    string int2string( int num )
    {
        stringstream ss;
        ss << setw(HEADER) << setfill('0') << num;
        return ss.str();
    }
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs)
    {
        string res = ""; 
        for(auto s : strs)
        {
            int iLen = s.length();
            string sLen = int2string(iLen);
            res += (sLen + s);
        }
        return res;
    }
    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {
        vector<string> res;
        while(s.length() > 0)
        {
            string sLen = s.substr(0, HEADER);
            int iLen = stoi(sLen);
            s.erase(0, HEADER);
            string str = s.substr(0, iLen);
            s.erase(0, iLen);
            res.push_back(str);
        }
        return res;
    }
};

