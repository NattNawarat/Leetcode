/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> num_vect;
    void travel(TreeNode* node){
        if(node -> left != NULL)travel(node -> left);
        num_vect.push_back(node->val);
        if(node -> right != NULL)travel(node -> right);
    }
    bool isValidBST(TreeNode* root) {
        travel(root);
        bool valid = true;
        for(int i = 1 ; i < num_vect.size();i++){
            if(num_vect.at(i) <= num_vect.at(i-1))valid = false;
        }
        return valid;
    }
};