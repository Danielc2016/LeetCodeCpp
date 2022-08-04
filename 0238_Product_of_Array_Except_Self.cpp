class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n_size = nums.size();
        //if( n_size < 3) return nums;
        // do left
        vector<int> res(n_size);
        res[0] = 1;
        for( int i = 1; i < n_size; ++i)
        {
            res[i] = nums[i-1] * res[i-1];
        }
        // do right;
        int prev = 1;
        for( int j = n_size-2; j >=0; j--)
        {
            prev = nums[j+1] * prev;
            res[j] = res[j] * prev; 
        }
        return res;
    }
};
