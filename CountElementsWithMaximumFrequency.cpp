class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        int mf=0;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            mf = max(mf, m[nums[i]]);
        }

        int ans=0;
        for(int i=0; i<m.size(); i++){
            if(m[i]==mf)
                ans+=mf;
        }

        return ans;
    }
};
