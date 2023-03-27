#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
	int key;
	Node *left, *right, *parent;
};

class BST
{
	Node *root;
	
	Node* insert(int key, Node *node)
	{
		if (node == NULL) 
		{
			node = new Node;
			node->key = key;
			node->left = node->right = node->parent = NULL;
		} else if (key > node->key) 
		{
			node->right = insert(key, node->right);
			node->right->parent = node;
		} else 
		{
			node->left = insert(key, node->left);
			node->left->parent = node;
		}
		return node;
			
	}

	void inorder(Node *node)
	{
		if (node == NULL)
			return;
		inorder(node->left);
		cout << node->key << ' ';
		inorder(node->right);
	}

	Node* search(int key, Node *node)
	{
		if (node == NULL || key == node->key)
			return node;
		if (key > node->key)
			return search(key, node->right);
		return search(key, node->left);
	}

	Node* find_min(Node *node)
	{
		if (node == NULL)
			return NULL;
		if (node->left == NULL)
			return node;
		return find_min(node->left);
	}

	Node* find_max(Node *node)
	{
		if (node == NULL)
			return NULL;
		if (node->right == NULL)
			return node;
		return find_min(node->right);
	}

	Node* successor(Node *node)
	{
		if (node->right != NULL)
			return find_min(node->right);

		Node *parent = node->parent;
		while (parent != NULL && node == parent->right) {
			node = parent;
			parent = node->parent;
		}

		return parent;
	}

	Node* predecessor(Node *node)
	{
		if (node->left != NULL)
			return find_max(node->left);

		Node *parent = node->parent;
		while (parent != NULL && node == parent->left) {
			node = parent;
			parent = node->parent;
		}

		return parent;
	}

	bool nodesEqual(Node *node1, Node *node2)
	{
		if(node1 == nullptr && node2 == nullptr){
			return true;
		}

		if(node1 == nullptr || node2 == nullptr)
		{
			return false;
		}
		
		return (nodesEqual(node1->left, node2->left) && nodesEqual(node1->right, node2->right));

	}

    void nthPower(Node *node, int n)
    {
        if(node == nullptr)
            return;
        
        node->key = pow(node->key, n);
        nthPower(node->left, n);
        nthPower(node->right, n);

    }

public:
	BST() : root(NULL) {}
	
	void print()
	{
		inorder(root);
	}

	void insert(int key)
	{
		root = insert(key, root);
	}

	bool search(int key)
	{
		return search(key, root);
	}

	int find_min()
	{
		Node *node = find_min(root);
		if (node != NULL)
			return node->key;
		return -1;
	}

	int find_max()
	{
		Node *node = find_max(root);
		if (node != NULL)
			return node->key;
		return -1;
	}

	int successor(int key)
	{
		Node *node = search(key, root);
		if (node == NULL)
			return -1;
		node = successor(node);
		if (node == NULL)
			return -1;
		return node->key;
	}

	int predecessor(int key)
	{
		Node *node = search(key, root);
		if (node == NULL)
			return -1;
		node = predecessor(node);
		if (node == NULL)
			return -1;
		return node->key;
	}

	bool structurallyEqual(BST T1, BST T2)
	{
		return nodesEqual(T1.root, T2.root);
	}

    BST nthPowerBST(BST T, int n)
    {
        BST rez(T);
        nthPower(rez.root, n);
        return rez;
    }

};

int main()
{
    BST t1;

    t1.insert(10);
    t1.insert(5);
    t1.insert(15);
    t1.insert(20);
    t1.insert(13);
       
    BST t2;

    t2.insert(8);
    t2.insert(3);
    t2.insert(12);
    t2.insert(17);
    t2.insert(9);

    cout << t2.structurallyEqual(t1, t2) << endl;

    t1.nthPowerBST(t1, 2);
    t1.print();
}
    
