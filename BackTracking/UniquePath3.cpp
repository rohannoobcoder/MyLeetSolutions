class Solution {
public:
    
    int paths=0;
    void createme(vector<vector<int>>&grid,int i,int j,int visited,int totalsquares)
    {
        if(i<0 or j<0 or i>grid.size()-1 or j>grid[0].size()-1 or grid[i][j]==-1)
        {
            return;
        }
        if(grid[i][j]==2)
        {
            if(totalsquares==visited)
            {
            paths++;
            }
           
            return;
        }
        grid[i][j]=-1;
        createme(grid,i+1,j,visited+1,totalsquares);
        createme(grid,i,j+1,visited+1,totalsquares);
        createme(grid,i-1,j,visited+1,totalsquares);
        createme(grid,i,j-1,visited+1,totalsquares);
        grid[i][j]=0;
    }
 
    int uniquePathsIII(vector<vector<int>>& grid) {
            int i1,j1;
            int totalsquares=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                        i1=i;
                        j1=j;
                }
                if(grid[i][j]!=-1)
                {
                    totalsquares++;
                }
            }
        }
        
        createme(grid,i1,j1,1,totalsquares);
        
        
        return paths;
        
        
    }
    
  
};