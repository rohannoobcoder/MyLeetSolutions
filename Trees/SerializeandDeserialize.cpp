/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="[,";
        queue<TreeNode *>qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode *temp=qu.front();
            qu.pop();
            if(temp!=NULL){
                ans+=to_string(temp->val)+",";
            }else{
                ans+="NULL,";
            }
            if(temp!=NULL){
                qu.push(temp->left);
                qu.push(temp->right);
            }
        }
        
        ans+=']';
        
        return ans;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode *>nodes;
        vector<int> pos;
        vector<string> ans;
        for(int i=0;i<data.length();i++){
            if(data[i]==',') pos.push_back(i);
        }
        for(int i=0;i<pos.size();i++){
            if(pos[i]==data.length()-2) break;
            int first = pos[i];
            int second = pos[i+1];
            string temp = data.substr(first+1,second-first-1);
            ans.push_back(temp);
        }
        
        for(int i=0;i<ans.size();i++){
            if(ans[i]=="NULL"){
                nodes.push_back(NULL);
            }else{
                nodes.push_back(new TreeNode(stoi(ans[i])));
            }
        }
        if(nodes[0]==NULL)return NULL;
        int i=0;
        int j=i+1;
        while(j<nodes.size()){
            if(nodes[i]==NULL){
                i++;
                continue;
            }
            nodes[i]->left = nodes[j];
            ++j;
            nodes[i]->right = nodes[j];
            ++j;
            ++i;
        }
        
        return nodes[0];
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;