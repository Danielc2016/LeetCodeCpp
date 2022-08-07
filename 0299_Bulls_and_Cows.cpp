class Solution {
public:
    string getHint(string secret, string guess) {
        int countA = 0, countB = 0;
        unordered_map<char, int> st;
        string res = "";
        for(int i = 0; i < secret.size(); i++)
        {
            if(guess[i] == secret[i])
            {
                countA++;
            }
            else
            {
                st[secret[i]]++;
            }
        }
        for(int i = 0; i < guess.size(); i++)
        {
            if(st[guess[i]] > 0 && guess[i] != secret[i])
            {
                countB++;
                st[guess[i]]--;
            }
        }
        res = to_string(countA) + "A" + to_string(countB) + "B";
        return res;
    }
};
