// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n)
    {
        int low = 1, high = n, mid;
        while( low < high )
        {
            mid = low + (high -low)/2;
            if(isBadVersion(mid) )
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

/*

0 , 1, 2, 3, 4,   5
low               high

mid = low + (high -low)/2

isBadVersion(mid):
    high = mid -1
!isBadVersion(mid)
    low = mid + 1

while( low < high )

*/
