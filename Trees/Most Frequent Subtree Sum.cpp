
    class Solution {
    public:

        int findAllsum(TreeNode *root,map<int,int>&freq)
        {
            if(!root->left && !root->right) 
            {
                freq[root->val]+=1; 
                return root->val;
            }
            int sum=root->val;
            if(root->left) sum += findAllsum(root->left,freq);
            if(root->right) sum += findAllsum(root->right,freq);
            freq[sum]+=1;

            return sum;

        }

        vector<int> findFrequentTreeSum(TreeNode* root) {

            if(root==NULL)
            {
                return {};
            }

            map<int,int>freq;
            findAllsum(root,freq);

            vector<int>vecsum;
            int max=INT_MIN;
            for(auto v:freq)
            {
                if(v.second>max)
                {
                    max=v.second;
                }
            }

            for(auto v:freq)
            {
                if(v.second==max)
                {
                    vecsum.push_back(v.first);
                }
            }


            return vecsum;

        }
    };