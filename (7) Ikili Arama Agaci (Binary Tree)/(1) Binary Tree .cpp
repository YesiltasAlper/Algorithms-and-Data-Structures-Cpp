#include <iostream>

using namespace std;
	
struct node {
	int data;
	struct node* left;
	struct node* right;
};


struct node* kok_dugum(int number) {

	struct node* root = new node();
	root->data = number;
	root->left = NULL;
	root->right = NULL;

	return root;
}


struct node* dugum_ekle(struct node* root, int number) {

	if (root == NULL) {
		root = kok_dugum(number);
	}

	else {

		if (number < root->data) {
			root->left = dugum_ekle(root->left, number);
		}
		else {
			root->right = dugum_ekle(root->right, number);
		}
	}

	return root;
}

void preorder(struct node* root) {		// once kok

	if (root !=  NULL) {
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node* root) {		// ortada kok

	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void postorder(struct node* root) {		// sonda kok

	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}


int main() {

	struct node* root = NULL;
	int sayi;

	for (int i = 0; i < 7; i++) {

		cout << "Sayi giriniz : ";
		cin >> sayi;
		root = dugum_ekle(root, sayi);
	}

	cout << "**************************" << endl;

	cout << "preOrder  : ";
	preorder(root);
	cout << endl;

	cout << "inOrder   : ";
	inorder(root);
	cout << endl;

	cout << "postOrder : ";
	postorder(root);
	cout << endl;
}


