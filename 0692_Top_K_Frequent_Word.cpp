class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        typedef pair<string, int> pr;
        unordered_map<string, int> word_map;
        vector<string> res;
        struct comp{
          bool operator() (const pr& a, const pr& b)
          {
              if(a.second == b.second)
                  return a.first < b.first;
              else
                  return a.second > b.second;
          }
        };
        priority_queue< pr, vector<pr>, comp> pq;
        
        for( auto word : words)
        {
            word_map[word]++;
        }
        
        for( auto i : word_map)
        {
            int count = i.second;
            string word = i.first;
            pq.push(make_pair(word, count));
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        while(k--)
        {
            res.insert(res.begin(), pq.top().first);
            pq.pop();
        }
        return res;
        
    }
};
