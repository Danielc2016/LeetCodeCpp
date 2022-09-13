class Solution {
private:
    string baseUrl = "http://tinyurl.com/";
    unordered_map<string, string> enc;
    unordered_map<string, string> dec;
public:

    Solution()
    {
        enc.clear();
        dec.clear();
        srand(time(0));
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if( enc.count(longUrl) )
            return baseUrl + enc[longUrl];
        string code = "";
        while(true)
        {
            for(int i = 0; i < 6; i++)
            {
                code += char( rand() % 62 );
            }
            if( !dec.count(code) )
                break;
            code = "";
        }
        enc[longUrl] = code;
        dec[code] = longUrl;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return dec[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
