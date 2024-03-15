class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int lp=1,rp = 1;
        vector<int> ans(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            ans[i]=lp;
            lp *= nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]*=rp;
            rp *=nums[i];
            
        }

        return ans;

    }
};
