class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());

        long long int ans = 0,s=0,c=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==m)
                c++;
            
            while(c>=k){
                if(nums[s]==m)
                    c--;
                s++;
            }
            ans+=s;
        }

        return ans;

    }
};
