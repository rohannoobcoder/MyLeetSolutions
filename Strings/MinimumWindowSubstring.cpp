class Solution {
public:
    string minWindow(string s, string t) {
        
        int count=0;
        int start=0;
        int start_index=-1;
        int min_len=INT_MAX;
        vector<int>s_map(256,0);
        vector<int>t_map(256,0);
        
        
        
        
        for(int i=0;i<t.length();i++)
        {
            t_map[t[i]]++;
        }
        
        for(int i=0;i<s.length();i++)
        {
            s_map[s[i]]++;
            
            if(t_map[s[i]]!=0 && s_map[s[i]]<=t_map[s[i]])
            {
                count++;
            }
            
            if(count==t.length())
            {
                while(t_map[s[start]]==0 || s_map[s[start]]>t_map[s[start]])
                {
                    if(s_map[s[start]]>t_map[s[start]])
                    {
                        s_map[s[start]]--;
                    }
                    start++;
                    
                }
                
                int len_window=i-start+1;
                
                if(len_window<min_len)
                {
                    min_len=len_window;
                    start_index=start;
                    
                }
            }
        }
        if(start_index==-1)
        {
            return "";
        }
        
        return s.substr(start_index,min_len);
        
        
    }
};