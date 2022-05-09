// 所有叶子节点的深度差不能超过1

bool Resolution(TreeNode* root)
{
    if (getDepth(root->left) - getDepth(root->right)) return false;
    return Resolution(root->left) && Resolution(root->right);
}

int getDepth(TreeNode* root)
{
    return 1+max();
}
