#include "Function.h"

bool isPrime(int k) {
	if (k < 2)
		return false;

	for (int i = 2; i * i <= k; i++)
		if (k % i == 0)
			return false;

	return true;
}

bool isCp(int k) {
	return ((float)sqrt(k) == round(sqrt(k)));
}

int main() {
	BST tree, tree2;
	int n;
	cout << "Enter number of values: ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		tree.insert(x);
	}

	cout << "In-order traverse: ";
	tree.inOrder();
	cout << endl;
	cout << "Heigth of tree: " << tree.getHeight() << endl;

	cout << "Leaf Node of tree: ";
	tree.printLeafNode();
	cout << endl;

	cout << "Sum of the tree: " << tree.sumOfTree() << endl;
	
	cout << "Imbalanced Nodes:";
	tree.printImbalancedNodes();
	cout << endl;

	cout << "Tree longest path: ";
	tree.printLongestPath();
	cout << endl;

	int x; 
	cout << "Enter x to find: ";
	cin >> x;

	Node* X = tree.findX(x);
	if (X == NULL)
		cout << "X does not exist in the tree" << endl;
	else
		cout << "Found x \n";


	cout << "Enter x to delete: ";
	cin >> x;
	tree.deleteNode(x);
	cout << "Tree after delete: \n";
	tree.inOrder();

	int m;
	cout << "\nEnter number of value of the second tree";
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x;
		tree2.insert(x);
	}
	if (tree.isSubTree(tree2.root))
		cout << "Tree2 is a sub-tree of main tree \n";
	else
		cout << "Tree 2 is not a sub-tree of main tree \n";


	tree.deleteTree();

	return 0;
}