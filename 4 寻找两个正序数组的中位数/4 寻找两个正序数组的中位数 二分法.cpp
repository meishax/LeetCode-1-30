class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m>n)//保证第一个始终不能比第二个长
        {
            return findMedianSortedArrays(nums2,nums1);

        }
        
        int lmax1,lmax2,rmin1,rmin2;//左边最大的，右边最小的

        int c1,c2;//切割点
        int left=0,right=2*m;//最左边的位置，最右边的位置，补了双倍（补#）
        while(left <= right)
        {
            c1=(left+right)/2;
            c2=m+n-c1;

            lmax1 = (c1 == 0) ? INT_MIN : nums1[(c1-1)/2];
            rmin1 = (c1 == 2*m) ? INT_MAX : nums1[c1/2];

            lmax2 = (c2 == 0) ? INT_MIN : nums2[(c2-1)/2];
            rmin2 = (c2 == 2*n) ? INT_MAX : nums2[c2/2];

            if(lmax1>rmin2)
            {
                right = c1-1;

            }
            else if(lmax2>rmin1)
            {
                left = c1+1;

            }
            else
            {
                break;
            }
        }
        return double(max(lmax1,lmax2)+min(rmin1,rmin2))/2;

    }
};