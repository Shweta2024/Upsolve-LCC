//Time Complexity = O(n)
//Space Complexity = O(h+n), h->height of binary tree

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
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        priority_queue<long long>pq;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            long long len = q.size();
            long long levelSum = 0;
            while(len--)
            {
                TreeNode* currentNode = q.front();
                levelSum += currentNode->val;
                q.pop();
                
                if(currentNode->left)
                    q.push(currentNode->left);
                if(currentNode->right)
                    q.push(currentNode->right);
            }
            pq.push(levelSum);
        }
        if(pq.size() < k)
            return -1;
        
        k = k-1;
        while(k--)
            pq.pop();
        
        return pq.top();
    }
};
