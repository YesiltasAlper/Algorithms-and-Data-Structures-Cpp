#include <iostream>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};


struct node* root_node(int number) {

	struct node* root = new node();
	root->data = number;
	root->left = NULL;
	root->right = NULL;

	return root;
}


struct node* add_node(struct node* root, int number) {

	if (root == NULL) {
		root = root_node(number);
	}

	else {

		if (number < root->data) {
			root->left = add_node(root->left, number);
		}
		else {
			root->right = add_node(root->right, number);
		}
	}

	return root;
}

size_t number_of_nodes(struct node* root) {

	if (root == NULL) {
		return 0;
	}

	else {
		return (number_of_nodes(root->left) + 1 + number_of_nodes(root->right));
	}
}

size_t depth(struct node* root) {

	size_t left = 0;
	size_t right = 0;

	if (root == NULL) {
		return 0;
	}

	else {

		left = depth(root->left);
		right = depth(root->right);

		if (left > right)
			return (left + 1);
		else
			return(right + 1);
	}
}

void change_location(struct node* root) {

	struct node* temp = NULL;

	if (root != NULL) {

		change_location(root->left);
		change_location(root->right);

		temp = root->left;

		root->left = root->right;
		root->right = temp;
	}

}

void preorder(struct node* root) {		// once kok

	if (root != NULL) {
		cout << root->data << "   ";
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node* root) {		// ortada kok

	if (root != NULL) {
		inorder(root->left);
		cout << root->data << "   ";
		inorder(root->right);
	}
}

void postorder(struct node* root) {		// sonda kok

	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		cout << root->data << "   ";
	}
}


int main() {

	struct node* root = NULL;
	int number;
	int node = 0;

	cout << "Enter the number of nodes : ";
	cin >> node;

	for (int i = 0; i < node; i++) {

		cout << "Number " << i + 1 << " : ";
		cin >> number;
		root = add_node(root, number);
	}

	cout << "****************BEFORE*********************" << endl;

	cout << "preOrder  : ";
	preorder(root);
	cout << endl;

	cout << "inOrder   : ";
	inorder(root);
	cout << endl;

	cout << "postOrder : ";
	postorder(root);
	cout << endl;

	cout << "****************AFTER********************" << endl;

	change_location(root);

	cout << "preOrder  : ";
	preorder(root);
	cout << endl;

	cout << "inOrder   : ";
	inorder(root);
	cout << endl;

	cout << "postOrder : ";
	postorder(root);
	cout << endl;

	cout << "*****************************************" << endl;

	cout << "Added number of the nodes : " << number_of_nodes(root);

	cout << endl;

	cout << "Depth of the tree : " << depth(root);

	cout << endl;

	cout << "*****************************************" << endl;
}
