class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //Bottom up
        int target = 0;
        for(auto& e : nums)
            target += e;
        if(target % 2)
            return false;
        target = target / 2;
        int n = nums.size();
        unordered_set<int> s;
        s.insert(nums[n-1]);
        s.insert(0);
        for(int i = n-2; i >=0; i--)
        {
            unordered_set<int> temp = s;
            for(auto& t : s)
            {
                if(target == t + nums[i])
                    return true;
                temp.insert(t + nums[i]);
            }
            s = temp;
        }
        return s.count(target);
    }
};
