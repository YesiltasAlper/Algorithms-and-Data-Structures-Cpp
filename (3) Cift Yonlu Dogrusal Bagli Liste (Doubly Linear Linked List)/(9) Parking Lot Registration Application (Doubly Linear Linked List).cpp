#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>

using namespace std;

struct parking_lot {

	string number_plate;
	string vehicle_type;
	int parking_fee;

	struct parking_lot* previous;
	struct parking_lot* next;
};

struct parking_lot* registration(struct parking_lot* head, string number_plate, string vehicle_type, int parking_fee);		// for new registration

struct parking_lot* delete_first(struct parking_lot* head);								// These three functions were written only in order to be used by "delete_vehicle" function 
struct parking_lot* delete_last(struct parking_lot* head);
struct parking_lot* delete_intermediate(struct parking_lot* head, string number_plate);
struct parking_lot* delete_vehicle(struct parking_lot* head, string number_plate);		// to delete vehicle 

bool find_vehicle(struct parking_lot* head, string number_plate);						// to find any vehicle					
size_t number_of_vehicles(struct parking_lot* head);									// to calculate total number of the vehicles
int total_fee(struct parking_lot* head);												// to calculate total parking fee
void save_to_file(struct parking_lot* head);											// to save data to file
void read_from_file();																	// to display saved data in the file
void display(struct parking_lot* head);


int main() {

	struct parking_lot* head = NULL;

	string number_plate;
	string vehicle_type;
	int parking_fee;

	int choice;

	cout << "*****Parking Lot Registration Application******" << endl;

	while (true) {

		cout << "-----------------------------------------------" << endl;
		cout << "1 -->> New vehicle registration" << endl;
		cout << "2 -->> Delete vehicle" << endl;
		cout << "3 -->> Find vehicle registration" << endl;
		cout << "4 -->> Total number of vehicles " << endl;
		cout << "5 -->> Total fee " << endl;
		cout << "6 -->> Display" << endl;
		cout << "7 -->> Save the vehicles information to the file" << endl;
		cout << "8 -->> Display saved vehicles in the file" << endl;
		cout << "0 -->> Exit" << endl;
		cout << "-----------------------------------------------" << endl;

		cin >> choice;

		if (choice == 1) {
			cout << "Number Plate : ";	    cin >> number_plate;
			cout << "Vehicle Type : ";		cin >> vehicle_type;
			cout << "Parking Fee  : ";		cin >> parking_fee;

			head = registration(head, number_plate, vehicle_type, parking_fee);
		}
		else if (choice == 2) {
			cout << "Enter the number plate want to be deleted : ";
			cin >> number_plate;
			head = delete_vehicle(head, number_plate);
		}
		else if (choice == 3) {
			cout << "Enter the number plate want to be found : ";
			cin >> number_plate;
			bool flag = find_vehicle(head, number_plate);
		}
		else if (choice == 4) {
			size_t total_vehicles = number_of_vehicles(head);
		}
		else if (choice == 5) {
			int total = total_fee(head);
		}

		else if (choice == 6) {
			display(head);
		}
		else if (choice == 7) {
			save_to_file(head);
		}
		else if (choice == 8) {
			read_from_file();
		}
		else if (choice == 0) {
			system("cls");
			cout << "Exit is successful..." << endl;
			return 0;
		}
		else {
			system("cls");
			cout << "!!!! Please enter the number between 1-8 or exit by pressing 0" << endl;
		}
	}
}

struct parking_lot* registration(struct parking_lot* head, string number_plate, string vehicle_type, int parking_fee) {

	system("cls");

	struct parking_lot* vehicle = new parking_lot();

	vehicle->number_plate = number_plate;
	vehicle->vehicle_type = vehicle_type;
	vehicle->parking_fee = parking_fee;

	bool flag = false;							// The flag which checks whether the same number plate is entered

	if (head == NULL) {

		head = vehicle;
		head->previous = NULL;
		head->next = NULL;

		cout << number_plate << " added as first registration..." << endl;
	}

	else {

		struct parking_lot* temp = head;

		while (temp != NULL) {

			if (temp->number_plate == number_plate) {

				cout << number_plate << " Same number plate can not be entered TRY AGAIN..." << endl;
				flag = false;
				break;
			}

			else {

				flag = true;
				temp = temp->next;
			}
		}
	}

