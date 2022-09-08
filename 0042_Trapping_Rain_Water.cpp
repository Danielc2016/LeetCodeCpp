class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size == 0) return 0;
        int left = 0, right = size - 1;
        int maxLeft = height[left], maxRight = height[right];
        int res = 0;
        while(left <= right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] >= maxLeft)
                {
                    maxLeft = height[left];
                }
                res += maxLeft - height[left];
                left++;
            }
            else
            {
                if(height[right] >= maxRight)
                    maxRight = height[right];
                res += maxRight - height[right];
                right--;
            }
        }
        return res;
    }
};


/*
Brute force:
O(N^2)

Two Pointers:
O(N)
Space: O(1)

*/
