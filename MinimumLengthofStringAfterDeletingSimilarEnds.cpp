class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.length()-1;
        string temp="";
        while(i<j){
            if(s[i]==s[j]){
                char t = s[i];
                while(s[i]==t && i<s.length())
                    i++;
                while(s[j]==t && j>0)
                    j--;
            }else
                break;
        }
        if(i>j)
            return 0;
        return (j-i)+1;
    }
};
