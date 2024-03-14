class Solution {
public:
    int helper(vector<int>& nums, int goal){
        int j=0, preSum=0, ans=0;
        for(int i=0; i<nums.size(); i++){
            preSum+=nums[i];
            
            while(j<=i && preSum>goal)
            {
                preSum-=nums[j];
                j++;
            }
            ans+= i-j+1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal-1);
    }
};
