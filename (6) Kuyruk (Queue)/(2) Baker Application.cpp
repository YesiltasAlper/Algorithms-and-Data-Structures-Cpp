#include <iostream>

using namespace std;

#define		QUEUE_SIZE		5									// Maximum number of people in the queue
#define		BREAD_FEE		2	

struct customer {
	string name;
	int number_of_bread;										// the number of bread the customer bought
	int debt;													// total fee the customer need to pay
	struct customer* next;
};

struct queue {
	int number_of_people;										// the number of people in the queue
	struct customer* front;
	struct customer* rear;
};


void initialize(struct queue* que);								
void add_to_queue(struct queue* que, string name, int number_of_bread);		
int collect_money(struct queue* que);
bool find_customer(struct queue* que, string name);
int customers_debt(struct queue* que);
void display(struct queue* que);


int main() {

	struct queue que;

	initialize(&que);

	string name;
	int number_of_bread;
	int choice;

	while (true) {

		cout << "----------------------------" << endl;
		cout << "BAKER QUEUE APPLICATION " << endl;
		cout << "1 -->> Add customer to queue" << endl;
		cout << "2 -->> Collect money and see the earnings" << endl;
		cout << "3 -->> Display the people in the queue" << endl;
		cout << "4 -->> Display customer's total debts" << endl;
		cout << "5 -->> Find customer" << endl;
		cout << "0 -->> Exit" << endl;
		cout << "----------------------------" << endl;

		cin >> choice;

		if (choice == 1) {
			cout << "Customer name : ";
			cin >> name;
			cout << "How much bread is required : ";
			cin >> number_of_bread;
			add_to_queue(&que, name, number_of_bread);
		}
		else if (choice == 2) {
			int x = collect_money(&que);
		}
		else if (choice == 3) {
			display(&que);
		}
		else if (choice == 4) {
			int x = customers_debt(&que);
		}
		else if (choice == 5) {
			cout << "Name : ";
			cin >> name;
			bool flag = find_customer(&que, name);
		}
		else if (choice == 0) {
			system("cls");
			cout << "Exit is successful...";
			return 0;
		}
		else {
			system("cls");
			cout << "Please enter the number between 1-5 or exit by pressing 0..." << endl;
		}
	}
}


void initialize(struct queue* que) {

	que->number_of_people = 0;
	que->front = que->rear = NULL;
}


void add_to_queue(struct queue* que, string name, int number_of_bread) {

	system("cls");

	struct customer* person = new customer();

	person->name = name;
	person->number_of_bread = number_of_bread;
	person->debt = (number_of_bread * BREAD_FEE);

	if (que->number_of_people == QUEUE_SIZE) {
		cout << "Queue is full..." << endl;
	}

	else if (que->number_of_people == 0) {

		person->next = NULL;

		que->front = que->rear = person;
		(que->number_of_people)++;

		cout << "First customer " << name << " added to queue " << endl;
	}

	else {

		person->next = que->rear;

		que->rear = person;
		(que->number_of_people)++;

		cout << "Customer " << name << " added to queue " << endl;
	}
}


int collect_money(struct queue* que) {

	system("cls");

	static int total_earnings = 0;

	if (que->number_of_people == 0) {
		cout << "Queue is empty..." << endl;
	}

	else if (que->number_of_people == 1) {

		cout << que->front->name << " last customer in the queue left by paying " << que->front->debt << " TL" << endl;

		total_earnings += que->front->debt;

		delete que->front;
		que->front = que->rear = NULL;
		(que->number_of_people)--;
	}

	else {

		struct customer* temp = que->rear;

		while (temp->next->next != NULL) {
			temp = temp->next;
		}

		cout << que->front->name << " customer in the queue left by paying " << que->front->debt << " TL" << endl;

		total_earnings += que->front->debt;

		delete que->front;
		que->front = temp;
		que->front->next = NULL;
		(que->number_of_people)--;
	}

	cout << "Total earnings : " << total_earnings << endl;

	return total_earnings;
}


bool find_customer(struct queue* que, string name) {

	system("cls");

	bool flag = false;

	struct customer* temp = que->rear;

	if (que->number_of_people == 0) {
		cout << "Queue is empty..." << endl;
	}

	else {

		while (temp != NULL) {

			if (temp->name == name) {

				cout << "**********************" << endl;

				cout << "Name : " << temp->name << endl;
				cout << "Number of bread : " << temp->number_of_bread << endl;
				cout << "Debt : " << temp->debt << " TL" << endl;

				cout << "**********************" << endl;

				flag = true;
				break;
			}

			else {

				flag = false;
				temp = temp->next;
			}
		}
	}

	if ((flag == false) && (que->number_of_people != 0))
		cout << name << " customer could not be found..." << endl;

	return flag;
}


int customers_debt(struct queue* que) {

	system("cls");

	int total_debt = 0;

	if (que->number_of_people == 0) {
		cout << "Queue is empty..." << endl;
	}

	else {

		struct customer* temp = que->rear;

		cout << "**********************" << endl;

		while (temp != NULL) {

			cout << "Name : " << temp->name << endl;
			cout << "Number of bread : " << temp->number_of_bread << endl;
			cout << "Debt : " << temp->debt << endl;

			cout << "**********************" << endl;

			total_debt += temp->debt;
			temp = temp->next;
		}
	}

	cout << endl << "Total debt : " << total_debt << " TL" << endl;

	return total_debt;
}

void display(struct queue* que) {

	system("cls");

	if (que->number_of_people == 0) {
		cout << "Queue is empty..." << endl;
		cout << "Number of people in the queue : " << que->number_of_people << endl;
	}

	else {

		struct customer* temp = que->rear;

		while (temp->next != NULL) {

			cout << temp->name << " --->> ";
			temp = temp->next;
		}
		cout << temp->name << " --->> ";
		cout << endl << endl << "Number of people in the queue : " << que->number_of_people << endl;
	}

	cout << endl;
}

