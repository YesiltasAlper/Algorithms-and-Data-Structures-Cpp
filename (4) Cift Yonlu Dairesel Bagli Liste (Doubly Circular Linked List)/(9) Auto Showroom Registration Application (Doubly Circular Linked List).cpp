#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>

using namespace std;

struct auto_showroom {

	string number_plate;
	string brand;
	string model;
	string colour;
	int year;
	float purchase_price;

	struct auto_showroom* previous;
	struct auto_showroom* next;
};


struct auto_showroom* registration(struct auto_showroom* head, string number_plate, string brand, string model, string colour, int year, float purchase_price);		// for new registration

struct auto_showroom* delete_first(struct auto_showroom* head, float profit);								// These three functions were written only in order to be used by "sell_vehicle" function 
struct auto_showroom* delete_last(struct auto_showroom* head, float profit);
struct auto_showroom* delete_intermediate(struct auto_showroom* head, string number_plate, float profit);
struct auto_showroom* sell_vehicle(struct auto_showroom* head, string number_plate, float profit);			// to sell vehicle with profit% profit.	Profit variable is entered by user.	
																											// if purchase_price = 250 and profit = 20 the vehicle is sold with 20% profit.
																											// Sale price = 300  and profit is 50 
bool find_vehicle(struct auto_showroom* head, string number_plate);		// to find any vehicle					
size_t number_of_vehicles(struct auto_showroom* head);					// to calculate total number of the vehicles
void save_to_file(struct auto_showroom* head);							// to save data to file
void read_from_file();													// to display saved data in the file
void display(struct auto_showroom* head);

int main() {

	struct auto_showroom* head = NULL;
	int choice;
	float profit;														// The profit percentage of the vehicle want to be sold 

	string number_plate;
	string brand;
	string model;
	string colour;
	int year;
	float purchase_price;

	cout << "*******Auto Showroom Registration Application*******" << endl;


	while (true) {

		cout << "---------------------------------------------------" << endl;
		cout << "1 -->> New vehicle registration" << endl;
		cout << "2 -->> Sell vehicle" << endl;
		cout << "3 -->> Find vehicle registration" << endl;
		cout << "4 -->> Total number of vehicles in the auto showroom" << endl;
		cout << "5 -->> Display the vehicles in auto showroom" << endl;
		cout << "6 -->> Save the vehicles information to the file" << endl;
		cout << "7 -->> Display saved vehicles in the file" << endl;
		cout << "0 -->> Exit" << endl;
		cout << "---------------------------------------------------" << endl;

		cin >> choice;

		if (choice == 1) {

			cout << "Number Plate : ";			cin >> number_plate;
			cout << "Brand : ";					cin >> brand;
			cout << "Model : ";					cin >> model;
			cout << "Colour : ";				cin >> colour;
			cout << "Year : ";					cin >> year;
			cout << "Purchase Price [TL] : ";	cin >> purchase_price;

			head = registration(head, number_plate, brand, model, colour, year, purchase_price);
		}
		else if (choice == 2) {
			cout << "Enter the number plate want to be sold : ";
			cin >> number_plate;
			cout << "Enter the profit percentage (%) of " << number_plate << " vehicle want to be sold : ";
			cin >> profit;
			head = sell_vehicle(head, number_plate, profit);
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
			display(head);
		}
		else if (choice == 6) {
			save_to_file(head);
		}
		else if (choice == 7) {
			read_from_file();
		}
		else if (choice == 0) {
			system("cls");
			cout << "Exit is successful..." << endl;
			return 0;
		}
		else {
			system("cls");
			cout << "!!!! Please enter the number between 1-7 or exit by pressing 0" << endl;
		}
	}
}


struct auto_showroom* registration(struct auto_showroom* head, string number_plate, string brand, string model, string colour, int year, float purchase_price) {

	system("cls");

	struct auto_showroom* vehicle = new auto_showroom();

	vehicle->number_plate = number_plate;
	vehicle->brand = brand;
	vehicle->model = model;
	vehicle->colour = colour;
	vehicle->year = year;
	vehicle->purchase_price = purchase_price;

	bool flag = false;													// The flag which checks whether the same number plate is entered

	if (head == NULL) {

		head = vehicle;
		head->next = head;
		head->previous = head;

		cout << number_plate << " added as first registration..." << endl;
	}

