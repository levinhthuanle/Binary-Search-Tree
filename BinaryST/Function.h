#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

struct BST {
	Node* root;

	BST() {
		root = NULL;
	}

	void insert(int x);
	void insert(Node*& root, int x);

	void inOrder();
	void inOrder(Node* root);

	// 2022 - 2023 a
	void printLeafNode();
	void printLeafNode(Node* root);

	// 2019 - 2020 a
	Node* findX(int x);
	Node* findX(Node* root, int x);

	Node* findMin();
	Node* findMin(Node* root);

	Node* deleteNode(int x);
	Node* deleteNode(Node* root, int x);

	// 2019 - 2020 c
	bool isIdentical(Node* t1, Node* t2);
	bool isSubTree(Node* t1);
	bool isSubTree(Node* tree1, Node* tree2);

	int getHeight();
	int getHeight(Node* root);

	void deleteTree();
	void deleteTree(Node*& root);

	// 2021 - 2022 b
	int sumOfTree();
	int sumOfTree(Node* root);

	// 2022 - 2023 b
	void printImbalancedNodes();
	void printImbalancedNodes(Node* root);

	// 2022 - 2023 c
	void get2NodesSumX(int x, Node*& p1, Node*& p2);
	void get2NodesSumX(Node* root, int x, Node*& p1, Node*& p2);

	// 2019 - 2020 b
	void printLongestPath();
	void printLongestPath(Node* root, vector<int>& path, vector<int>& pathLongest);
};