#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

#define		SIZE	10					// Size of the array

struct stack {

	int array[SIZE];					// Static array
	int top = -1;						// for index of the array
};

stack stack1;

void push(int value) {					// to add value to the array (stack)

	system("cls");

	if (stack1.top == SIZE - 1) {
		cout << "Array is full..." << endl;
	}

	else {
		stack1.top++;
		stack1.array[stack1.top] = value;
		cout << value << " added to stack..." << endl;
	}
}

void pop() {							// to delete value from the array (stack)

	system("cls");

	if (stack1.top == -1) {
		cout << "Array is empty..." << endl;
	}

	else {
		cout << stack1.array[stack1.top] << " deleted from stack..." << endl;
		stack1.top--;
	}
}

void reset() {							// to reset the stack

	system("cls");

	if (stack1.top == -1) {
		cout << "Array is empty..." << endl;
	}

	else {
		stack1.top = -1;
		cout << "Stack reseted..." << endl;
	}
}

void display() {

	system("cls");

	if (stack1.top == -1) {
		cout << "Array is empty..." << endl;
	}

	else {

		cout << "********" << endl;

		for (int i = stack1.top; i > -1; i--) {
			cout << stack1.array[i] << endl;
		}

		cout << "********" << endl;
	}
}

int main() {

	int value;
	int choice;

	while (true) {

		cout << "---------------------------------" << endl;
		cout << "1 -->> Add to stack " << endl;
		cout << "2 -->> Delete from stack " << endl;
		cout << "3 -->> Reset " << endl;
		cout << "4 -->> Display " << endl;
		cout << "0 -->> Exit" << endl;
		cout << "---------------------------------" << endl;

		cin >> choice;

		if (choice == 1) {
			cout << "The value want to be added : ";
			cin >> value;
			push(value);
		}
		else if (choice == 2) {
			pop();
		}
		else if (choice == 3) {
			reset();
		}
		else if (choice == 4) {
			display();
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

