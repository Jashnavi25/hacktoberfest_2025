void inorder(struct TreeNode* root, struct TreeNode** prev, int* ans){
    if(!root)
        return;
    inorder(root->left, prev, ans);
    if(*(prev))
        *ans = fmin(*ans , fabs(root->val - (*prev)->val));
    *prev = root;
    inorder(root->right, prev, ans);
    return;
    
}
int getMinimumDifference(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    int ans = INT_MAX;
    inorder(root, &prev, &ans);
    return ans;
}
