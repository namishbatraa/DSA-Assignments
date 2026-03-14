#include <iostream>
using namespace std;

bool invalidTree=false;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        data=d;
        left=nullptr;
        right=nullptr;
    }
};

TreeNode* createTreeInPre(int *in, int *pre, int s, int e, int &preIndex, int total) {
    if (s>e || preIndex>=total) {
        return nullptr;
    }

    int rootVal=pre[preIndex];
    TreeNode* root=new TreeNode(pre[preIndex]);
    int index=-1;

    for (int j=s;j<=e; j++) {
        if (in[j]==pre[preIndex]) {
            index=j;
            break;
        }
    }

    if (index==-1){
        invalidTree=true;
        return nullptr;
    }

    preIndex++;
    root->left=createTreeInPre(in, pre, s, index - 1, preIndex, total);
    root->right=createTreeInPre(in, pre, index + 1, e, preIndex, total);
    return root;
}

int findHEIGHT(TreeNode* root) {
    if (root==nullptr) {
        return 0;
    }
    int l=findHEIGHT(root->left);
    int r=findHEIGHT(root->right);
    return max(l, r) + 1;
}

void printKTHlevel(TreeNode* root, int k) {
    if (k==1) {
        if (root!=nullptr){
        cout<<root->data<<" ";
        }
        else{
        cout<<"null ";
        }
        return;
    }
    if (root==nullptr){
        int nullCount=1 << (k-1);
        for (int i=0; i<nullCount; i++){
            cout<<"null ";
        }
        return;
    }
    printKTHlevel(root->left,k-1);
    printKTHlevel(root->right,k-1);
}

void print(TreeNode* root) {
    int height=findHEIGHT(root);
    for (int i=1;i<=height;i++) {
        printKTHlevel(root, i);
    }
}

int main(){
    cout<<"Enter total number of elements in the tree: ";
    int total;
    cin>>total;
    int pre[total];
    int in[total];

    cout<<"Enter the elements of preorder array (separated by a space): ";
    for (int k=0; k<total; k++) {
        cin>>pre[k];
    }

    cout <<"Enter the elements of inorder array (separated by a space): ";
    for (int k=0; k<total; k++) {
        cin>>in[k];
    }
    
    int preIndex=0;
    TreeNode* root=createTreeInPre(in, pre, 0, total-1, preIndex, total);
    if (invalidTree || preIndex!=total){
        cout<<"Unable to construct a valid binary tree."<<endl;
    }
    else{
        cout<<"The elements of the tree are : ";
        print(root);
    }
    return 0;
}