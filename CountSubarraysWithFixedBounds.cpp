class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long  s=-1,e=-1, ans=0, b=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==maxK)
                e=i;
            if(nums[i]==minK)
                s=i;
            if(nums[i]>maxK || nums[i]<minK){
                b=i;
            }
           
            ans+=max(0L, min(s,e)-b);
        }
        return ans;
    }
};
