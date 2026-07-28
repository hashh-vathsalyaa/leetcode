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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp = nullptr;
        TreeNode* curr = root;

        while(curr != nullptr && curr->val != key)
        {
            temp = curr;
            if(key < curr->val)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        if(curr == nullptr)
        {
            return root;
        }
        else if(curr->left == nullptr && curr->right == nullptr)
        {
            if(temp == nullptr)
            {
                 delete curr;
                 return nullptr;
            }

            if(temp->left == curr)
            {
                temp->left = nullptr;
            }
            else{
                temp->right = nullptr;
            }
            delete curr;
            return root;
        }

        else if(curr->left == nullptr || curr->right == nullptr)
        {
            TreeNode* child;
            if(curr->left != nullptr)
            {
                child = curr->left;
            }
            else
            {
                child = curr->right;
            }
            if(temp == nullptr)
            {
                root = child;
            }
            else if(temp->left == curr)
            {
                temp->left = child;
            }
            else
            {
                temp->right = child;
            }
            delete curr;
            return root;
        }

        else
        {
            TreeNode* succ = curr->right;
            TreeNode* parent = curr;
            while(succ->left != nullptr)
            {
                parent = succ;
                succ = succ->left;
            }
            curr->val = succ->val;
            if(parent == curr)
            {
                curr->right = succ->right;
            }
            else
            {
                parent->left = succ->right;
            }
            delete succ;
            return root;
        }
    }


};