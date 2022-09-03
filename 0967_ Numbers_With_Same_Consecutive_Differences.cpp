class Solution {
public:
    //Back Tracking
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> res;
        string path = "";
        for(int i = 1; i <= 9; i++)
        {
            path.push_back(i + '0');
            Tracking(n, k, i, path, res);
            path.pop_back();
        }
        return res;
    }
    
    void Tracking(int n, int k,
                  int curr, string& path, vector<int>& res)
    {
        if(path.length() == n)
        {
            int pt = stoi(path);
            res.push_back(pt);
            return;
        }
        if(curr + k <= 9)
        {
            int j = curr + k;
            path.push_back(j + '0');
            Tracking(n, k, j, path, res);
            path.pop_back();
        }
        if(curr - k >=0 && k != 0)
        {
            int j = curr - k;
            path.push_back(j + '0');
            Tracking(n, k, j, path, res);
            path.pop_back();
        }
    }
};
