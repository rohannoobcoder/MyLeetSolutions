class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        string ans="";
        vector<int>last(26,0);
        vector<int>count(26,0);
        
        for(int i=0;i<s.length();i++){
            last[s[i]-'a'] = i;
        }
        
        for(int i=0;i<s.length();i++){
            
            if(count[s[i]-'a']++ > 0){
                continue;
            }
            while(!ans.empty() && (ans.back() > s[i]) && i < last[ans.back()-'a']){
                count[ans.back()-'a']=0;
                ans.pop_back();
            }            
            
            ans.push_back(s[i]);
            
            
        }
        
        
        
        return ans;
        
        
    }
};