#include "../include/include.h"

bool Solution(TreeNode* a, TreeNode* b)
{
    if (a == nullptr && b == nullptr) return true;
    if ((!a && b) || (a && !b) || (a->value != b->value)) return fasle;
    return Solution(a->left, b->left) && Solution(a->right, b->right);
}

// 重点是四种遍历方法, 背下来就行了
//
// 递归
vector<int> TraverseInOrder(TreeNode* root)
{
    vector<int> res;
    dfs(root, res);
    return res;
}

void dfs(TreeNode* parent, vector<int>& res)
{
    if (parent == nullptr) return;
    if (parent->left != nullptr) dfs(parent->left, res);
    res.push_back(parent->value);
    if (parent->right != nullptr) dfs(parent->right, res);
}

// 辅助栈
vector<int> TraverseInOrder(TreeNode* root)
{
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur != nullptr || !st.empty())
    {
        if (cur != nullptr)
        {
            // res.push_back(p->value);  放在这里是前序遍历
            st.push(p);  // 所有节点都要先入栈
            cur = cur->left;
        }
        else
        {
            p = s.top(); s.pop();
            res.push_back(p->value);
            p = p->right;
        }
    }
    return res;
}

// 更通用的写法
// 这个写法跟上面写法的区别在于, 上面的写法属于简化的写法, 访问右子节点时, 父节点并不在栈中, 无法打印完整路径
// 下面这个通用写法在访问右子节点时, 父节点依然在栈中, 可以打印完整路径, 并且这个栈是当前节点的完整路径
vector<int> TraverseInOrder(TreeNode* root)
{
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    while (cur != nullptr || !st.empty())
    {
        while (cur != nullptr)
        {
            // res.push_back(cur->value);  // 放在这里是前序遍历
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();  // 访问这个节点
        res.push_back(cur->value);  // 放在这里是中序遍历
        if (cur->right != nullptr && cur->right != pre)
        {
            cur = cur->right;
        }
        else
        {
            // res.push_back(cur->value);  // 放在这里是后续遍历
            st.pop();
            pre = cur;  // 防止死循环
            cur = nullptr;
        }
    }
    return res;
}

// Morris 遍历, 利用一个指针记录前一个节点, 而不是用栈
// 这个方法有两个主要逻辑: 1. 对每一个cur 节点, 寻找上一个节点, 如果是空, 则认为还没有遍历上一个节点, 指向自己, 往左遍历
// 2. 如果上一个节点非空, 说明cur 节点是从上一个节点跳过来的, 删除这个连接, 右移遍历
vector<int> MorrisTraverse(TreeNode* root)
{
    vector<int> res;
    if (root == nullptr) return res;
    TreeNode* cur = root;
    TreeNode* pre;
    while (cur != nullptr)
    {
        if (cur->left == nullptr)
        {
            res.push_back(cur->value);
            cur = cur->right;  // 右节点指向下一个节点, 未必是真正的右节点
        }
        else
        {
            pre = cur->left;
            while (pre->right != nullptr && pre->right != cur) pre = pre->right;
            if (pre->right == nullptr)
            {
                pre->right = cur;  // 下一个节点指向当前节点
                cur = cur->left;   // 遍历左节点
            }
            else  // pre->right == cur, 说明cur 节点是从pre->right 跳过来的
            {
                pre->right = nullptr;
                res.push_back(cur->value);
                cur = cur->right;
            }
        }
    }
    return res;
}
