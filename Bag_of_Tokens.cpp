class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1,ans=0;
        while(i<=j){
            if(tokens[i]<=power){
                ans++;
                power-=tokens[i];
                i++;
            }
            else if(ans > 0 && i!=j){
                power+=tokens[j];
                ans--;
                j--;
            }
            else 
                break;
        }
        
        return ans;
    }
};
