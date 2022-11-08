class TimeMap {
public:
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if( mp.find(key) != mp.end() )
        {
            int left = 0, right = mp[key].size();
            int mid = 0;
            auto& m = mp[key];
            while(left < right)
            {
                mid = left + (right - left) /2;
                if( timestamp < m[mid].first )
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            if( left > 0 && left <= mp[key].size() )
                return m[left-1].second;
            else
                return "";
        }
        else
        {
            return "";
        }
        
    }
private:
    unordered_map<string, vector<pair<int, string>>> mp;
};

/*
store: hash-map

1, 2, 4, 6, 9 ,10

target 7


5, 10, 15, 20, 35

find: hash-map + binary search




*/


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
