class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(points.empty())
            return 0;

        sort(points.begin(), points.end(), [] (auto &p1, auto&p2) {
            return p1[1] < p2[1];
        });
 
        int val = points[0][1], arrows = 1;
        
        for(int i=0; i<points.size(); i++){
            if(points[i][0]<=val)
                continue;
            arrows++;
            val = points[i][1];
        }
        
        return arrows;
    }
};
