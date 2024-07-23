# 145 Binary Tree Postorder Traversal
![alt text](image.png)

## 难点
后序遍历是左右根

## C++
``` C++
void traversal(TreeNode* cur,vector<int>& ans)
{
    if (cur==nullptr) return;
    traversal(cur->left,ans);
    traversal(cur->right,ans);
    ans.push_back(cur->val);
}

vector<int> postorderTraversal(TreeNode* root) {
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
        self.traversal(cur.right,ans)
        ans.append(cur.val)

    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans=[]
        self.traversal(root,ans)
        return ans
```