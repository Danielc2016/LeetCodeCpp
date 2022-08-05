class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int left = 0, right = size-1;
        vector<int> ans;
        while(left < right)
        {
            int sum = numbers[left] + numbers[right];
            if( sum < target )
                left++;
            else if(sum > target)
                right--;
            else
            {
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }   
        }
        return {};
    }
};
