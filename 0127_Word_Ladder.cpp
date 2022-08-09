//Graph BFS

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // A set to keep track of unvisited
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord)==st.end()) return 0;
        queue<string> q; // use a queue to perform BFS
        q.push(beginWord);
        st.erase(beginWord);
        int res = 1; //starts from begin
        int wsize = beginWord.length();
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                auto word = q.front();
                q.pop();
                if(word == endWord)
                    return res;
                for(int j = 0; j < wsize; j++)
                {
                    char temp = word[j];
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        word[j] = c;
                        if(st.find(word)!=st.end())
                        {
                            st.erase(word);
                            q.push(word);
                        }
                    }
                    word[j] = temp;
                }
            }
            res++;
        }
        return 0;
    }
};
