class Solution {
public:
    int findSubarrays(vector<int>& nums, int k){
        unordered_map<int,int> m;
        int r=0, ans=0;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            while(m.size()>k){
                m[nums[r]]--;
                if(m[nums[r]]==0)
                    m.erase(nums[r]);
                r++;
            }
            ans+=i-r+1;
        }
        cout<<ans;
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return findSubarrays(nums,k) - findSubarrays(nums,k-1);
    }
};
