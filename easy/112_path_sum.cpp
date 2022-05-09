// 检查二叉树是否存在根节点到叶节点的路径和为给定值
// 简单递归就行了
return has(root->left, sum - root->val) || has(root->right, sum - root->value);

// 另一个巧妙的方法是层序遍历, 每次遍历到一个节点就把上一个节点的数值加到当前节点上, 看到叶节点的时候是否正好为给定的值
