class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         vector<int> duplicates;
        
        for(int i=0;i<nums.size();i++)
        { 
            int indexOfElem = abs(nums[i]) - 1;
            nums[indexOfElem] = - nums[indexOfElem];
            
            if(nums[indexOfElem]>0)
                duplicates.push_back(indexOfElem+1);
            
        }
        return duplicates;
    }
};
