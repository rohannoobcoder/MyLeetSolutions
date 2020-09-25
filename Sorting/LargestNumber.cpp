class Solution {
public:
    
    bool compare(string s1,string s2)
    {
            return s1>s2;
    }
    
    string largestNumber(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                string temp1=to_string(nums[i])+to_string(nums[j]);
                string temp2= to_string(nums[j])+to_string(nums[i]);
                
                if(!compare(temp1,temp2))
                {
                    swap(nums[i],nums[j]);
                }
            }
        }
        
        string to_return="";
        for(int i=0;i<nums.size();i++)
        {
            to_return+=to_string(nums[i]);
        }
        
        if(to_return[0]=='0')
        {
                return "0";
        }
        
        return to_return;
        
    }
};