	else {

		struct auto_showroom* temp1 = head;
		int total_vehicle = 1;

		while (temp1->next != head) {
			total_vehicle++;
			temp1 = temp1->next;
		}

		temp1 = head;

		for (int i = 0; i < total_vehicle; i++) {

			if (temp1->number_plate == number_plate) {

				cout << number_plate << " Same number plate can not be entered TRY AGAIN..." << endl;
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

		struct auto_showroom* temp2 = head;

		while (temp2->next != head) {
			temp2 = temp2->next;
		}

		vehicle->next = head;
		head->previous = vehicle;
		head = vehicle;
		head->previous = temp2;
		temp2->next = head;

		cout << number_plate << " added..." << endl;
	}

	return head;
}


struct auto_showroom* delete_first(struct auto_showroom* head, float profit) {

	float sale_price = ((head->purchase_price) + ((head->purchase_price) * (profit / 100)));

	if ((head->previous == head) && (head->next == head)) {

		cout << head->number_plate << " Last vehicle in the auto showroom sold..." << endl;
		cout << "Purchase Price [TL] : " << head->purchase_price << endl;
		cout << "Profit : " << profit << "%" << endl;
		cout << "Sale Price [TL] : " << sale_price << endl;
		cout << "Profit [TL] : " << sale_price - head->purchase_price << endl;

		delete head;
		head = NULL;
	}

	else {

		struct auto_showroom* temp1 = head;

		while (temp1->next != head) {
			temp1 = temp1->next;
		}

		struct auto_showroom* temp2 = head->next;

		cout << head->number_plate << " Vehicle in the auto showroom sold..." << endl;
		cout << "Purchase Price [TL] : " << head->purchase_price << endl;
		cout << "Profit : " << profit << "%" << endl;
		cout << "Sale Price [TL] : " << sale_price << endl;
		cout << "Profit [TL] : " << sale_price - head->purchase_price << endl;

		delete head;
		head = temp2;
		temp1->next = head;
		head->previous = temp1;

	}

	return head;
}

struct auto_showroom* delete_last(struct auto_showroom* head, float profit) {

	struct auto_showroom* temp1 = head;

	while (temp1->next->next != head) {
		temp1 = temp1->next;
	}

	struct auto_showroom* temp2 = temp1->next;

	float sale_price = ((temp2->purchase_price) + ((temp2->purchase_price) * (profit / 100)));

	cout << temp2->number_plate << " Vehicle in the auto showroom sold..." << endl;
	cout << "Purchase Price [TL] : " << temp2->purchase_price << endl;
	cout << "Profit : " << profit << "%" << endl;
	cout << "Sale Price [TL] : " << sale_price << endl;
	cout << "Profit [TL] : " << sale_price - temp2->purchase_price << endl;

	delete temp2;
	temp1->next = head;
	head->previous = temp1;

	return head;
}


struct auto_showroom* delete_intermediate(struct auto_showroom* head, string number_plate, float profit) {

	struct auto_showroom* temp1 = head;

	while (temp1->next != head) {

		if (temp1->next->number_plate == number_plate) {

			struct auto_showroom* temp2 = temp1->next->next;
			struct auto_showroom* temp3 = temp1->next->next->previous;

			float sale_price = ((temp1->next->purchase_price) + ((temp1->next->purchase_price) * (profit / 100)));

			cout << number_plate << " Vehicle in the auto showroom sold..." << endl;
			cout << "Purchase Price [TL] : " << temp1->next->purchase_price << endl;
			cout << "Profit : " << profit << "%" << endl;
			cout << "Sale Price [TL] : " << sale_price << endl;
			cout << "Profit [TL] : " << sale_price - temp1->next->purchase_price << endl;

			delete temp1->next;
			temp1->next = temp2;
			temp3 = temp1;

			break;

		}
		temp1 = temp1->next;
	}

	return head;
}


struct auto_showroom* sell_vehicle(struct auto_showroom* head, string number_plate, float profit) {

	system("cls");

	struct auto_showroom* temp = head;

	bool flag = false;													// if there is vehicle in the auto showroom flag = true  or else  flag = false
	int total_vehicles = 1;												// to calculate total number of the vehicles
	int vehicle_index = 0;												// The index of the vehicle want to be sold

	if (head == NULL) {
		cout << "Auto showroom is EMPTY..." << endl;
	}

	else {

		while (temp->next != head) {
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

		if (vehicle_index == 1) {													// If the vehicle want to be sold is first 
			head = delete_first(head, profit);
		}

		else if ((vehicle_index == total_vehicles) && (total_vehicles != 1)) {		// If the vehicle want to be sold is last 
			head = delete_last(head, profit);
		}

		else {																		// If the vehicle want to be sold is intermediate
			head = delete_intermediate(head, number_plate, profit);
		}
	}

	else {
		cout << number_plate << " vehicle could NOT be sold..." << endl;
	}

	return head;
}


bool find_vehicle(struct auto_showroom* head, string number_plate) {

	system("cls");

	bool flag = false;
	int total_vehicles = 1;															// to calculate total number of the vehicles
	struct auto_showroom* temp = head;

	if (head == NULL) {

		cout << "Auto showroom is EMPTY..." << endl;
		return flag;
	}

	else {

		while (temp->next != head) {
			total_vehicles++;
			temp = temp->next;
		}

		temp = head;

		for (int i = 0; i < total_vehicles; i++) {

			if (temp->number_plate == number_plate) {

				cout << "*********************************" << endl;
				cout << "Number Plate : " << temp->number_plate << endl;
				cout << "Brand : " << temp->brand << " " << endl;
				cout << "Model : " << temp->model << " " << endl;
				cout << "Colour : " << temp->colour << " " << endl;
				cout << "Year : " << temp->year << " " << endl;
				cout << "Purchase Price[TL] : " << temp->purchase_price << endl;
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
		cout << number_plate << " vehicle could NOT be found..." << endl;

	return flag;
}


size_t number_of_vehicles(struct auto_showroom* head) {

	system("cls");

	int total_vehicles = 0;															// to calculate total number of the vehicles

	if (head == NULL) {
		cout << "Auto showroom is EMPTY..." << endl;
		return total_vehicles;
	}

	else {

		struct auto_showroom* temp = head;
		total_vehicles = 1;

		while (temp->next != head) {
			total_vehicles++;
			temp = temp->next;
		}

		cout << "Number of the vehicles in the parking lot is : " << total_vehicles << endl;
	}

	return total_vehicles;
}

void save_to_file(struct auto_showroom* head) {

	system("cls");

	if (head == NULL) {
		cout << "There is NOT any vehicle to save to file..." << endl;
	}

	else {

		ofstream write("autoshowroom.txt");		// Alttaki 'read_from_file' fonksiyonunu kullanabilmek icin oncelikle Runtime'da 6'ya basarak 'save_to_file' fonksiyonuna cagri yapilmalidir
												// Eger bunlar yapilmazsa olusmayan dosya okunmaya calisilacagi icin "Reading from file failed..." hatasi alinacaktir
												// autoshowroom.txt dosyasi bu proje nerede kayitli ise orada acilir
		if (!write.is_open()) {					// Ayrica bilgilerin kaldigi yerden uzerine yazilmasi istenirse kod ofstream write("autoshowroom.txt", ios::app); olarak degistirilebilir
			cout << "Save to file failed..." << endl;
			write.close();						// to be able to call 'read_from_file' function below,first 'save_to_file' function must be called by pressing '6' in runtime.	
			exit(EXIT_FAILURE);					// If these steps are not done, the error "Reading from file failed..." will be got, because the file that did not occur will be tried to be read.
		}										// autoshowroom.txt file is opened where this project saved is.
												// if you want the data resumed to be overwritten,you can change the code as ofstream write("autoshowroom.txt", ios::app);
		else {

			struct auto_showroom* temp = head;

			write << "*********************************" << endl;

			while (temp->next != head) {

				write << "Number Plate : " << temp->number_plate << endl;
				write << "Brand : " << temp->brand << " " << endl;
				write << "Model : " << temp->model << " " << endl;
				write << "Colour : " << temp->colour << " " << endl;
				write << "Year : " << temp->year << " " << endl;
				write << "Purchase Price[TL] : " << temp->purchase_price << endl;

				temp = temp->next;

				write << "*********************************" << endl;
			}

			write << "Number Plate : " << temp->number_plate << endl;
			write << "Brand : " << temp->brand << " " << endl;
			write << "Model : " << temp->model << " " << endl;
			write << "Colour : " << temp->colour << " " << endl;
			write << "Year : " << temp->year << " " << endl;
			write << "Purchase Price[TL] : " << temp->purchase_price << endl;

			write << "*********************************" << endl;

			cout << "Vehicle data in the autoshowroom saved to 'autoshowroom.txt' file..." << endl;

			write.close();
		}

	}

}

void read_from_file() {

	system("cls");

	ifstream read("autoshowroom.txt");

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

		read.close();
	}

}


void display(struct auto_showroom* head) {

	system("cls");

	if (head == NULL)
		cout << "Auto showroom is EMPTY..." << endl;

	else {

		struct auto_showroom* temp = head;
		int total_vehicles = 1;														// to calculate total number of the vehicle

		while (temp->next != head) {
			temp = temp->next;
			total_vehicles++;
		}

		temp = head;

		cout << "*********************************" << endl;

		for (int i = 0; i < total_vehicles; i++) {

			cout << "Number Plate : " << temp->number_plate << endl;
			cout << "Brand : " << temp->brand << " " << endl;
			cout << "Model : " << temp->model << " " << endl;
			cout << "Colour : " << temp->colour << " " << endl;
			cout << "Year : " << temp->year << " " << endl;
			cout << "Purchase Price[TL] : " << temp->purchase_price << endl;
			cout << "*********************************" << endl;

			temp = temp->next;
		}

	}
}
