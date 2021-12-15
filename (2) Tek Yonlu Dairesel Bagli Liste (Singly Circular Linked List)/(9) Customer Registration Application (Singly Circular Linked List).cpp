#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct customer {

	string customer_id;
	string name;
	string surname;
	string location;
	string product_name;
	int fee;

	struct customer* next;
};

struct customer* registration(struct customer* head, string customer_id, string name, string surname, string location, string product_name, int fee);			// for new registration

struct customer* delete_first(struct customer* head);									// These three functions were written only in order to be used by "delete_customer" function 
struct customer* delete_last(struct customer* head);
struct customer* delete_intermediate(struct customer* head, string customer_id);
struct customer* delete_customer(struct customer* head, string customer_id);			// to delete customer

bool find_customer(struct customer* head, string customer_id);							// to find any customer
size_t number_of_customers(struct customer* head);										// to calculate total number of the customers
int total_fee(struct customer* head);													// to calculate total fee of sold products
void display(struct customer* header);													// to display all customers in the list

int main() {

	struct customer* head = NULL;
	int choice;

	string customer_id;
	string name;
	string surname;
	string location;
	string product_name;
	int fee;

	cout << "****Customer Registration Application****" << endl << endl;

	while (true) {

		cout << "-----------------------------------------" << endl;
		cout << "1 -->> New customer registration" << endl;
		cout << "2 -->> Delete customer" << endl;
		cout << "3 -->> Find registration" << endl;
		cout << "4 -->> Total number of customers " << endl;
		cout << "5 -->> Total fee of sold products " << endl;
		cout << "6 -->> Display" << endl;
		cout << "0 -->> Exit" << endl;
		cout << "-----------------------------------------" << endl;

		cin >> choice;

		if (choice == 1) {

			cout << "Customer_id : ";	cin >> customer_id;
			cout << "Name : ";			cin >> name;
			cout << "Surname : ";		cin >> surname;
			cout << "Location : ";		cin >> location;
			cout << "Product Name : ";	cin >> product_name;
			cout << "Fee [TL] : ";		cin >> fee;

			head = registration(head, customer_id, name, surname, location, product_name, fee);
		}
		else if (choice == 2) {
			cout << "Enter the customer_id want to be deleted : ";
			cin >> customer_id;
			head = delete_customer(head, customer_id);
		}
		else if (choice == 3) {
			cout << "Enter the customer_id want to be found : ";
			cin >> customer_id;
			bool flag = find_customer(head, customer_id);
		}
		else if (choice == 4) {
			size_t total_customers = number_of_customers(head);
		}
		else if (choice == 5) {
			int total = total_fee(head);
		}
		else if (choice == 6) {
			display(head);
		}
		else if (choice == 0) {
			system("cls");
			cout << "Exit is successful..." << endl;
			return 0;
		}
		else {
			system("cls");
			cout << "!!!! Please enter the number between 1-6 or exit by pressing 0" << endl;
		}
	}
}


struct customer* registration(struct customer* head, string customer_id, string name, string surname, string location, string product_name, int fee) {

	system("cls");

	struct customer* person = new customer();

	person->customer_id = customer_id;
	person->name = name;
	person->surname = surname;
	person->location = location;
	person->product_name = product_name;
	person->fee = fee;

	bool flag = false;							// The flag which checks whether the same customer_id is entered

	if (head == NULL) {

		head = person;
		head->next = head;

		cout << customer_id << " added as first registration..." << endl;
	}

	else {

		struct customer* temp1 = head;
		int total_customers = 1;				// to calculate number of the customers

		while (temp1->next != head) {
			total_customers++;
			temp1 = temp1->next;
		}

		temp1 = head;

		for (int i = 0; i < total_customers; i++) {

			if (temp1->customer_id == customer_id) {

				cout << customer_id << " Same customer_id can not be entered TRY AGAIN..." << endl;
				flag = false;
				break;
			}

			else {

				flag = true;
				temp1 = temp1->next;
			}
		}
	}

	if (flag) {

		struct customer* temp2 = head;

		while (temp2->next != head) {
			temp2 = temp2->next;
		}

		person->next = head;
		head = person;
		temp2->next = head;

		cout << customer_id << " added..." << endl;
	}

	return head;
}


struct customer* delete_first(struct customer* head) {

	if (head->next == head) {

		cout << head->customer_id << " last customer deleted..." << endl;

		delete head;
		head = NULL;
	}

	else {

		struct customer* temp1 = head;

		while (temp1->next != head) {
			temp1 = temp1->next;
		}

		struct customer* temp2 = head->next;

		cout << head->customer_id << " deleted..." << endl;

		delete head;
		head = temp2;
		temp1->next = head;

	}

	return head;
}


struct customer* delete_last(struct customer* head) {

	struct customer* temp1 = head;

