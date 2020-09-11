class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int max_so_far=nums[0];
        int min_so_far=nums[0];
        // int cuurent=nums[0];
        
        int result=max_so_far;
        
        int i=1;
        while(i<nums.size())
        {
            int curr = nums[i];
            int temp_max = max(curr,max(max_so_far*curr,min_so_far*curr));
            min_so_far = min(curr,min(max_so_far*curr,min_so_far*curr));
            max_so_far=temp_max;
            result=max(max_so_far,result);
            i++;
        }
        
        return result;
        
        
    }
};