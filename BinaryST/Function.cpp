#include "Function.h"

void BST::insert(int x)
{
	insert(root, x);
}

void BST::insert(Node*& root, int x)
{
	if (root == nullptr) {
		root = new Node(x);
		return;
	}

	if (x < root->data)
		insert(root->left, x);
	else
		insert(root->right, x);
}

void BST::inOrder()
{
	inOrder(root);
}

void BST::inOrder(Node* root)
{
	if (root == nullptr)
		return;

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void BST::printLeafNode()
{
	printLeafNode(root);
}

void BST::printLeafNode(Node* root)
{
	if (root == nullptr)
		return;

	printLeafNode(root->left);
	printLeafNode(root->right);

	if (root->left == NULL && root->right == NULL)
		cout << root->data << " ";
}

Node* BST::findX(int x)
{
	return findX(root, x);
}

Node* BST::findX(Node* root, int x)
{
	if (root == nullptr)
		return nullptr;
	
	if (root->data == x)
		return root;

	if (x < root->data)
		return findX(root->left, x);
	else
		return findX(root->right, x);
}

Node* BST::findMin()
{
	return findMin(root);
}

Node* BST::findMin(Node* root)
{
	Node* current = root;
	while (current && current->left) {
		current = current->left;
	}
	return current;
}

Node* BST::deleteNode(int x)
{
	return deleteNode(root, x);
}

Node* BST::deleteNode(Node* root, int x)
{
	if (root == nullptr) 
		return root;
	

	if (x < root->data) 
		root->left = deleteNode(root->left, x);
	else if (x > root->data) 
		root->right = deleteNode(root->right, x);
	else {
		if (root->left == nullptr) {
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr) {
			Node* temp = root->left;
			delete root;
			return temp;
		}

		Node* temp = findMin(root->right);
		root->data = temp->data;

		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

bool BST::isIdentical(Node* t1, Node* t2)
{
	if (t1 == nullptr && t2 == nullptr)
		return true;

	if (t1 == nullptr || t2 == nullptr)
		return false;

	return (t1->data == t2->data) && (isIdentical(t1->left, t2->left)) && 
		(isIdentical(t1->left, t2->left));
}

bool BST::isSubTree(Node* t1)
{
	return isSubTree(t1, root);
}

bool BST::isSubTree(Node* tree1, Node* tree2)
{
	if (tree1 == nullptr)
		return true;

	if (tree1 == NULL)
		return false;

	Node* rootOfTree1InTree2 = findX(tree1->data);

	return isIdentical(tree1, rootOfTree1InTree2);
}

int BST::getHeight()
{
	return getHeight(root);
}

int BST::getHeight(Node* root)
{
	if (root == NULL)
		return 0;

	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

void BST::deleteTree()
{
	deleteTree(root);
}

void BST::deleteTree(Node*& root)
{
	if (root == nullptr)
		return;

	deleteTree(root->left);
	deleteTree(root->right);


	delete root;



}

int BST::sumOfTree()
{
	return sumOfTree(root);
}

int BST::sumOfTree(Node* root)
{
	if (root == nullptr)
		return 0;

	return root->data + sumOfTree(root->left) + sumOfTree(root->right);
}

void BST::printImbalancedNodes()
{
	printImbalancedNodes(root);
}

void BST::printImbalancedNodes(Node* root)
{
	if (root == NULL)
		return;

	if (abs(getHeight(root->left) - getHeight(root->right)) > 1)
		cout << root->data << " ";

	printImbalancedNodes(root->left);
	printImbalancedNodes(root->right);
}

void BST::get2NodesSumX(int x, Node*& p1, Node*& p2)
{
	get2NodesSumX(root, x, p1, p2);
}

void BST::get2NodesSumX(Node* root, int x, Node*& p1, Node*& p2)
{
	if (root == NULL)
		return;

	for (int i = 1; i < x; i++) {
		p1 = findX(i);
		p2 = findX(x - i);

		if (p1 && p2)
			return;
	}
}

void BST::printLongestPath()
{
	vector<int> path, pathLongest;
	printLongestPath(root, path, pathLongest);

	for (auto x : pathLongest)
		cout << x << " ";
}

void BST::printLongestPath(Node* root, vector<int>& path, vector<int>& pathLongest)
{
	if (root == nullptr)
		return;

	path.push_back(root->data);

	if (root->left == nullptr && root->right == nullptr) {
		if (path.size() > pathLongest.size()) {
			pathLongest = path;
		}
	}

	printLongestPath(root->left, path, pathLongest);
	printLongestPath(root->right, path, pathLongest);

	
	path.pop_back();
}

