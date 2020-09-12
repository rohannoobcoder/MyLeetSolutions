class Solution {
public:
    void backtrack(vector<vector<int>>&res,vector<int>temp,int current_sum,int  target_sum,int index,int len)
    {
        if(len==0 && current_sum==target_sum)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=index;i<=9;i++)
        {
            temp.push_back(i);
            backtrack(res,temp,current_sum+i,target_sum,i+1,len-1);
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>res;
        
        vector<int>temp;
        
        if(k*9<n)
        {
            return res;
        }
        
        backtrack(res,temp,0,n,1,k);
        
        
        return res;
        
    }
};