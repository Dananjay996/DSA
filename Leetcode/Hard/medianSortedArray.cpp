class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        int n=nums1.size(), m=nums2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i] > nums2[j]){
                answer.push_back(nums2[j]);
                j++;
            }else{
                answer.push_back(nums1[i]);
                i++;
            }
        }

        while(i<n){
            answer.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            answer.push_back(nums2[j]);
            j++;
        }

        if((n+m)%2){
            double ans = answer[(n+m)/2];
            return ans;
        }

        double ans  = (double(answer[(n+m)/2 - 1]) + double(answer[(n+m)/2]))/2;
        return ans;
    }
};