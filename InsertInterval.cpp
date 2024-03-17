class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        if(intervals.empty())
        {
            ans.push_back(newInterval);
            return ans;
        }
        
        int s=intervals[0][0],e=intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(e < intervals[i][0])
            {
                ans.push_back({s,e});
                s=intervals[i][0];
                e=intervals[i][1];
            }else{
                s= min(s, intervals[i][0]);
                e= max(e, intervals[i][1]);
            }
        }

        ans.push_back({s,e});

        return ans;
    }
};
