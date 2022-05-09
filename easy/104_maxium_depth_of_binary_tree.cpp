int Resulution(TreeNode* root)
{
    return 1 + max(Resolution(root->left), Resolution(root->right));
}

// 递归或者层序遍历都可以
