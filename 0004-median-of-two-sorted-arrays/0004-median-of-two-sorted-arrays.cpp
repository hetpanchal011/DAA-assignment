class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        // Always binary search on the smaller array
        if (n > m) return findMedianSortedArrays(nums2, nums1);
        
        int low = 0, high = n;
        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int leftTotal = (n + m + 1) / 2;
            int partition2 = leftTotal - partition1;
            
            // Boundary values with sentinels for edge cases
            int left1  = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int right1 = (partition1 == n) ? INT_MAX : nums1[partition1];
            
            int left2  = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int right2 = (partition2 == m) ? INT_MAX : nums2[partition2];
            
            // Adjust search space
            if (left1 > right2) {
                high = partition1 - 1; // Too many elements from nums1
            } 
            else if (left2 > right1) {
                low = partition1 + 1;  // Too few elements from nums1
            } 
            else {
                // Correct partition found
                if ((n + m) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    return max(left1, left2);
                }
            }
        }
        return -1.0; 
    }
};