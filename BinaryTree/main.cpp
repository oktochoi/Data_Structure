#include <iostream>
#include <queue>
#include <sstream>
using namespace std;
 
class TreeNode {
public:    
    int val;
    TreeNode *left, *right;
    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
};
 
TreeNode* buildTree(int *nums, int size) { 
    if (size == 0 || nums[0] == 0) return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < size) {
        TreeNode* curr = q.front();
        q.pop();

        // 왼쪽 자식
        if (i < size) {
            if (nums[i] != 0) {
                curr->left = new TreeNode(nums[i]);
                q.push(curr->left);
            } else {
                curr->left = nullptr;
            }
            i++;
        }

        // 오른쪽 자식
        if (i < size) {
            if (nums[i] != 0) {
                curr->right = new TreeNode(nums[i]);
                q.push(curr->right);
            } else {
                curr->right = nullptr;
            }
            i++;
        }
    }

    return root;
}

// 중위 순회 (Left → Root → Right)
void printInOrderTree(TreeNode* root) {
    if (!root) return;
    printInOrderTree(root->left);
    cout << root->val << " ";
    printInOrderTree(root->right);
}

// 전위 순휘 root -> left -> right
void preorderTraversal(TreeNode* root){
    if (!root) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//후위 순위 left -> right -. root 
void postorderTraversal(TreeNode* root){
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);        
    cout << root->val << " ";
}
 
int main() {
    int size;//사이즈
    int way;
    string number; //저장할 숫자
    cin >> size >> way;
    
    cin.ignore();
    getline(cin,number);
    stringstream iss(number);

    int* nums = new int[size];
    for(int i=0; i<size; i++){
        iss >> nums[i];
    }

    // 배열을 완전 이진 트리로 변환
    if(way == 1){
        cout << "preorder traversla: ";
        TreeNode* root = buildTree(nums,size);
        preorderTraversal(root);
    }else if(way==2){
        cout << "postorder traversla: ";
        TreeNode* root = buildTree(nums,size);
        postorderTraversal(root);
    }else{
        cout << "InOrder traversla:  ";
        TreeNode* root = buildTree(nums,size);
        printInOrderTree(root);        
    }
    return 0;
}