	if (flag) {

		vehicle->next = head;
		head->previous = vehicle;
		head = vehicle;
		head->previous = NULL;

		cout << number_plate << " added..." << endl;
	}

	return head;
}

struct parking_lot* delete_first(struct parking_lot* head) {

	if ((head->previous == NULL) && (head->next == NULL)) {

		cout << head->number_plate << " Last vehicle in the parking lot deleted..." << endl;

		delete head;
		head = NULL;
	}

	else {

		struct parking_lot* temp = head->next;

		cout << head->number_plate << " vehicle in the parking lot deleted..." << endl;

		delete head;
		head = temp;
		head->previous = NULL;
	}

	return head;
}

struct parking_lot* delete_last(struct parking_lot* head) {

	struct parking_lot* temp1 = head;

	while (temp1->next->next != NULL) {
		temp1 = temp1->next;
	}

	struct parking_lot* temp2 = temp1->next;

	cout << temp2->number_plate << " vehicle in the parking lot deleted..." << endl;

	delete temp2;
	temp1->next = NULL;

	return head;
}

struct parking_lot* delete_intermediate(struct parking_lot* head, string number_plate) {

	struct parking_lot* temp1 = head;

	while (temp1->next != NULL) {

		if (temp1->next->number_plate == number_plate) {

			struct parking_lot* temp2 = temp1->next->next;
			struct parking_lot* temp3 = temp1->next->next->previous;

			cout << temp1->next->number_plate << " vehicle in the parking lot deleted..." << endl;

			delete temp1->next;
			temp1->next = temp2;
			temp3 = temp1;

			break;

		}
		temp1 = temp1->next;
	}

	return head;
}

struct parking_lot* delete_vehicle(struct parking_lot* head, string number_plate) {

	system("cls");

	struct parking_lot* temp = head;

	bool flag = false;							// if there is vehicle in the parking lot flag = true  or else  flag = false
	int total_vehicles = 1;						// to calculate total number of the vehicles
	int vehicle_index = 0;						// The index of the vehicle want to be deleted

	if (head == NULL) {
		cout << "Parking lot is EMPTY..." << endl;
	}

	else {

		while (temp->next != NULL) {
			total_vehicles++;
			temp = temp->next;
		}

		temp = head;

		for (int i = 0; i < total_vehicles; i++) {

			if (temp->number_plate == number_plate) {

				vehicle_index++;
				flag = true;
				break;
			}

			else {

				vehicle_index++;
				flag = false;
				temp = temp->next;
			}
		}
	}

	temp = head;

	if (flag) {

		if (vehicle_index == 1) {													// If the vehicle want to be deleted is first 
			head = delete_first(head);
		}

		else if ((vehicle_index == total_vehicles) && (total_vehicles != 1)) {		// If the vehicle want to be deleted is last 
			head = delete_last(head);
		}

		else {																		// If the vehicle want to be deleted is intermediate
			head = delete_intermediate(head, number_plate);
		}
	}

	else {
		cout << number_plate << " vehicle could NOT be deleted..." << endl;
	}

	return head;
}


bool find_vehicle(struct parking_lot* head, string number_plate) {

	system("cls");

	bool flag = false;
	struct parking_lot* temp = head;

	if (head == NULL) {

		cout << "Parking lot is EMPTY..." << endl;
		return flag;
	}

	while (temp != NULL) {

		if (temp->number_plate == number_plate) {

			cout << "***********************" << endl;
			cout << "Number Plate : " << temp->number_plate << endl;
			cout << "Vehicle Type : " << temp->vehicle_type << endl;
			cout << "Parking Fee : " << temp->parking_fee << endl;
			cout << "***********************" << endl;

			flag = true;
			break;
		}

		else {

			flag = false;
			temp = temp->next;
		}
	}

	if ((flag == false) && (head != NULL))
		cout << number_plate << " vehicle could NOT be found..." << endl;

	return flag;
}


