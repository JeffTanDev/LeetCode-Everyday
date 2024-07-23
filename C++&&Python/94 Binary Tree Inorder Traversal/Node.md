# 94 Binary Tree Inorder Traversal
![alt text](image.png)

## 难点
中序遍历是左根右

## C++
``` C++
void traversal(TreeNode* cur, vector<int>& ans)
{
    if (cur==nullptr) return;
    traversal(cur->left,ans);
    ans.push_back(cur->val);
    traversal(cur->right,ans);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    traversal(root, ans);
    return ans;
}
```

## Python
``` Python
class Solution:
    def traversal(self, cur, ans):
        if not cur:
            return
        self.traversal(cur.left,ans)
        ans.append(cur.val)
        self.traversal(cur.right,ans)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans=[]
        self.traversal(root,ans)
        return ans
```