class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // concat?=> no, it takes n already
        // BS... what to find?
        vector<int> arr;

        for(int i=0; i<nums1.size(); i++) {
            arr.push_back(nums1[i]);
        }

        for(int i=0; i<nums2.size(); i++) {
            arr.push_back(nums2[i]);
        }

        sort(arr.begin(), arr.end());
        double median;
        if(arr.size()%2 == 1) {
            median = arr[arr.size()/2];
        } else {
            median = (arr[arr.size()/2-1] + arr[arr.size()/2])/2.0;
        }
        
        return median;
    }
};
