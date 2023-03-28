#include<iostream>

using namespace std;

class TreeNode{
public:
    int value;
    TreeNode *left, *right;
    int height;

    TreeNode(int val){
        value = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree{
public:
    TreeNode* insert(TreeNode* root, int key){
        if(!root){
            return new TreeNode(key);
        }else if(key < root->value){
            root->left = insert(root->left, key);
        }else{
            root->right = insert(root->right, key);
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        if(balance > 1 && key < root->left->value){
            return RIGHT_ROTATE(root);
        }

        if(balance < -1 && key > root->right->value){
            return LEFT_ROTATE(root);
        }

        if(balance > 1 && key > root->left->value){
            root->left = LEFT_ROTATE(root->left);
            return RIGHT_ROTATE(root);
        }

        if(balance < -1 && key < root->right->value){
            root->right = RIGHT_ROTATE(root->right);
            return LEFT_ROTATE(root);
        }

        return root;
    }

    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            cout << root->value << " ";
            inorder(root->right);
        }
    }

private:
    int getHeight(TreeNode* node){
        if(!node){
            return 0;
        }
        return node->height;
    }

    int getBalance(TreeNode* node){
        if(!node){
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    TreeNode* LEFT_ROTATE(TreeNode* x){
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    TreeNode* RIGHT_ROTATE(TreeNode* y){
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

};

int main(){
    AVLTree tree;
    TreeNode* root = nullptr;
    
    root = tree.insert(root, 10);
    root = tree.insert(root, 20);
    root = tree.insert(root, 30);
    root = tree.insert(root, 40);
    root = tree.insert(root, 50);
    root = tree.insert(root, 25);

    tree.inorder(root);
    cout << endl;
}