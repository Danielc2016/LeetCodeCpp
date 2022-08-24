class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        //Bit solution
        int x = nums.size(); //array should contain n
        for(int i = 0; i < nums.size(); i++)
        {
            x = ( x ^ nums[i]);
            x = ( x ^ i);
        }
        return x;
    }
};