	while (temp1->next->next != head) {
		temp1 = temp1->next;
	}

	struct customer* temp2 = temp1->next;

	cout << temp2->customer_id << " deleted..." << endl;

	delete temp2;
	temp1->next = head;

	return head;
}

struct customer* delete_intermediate(struct customer* head, string customer_id) {

	struct customer* temp1 = head;

	while (temp1->next != head) {

		if (temp1->next->customer_id == customer_id) {

			struct customer* temp2 = temp1->next->next;

			cout << customer_id << " deleted..." << endl;

			delete temp1->next;
			temp1->next = temp2;

			break;

		}
		temp1 = temp1->next;
	}

	return head;
}

struct customer* delete_customer(struct customer* head, string customer_id) {

	system("cls");

	struct customer* temp = head;

	bool flag = false;							// if there is customer_id in the list flag = true  or else  flag = false
	int total_customers = 1;					// to calculate total number of the customers
	int customer_index = 0;						// The index of the customer want to be deleted

	if (head == NULL) {

		cout << "There is NOT any customer..." << endl;
	}

	else {

		while (temp->next != head) {
			total_customers++;
			temp = temp->next;
		}

		temp = head;

		for (int i = 0; i < total_customers; i++) {

			if (temp->customer_id == customer_id) {

				customer_index++;
				flag = true;
				break;
			}

			else {

				customer_index++;
				flag = false;
				temp = temp->next;
			}
		}
	}

	temp = head;

	if (flag) {

		if (customer_index == 1) {														// If the customer want to be deleted is first 
			head = delete_first(head);
		}

		else if ((customer_index == total_customers) && (total_customers != 1)) {		// If the customer want to be deleted is last 
			head = delete_last(head);
		}

		else {																			// If the customer want to be deleted is intermediate
			head = delete_intermediate(head, customer_id);
		}
	}

	else {
		cout << customer_id << " could NOT be deleted..." << endl;
	}

	return head;
}


bool find_customer(struct customer* head, string customer_id) {

	system("cls");

	bool flag = false;
	int total_customers = 1;			// to calculate total number of the customers
	struct customer* temp = head;

	if (head == NULL) {
		cout << "There is NOT any customer..." << endl;
		return flag;
	}

	else {

		while (temp->next != head) {
			total_customers++;
			temp = temp->next;
		}

		temp = head;

		for (int i = 0; i < total_customers; i++) {

			if (temp->customer_id == customer_id) {

				cout << "*********************************" << endl;
				cout << "Customer id : " << temp->customer_id << endl;
				cout << "Name : " << temp->name << endl;
				cout << "Surname : " << temp->surname << endl;
				cout << "Location : " << temp->location << endl;
				cout << "Product Name : " << temp->product_name << endl;
				cout << "Fee [TL] : " << temp->fee << endl;
				cout << "*********************************" << endl;

				flag = true;
				break;
			}

			else {

				flag = false;
				temp = temp->next;
			}
		}
	}

	if ((flag == false) && (head != NULL))
		cout << customer_id << " could NOT be found..." << endl;

	return flag;
}


size_t number_of_customers(struct customer* head) {

	system("cls");

	int total_customers = 0;						// to calculate total number of the customers

	if (head == NULL) {
		cout << "There is NOT any customer..." << endl;
		return total_customers;
	}

	else {

		struct customer* temp = head;
		total_customers = 1;

		while (temp->next != head) {
			total_customers++;
			temp = temp->next;
		}

		cout << "Number of the customers is : " << total_customers << endl;
	}

	return total_customers;
}


int total_fee(struct customer* head) {

	system("cls");

	int total_fee = 0;

	if (head == NULL) {
		cout << "There is NOT any customer..." << endl;
		return total_fee;
	}

	else {

		struct customer* temp = head;

		while (temp->next != head) {
			total_fee += temp->fee;
			temp = temp->next;
		}
		total_fee += temp->fee;
	}

	cout << "Total fee of sold products is : " << total_fee << " TL" << endl;

	return total_fee;
}


void display(struct customer* head) {

	system("cls");

	if (head == NULL)
		cout << "There is NOT any customer..." << endl;

	else {

		struct customer* temp = head;
		int total_customers = 1;			// to calculate total number of the customers

		while (temp->next != head) {
			temp = temp->next;
			total_customers++;
		}

		temp = head;

		cout << "*********************************" << endl;

		for (int i = 0; i < total_customers; i++) {

			cout << "Customer id : " << temp->customer_id << endl;
			cout << "Name : " << temp->name << endl;
			cout << "Surname : " << temp->surname << endl;
			cout << "Location : " << temp->location << endl;
			cout << "Product Name : " << temp->product_name << endl;
			cout << "Fee [TL] : " << temp->fee << endl;
			cout << "*********************************" << endl;

			temp = temp->next;
		}
	}
}

