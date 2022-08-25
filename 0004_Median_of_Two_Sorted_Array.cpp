class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        if( (n+m)%2 ) return kthElement(nums1, nums2, n, m, (n+m+1)/2);
        
        int a = kthElement(nums1, nums2, n, m, (n+m)/2);
        int b = kthElement(nums1, nums2, n, m, (n+m)/2 + 1);

        return (a + b) / 2.0 ;
    }

    double kthElement(vector<int>& nums1, vector<int>& nums2,
                      int n, int m, int k)
    {
        int low = max(0, k-m), high = min(n, k);
        int ind, ind2;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int x = mid, y = k - mid;
            
            // Take care of out of bound vectors
            int Aright = (x > 0) ? nums1[x-1] : INT_MIN;
            int Bright = (y > 0) ? nums2[y-1] : INT_MIN;
            int Aleft = (x+1 <= n) ? nums1[x] : INT_MAX;
            int Bleft = (y+1 <= m) ? nums2[y] : INT_MAX;
            
            if(Aright <= Bleft && Bright <= Aleft)
            {
                ind = x, ind2 = y;
                break;
            }
            else if( Aright > Bleft )
            {
                high = mid - 1;
            }
            else
            {
                low = mid +1;
            }
        }
        int ans;
        if(ind <= n)
        {
            int a = (ind > 0) ? nums1[ind - 1] : INT_MIN;
            int b = (ind2 > 0) ? nums2[ ind2 - 1] : INT_MIN;
            return max(a, b);
        }
        return nums2[ ind2 - 1];
    }
};