size_t number_of_vehicles(struct parking_lot* head) {

	system("cls");

	int total_vehicles = 0;							// to calculate total number of the vehicles

	if (head == NULL) {
		cout << "Parking lot is EMPTY..." << endl;
		return total_vehicles;
	}

	else {

		struct parking_lot* temp = head;
		total_vehicles = 1;

		while (temp->next != NULL) {
			total_vehicles++;
			temp = temp->next;
		}

		cout << "Number of the vehicles in the parking lot is : " << total_vehicles << endl;
	}

	return total_vehicles;
}


int total_fee(struct parking_lot* head) {

	system("cls");

	int total_fee = 0;

	if (head == NULL) {
		cout << "Parking lot is EMPTY..." << endl;
		return total_fee;
	}

	else {

		struct parking_lot* temp = head;

		while (temp->next != NULL) {
			total_fee += temp->parking_fee;
			temp = temp->next;
		}
		total_fee += temp->parking_fee;
	}

	cout << "Total fee of the vehicles in the parking lot is : " << total_fee << " TL" << endl;

	return total_fee;
}


void save_to_file(struct parking_lot* head) {

	system("cls");

	if (head == NULL) {
		cout << "There is NOT any vehicle to save to file..." << endl;
	}

	else {

		ofstream write("parkinglot.txt");		// Alttaki 'read_from_file' fonksiyonunu kullanabilmek icin oncelikle Runtime'da 7'ye basarak 'save_to_file' fonksiyonuna cagri yapilmalidir
												// Eger bunlar yapilmazsa olusmayan dosya okunmaya calisilacagi icin "Reading from file failed..." hatasi alinacaktir
												// parkinglot.txt dosyasi bu proje nerede kayitli ise orada acilir
		if (!write.is_open()) {					// Ayrica bilgilerin kaldigi yerden uzerine yazilmasi istenirse kod ofstream write("parkinglot.txt", ios::app); olarak degistirilebilir
			cout << "Save to file failed..." << endl;
			write.close();						// to be able to call 'read_from_file' function below,first 'save_to_file' function must be called by pressing '7' in runtime
			exit(EXIT_FAILURE);					// If these steps are not done, the error "Reading from file failed..." will be got, because the file that did not occur will be tried to be read
		}										// parkinglot.txt file is opened where this project saved is
												// if you want the data resumed to be overwritten,you can change the code as ofstream write("parkinglot.txt", ios::app);
		else {

			struct parking_lot* temp = head;

			write << "*************************" << endl;

			while (temp->next != NULL) {

				write << "Number Plate : " << temp->number_plate << endl;
				write << "Vehicle Type : " << temp->vehicle_type << endl;
				write << "Parking Fee : " << temp->parking_fee << endl;

				temp = temp->next;

				write << "*************************" << endl;
			}

			write << "Number Plate : " << temp->number_plate << endl;
			write << "Vehicle Type : " << temp->vehicle_type << endl;
			write << "Parking Fee : " << temp->parking_fee << endl;

			write << "*************************" << endl;

			cout << "Vehicle data in the parking lot saved to 'parkinglot.txt' file..." << endl;

			write.close();
		}
	}
}


void read_from_file() {

	system("cls");

	ifstream read("parkinglot.txt");

	if (!read.is_open()) {
		cout << "Reading from file failed..." << endl;
		read.close();
		exit(EXIT_FAILURE);
	}

	else {

		string line;

		while (getline(read, line)) {
			cout << line << endl;
		}

	}

	read.close();

}


void display(struct parking_lot* head) {

	system("cls");

	if (head == NULL)
		cout << "Parking lot is EMPTY..." << endl;

	else {

		struct parking_lot* temp = head;

		cout << "*************************" << endl;

		while (temp->next != NULL) {

			cout << "Number Plate : " << temp->number_plate << endl;
			cout << "Vehicle Type : " << temp->vehicle_type << endl;
			cout << "Parking Fee : " << temp->parking_fee << endl;

			temp = temp->next;

			cout << "*************************" << endl;
		}

		cout << "Number Plate : " << temp->number_plate << endl;
		cout << "Vehicle Type : " << temp->vehicle_type << endl;
		cout << "Parking Fee : " << temp->parking_fee << endl;

		cout << "*************************" << endl;
	}
}
