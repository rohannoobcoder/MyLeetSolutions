class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        if(nums.size()<3){
            return false;
        }
        
        vector<int>mintill(nums.size());
        
        int n = nums.size();
        
        mintill[0]=nums[0];
        
        for(int i=1;i<n;i++){
            
            mintill[i] = min(mintill[i-1],nums[i]);
            
           
            
        }
        
        
        stack<int>stk;
        
        for(int j=n-1;j>=0;j--){
            
                if(nums[j] > mintill[j]){

                    while(!stk.empty() && mintill[j] >= stk.top() ){
                        stk.pop();
                    }

                    if(!stk.empty() && nums[j] > stk.top())
                    {
                        return true;
                    }               

                    stk.push(nums[j]);

                }
            }
            
            
        
        
        
    return false;
        
    }
};