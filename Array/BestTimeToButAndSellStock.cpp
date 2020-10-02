class Solution {
public:
    int maxProfit(vector<int>& arr, int fee) {
        int obsp = -arr[0]; // old buy state profit
        int ossp = 0; //old sell state profit
        
        for(int i=1;i<arr.size();i++)
        {
            int nbsp=0;
            int nssp=0;
            if(ossp - arr[i] > obsp){
                nbsp = ossp - arr[i];
            }else{
                nbsp = obsp;
            }
            if((obsp+arr[i])-fee > ossp)
            {
                nssp = (obsp +arr[i]) -fee;
            }else{
                nssp=ossp;
            }
            
            obsp = nbsp;
            ossp = nssp;
        }
        
        
        return ossp;
    }
};