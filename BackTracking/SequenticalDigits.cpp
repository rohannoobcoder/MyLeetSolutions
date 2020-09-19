class Solution {
public:
    void create(int low,int high,vector<int>&res,int num)
    {
        num = num*10 + (num%10) + 1;
        
        if(num>high) return;
        else if(num>=low && num<=high) res.push_back(num);
        
        if((num+1)%10!=0)create(low,high,res,num);
    }
    
    
    
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int>res;
        for(int i=1;i<9;i++)
        {
            create(low,high,res,i);
        }
        
        sort(res.begin(),res.end());
        
        
        return res;
        
    }
};