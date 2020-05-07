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
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode*> Queue;
        Queue.push(root);
        int genCount = 1;
        while(!Queue.empty()){
            if(genCount == 0)
                genCount = Queue.size();
            TreeNode *u = Queue.front();
            Queue.pop();

            genCount--;
            int target = -1;
            if(u->left != NULL ){
                if(u->left->val == x)
                    target = y;
                else if(u->left->val == y)
                    target = x;
                else
                    Queue.push(u->left);
            }
            if(u->right != NULL){
                // check for sibling
                if(u->right->val == target)
                    return false;
                if(u->right->val == x)
                    target = y;
                else if(u->right->val == y)
                    target = x;
                else
                    Queue.push(u->right);
            }
            if(target != -1){
                while(genCount > 0){
                    u = Queue.front();
                    genCount--;
                    Queue.pop();
                    if(u->left != NULL && u->left->val == target)
                        return true;
                    if(u->right != NULL && u->right->val == target)
                        return true;
                }
                return false;
            }        
        }
        return false;
        
    }
};
