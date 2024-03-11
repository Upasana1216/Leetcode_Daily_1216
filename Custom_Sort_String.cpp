class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> m;
        for(int i=0; i<order.size(); i++)
            m[order[i]]=0;
        
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i])!=m.end())
                m[s[i]]++;
        }
            
        string ans="";
        for(int i=0; i<order.size(); i++){
            ans.append(m[order[i]], order[i]);
        }
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i])==m.end())
                ans+=s[i];
        }
        return ans;
    }
};
