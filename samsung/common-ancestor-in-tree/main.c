#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *findLowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || root == p || root == q)
        return root;
    TreeNode *left = findLowestCommonAncestor(root->left, p, q);
    TreeNode *right = findLowestCommonAncestor(root->right, p, q);
    if (left && right)
        return root;
    if (!left)
        return right;
    if (!right)
        return left;
}

int getTreeSize(TreeNode *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return getTreeSize(node->left) + 1 +
               getTreeSize(node->right);
}

int main()
{
    int v, e, left, right;
    int n, i, parent, child, treeSize;
    TreeNode *treeNodeList, *lowestCommonAncestor;

    for (n = 0; n < 10; ++n)
    {
        scanf("%d %d %d %d", &v, &e, &left, &right);
        treeNodeList = (TreeNode *)malloc((v + 1) * sizeof(TreeNode));
        memset(treeNodeList, 0, (v + 1) * sizeof(TreeNode));

        for (i = 1; i <= v; ++i)
        {
            treeNodeList[i].val = i;
            treeNodeList[i].left = NULL;
            treeNodeList[i].right = NULL;
        }
        for (i = 0; i < e; ++i)
        {
            scanf("%d %d", &parent, &child);
            if (treeNodeList[parent].left == NULL)
            {
                treeNodeList[parent].left = &treeNodeList[child];
            }
            else
            {
                treeNodeList[parent].right = &treeNodeList[child];
            }
        }

        lowestCommonAncestor = findLowestCommonAncestor(&treeNodeList[1], &treeNodeList[left], &treeNodeList[right]);
        treeSize = getTreeSize(lowestCommonAncestor);
        printf("#%d %d %d\n", n + 1, lowestCommonAncestor->val, treeSize);

        free(treeNodeList);
    }

    return 0;
}