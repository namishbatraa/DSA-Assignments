#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data=d;
        left=nullptr;
        right=nullptr;
    }
};


node* insert(node*root, int data){
    if (root==nullptr){
        return new node(data);
    }
    if (data<=root->data){
        root->left=insert(root->left, data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

node* build(){
    int d;
    cout<<"Enter the values for the nodes (enter -1 to stop): ";
    cin>>d;

    node* root=nullptr;

    while (d!=-1){
        root=insert(root, d);
        cin>>d;
    }
    return root;
}

void prosperity_tree(node* root, int &sum){
    if (!root){
        return;
    }
    prosperity_tree(root->right, sum);
    sum += root->data;
    root->data=sum;
    prosperity_tree(root->left, sum);
}

int findHEIGHT(node* root) {
    if (root==nullptr) {
        return 0;
    }
    int l=findHEIGHT(root->left);
    int r=findHEIGHT(root->right);
    return max(l, r) + 1;
}

void printKTHlevel(node* root, int k) {
    if (root==nullptr) {
        return;
    }
    if (k==1) {
        cout<<root->data<<" ";
        return;
    }
    printKTHlevel(root->left,k-1);
    printKTHlevel(root->right,k-1);
}

void print(node* root) {
    int height=findHEIGHT(root);
    for (int i=1;i<=height;i++) {
        printKTHlevel(root, i);
    }
}

int main(){
    int sum=0;
    node* root=build();
    prosperity_tree(root,sum);
    cout<<"The prosperity tree is: "<<endl;
    print(root);
    cout<<endl;
    return 0;
}