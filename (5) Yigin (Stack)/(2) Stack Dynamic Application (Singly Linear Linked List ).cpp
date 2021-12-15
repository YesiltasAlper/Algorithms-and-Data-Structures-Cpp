#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>

using namespace std;

#define		SIZE	10								// Size of the array

struct node {										// Node (Singly Linear Linked List)		
	int value;
	struct node* next;
};

struct stack {										// The stack contains node and cnt
	struct node* top = NULL;
	int cnt = 0;
};

void push(struct stack* stack_obj, int value) {		// to add value to stack

	system("cls");

	struct node* stack_node = new node();
	stack_node->value = value;

	if (stack_obj->cnt == SIZE) {					// if stack is full
		cout << "Stack is full..." << endl;
	}

	else if (stack_obj->cnt == 0) {					// if stack is empty

		stack_obj->top = stack_node;
		stack_obj->top->next = NULL;
		(stack_obj->cnt)++;

		cout << "First node added to stack..." << endl;
	}

	else {											// if stack is not full and empty

		stack_node->next = stack_obj->top;
		stack_obj->top = stack_node;
		(stack_obj->cnt)++;

		cout << "Node added to stack..." << endl;
	}
}

void pop(struct stack* stack_obj) {					// to delete value from stack

	system("cls");

	if (stack_obj->cnt == 0) {						// if stack is empty
		cout << "Stack is empty..." << endl;
	}

	else {

		if (stack_obj->cnt == 1) {					// if stack has one node

			delete stack_obj->top;
			stack_obj->top == NULL;
			(stack_obj->cnt)--;
		}

		else {

			struct node* temp = stack_obj->top->next;

			cout << stack_obj->top->value << " deleted..." << endl;

			delete stack_obj->top;
			stack_obj->top = temp;
			(stack_obj->cnt)--;
		}

	}
}

void display_top(struct stack* stack_obj) {			// to display top value in stack

	system("cls");

	if (stack_obj->cnt == 0) {
		cout << "Stack is empty..." << endl;
	}

	else {
		cout << "Top : " << stack_obj->top->value << endl;
	}
}

void display(struct stack* stack_obj) {				// to display all values in stack

	system("cls");

	if (stack_obj->cnt == 0) {
		cout << "Stack is empty..." << endl;
	}

	else {

		cout << "**STACK**" << endl;

		struct node* temp = stack_obj->top;

		for (int i = 0; i < stack_obj->cnt; i++) {
			cout << temp->value << endl;
			temp = temp->next;
		}

		cout << "*********" << endl;
	}

}

int main() {

	struct stack stack_obj;

	int value;
	int choice;

	while (true) {

		cout << "---------------------------------" << endl;
		cout << "1 -->> Add to stack " << endl;
		cout << "2 -->> Delete from stack " << endl;
		cout << "3 -->> Top value " << endl;
		cout << "4 -->> Display " << endl;
		cout << "0 -->> Exit" << endl;
		cout << "---------------------------------" << endl;

		cin >> choice;

		if (choice == 1) {
			cout << "The value want to be added : ";
			cin >> value;
			push(&stack_obj, value);
		}
		else if (choice == 2) {
			pop(&stack_obj);
		}
		else if (choice == 3) {
			display_top(&stack_obj);
		}
		else if (choice == 4) {
			display(&stack_obj);
		}
		else if (choice == 0) {
			system("cls");
			cout << "Exit is successful..." << endl;
			return 0;
		}
		else {
			system("cls");
			cout << "!!!! Please enter the number between 1-4 or exit by pressing 0 " << endl;
		}
	}
}
