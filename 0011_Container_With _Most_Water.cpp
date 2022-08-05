class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0, right = size-1;
        //int left_h = height[left], right_h = height[right];
        int maxArea = (right - left) * min(height[left], height[right]);
        while(left < right)
        {
            if(height[left] < height[right])
                left++;
            else if(height[left] > height[right])
                right--;
            else
            {
                if(height[left+1] > height[right-1])
                    right--;
                else
                    left++;
            }
            maxArea = max( maxArea, (right - left) * min(height[left], height[right]));
        }
        return maxArea;
    }
};
