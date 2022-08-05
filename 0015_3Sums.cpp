class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //int i = 0, j = 1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = nums.size()-1;
        for(int i = 0; i < size - 1; ++i )
        {
            if(nums[i]>0)
                break;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int mid = i+1, right = size;
            while (mid < right) {
			int sum = nums[i] + nums[mid] + nums[right];
			if (sum < 0) {
				++mid;
			} else if (sum > 0) {
				--right;
			} else {
				res.push_back({nums[i], nums[mid], nums[right]});
				int last_mid = nums[mid], last_right = nums[right];
				// we have seen this number & combo before; skip
				while (mid < right && nums[mid] == last_mid) ++mid;
				while (mid < right && nums[right] == last_right) --right;
			}
		}
        }
        return res;
    }
};
