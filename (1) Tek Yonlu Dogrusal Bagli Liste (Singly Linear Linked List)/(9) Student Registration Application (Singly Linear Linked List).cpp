#include <iostream>

using namespace std;

struct student {

	string name;
	string surname;
	int student_number;
	float midterm, final, average;
	bool is_successful;										// if average >= 50 the student passes the lesson and 	is_successful = true		otherwise 	is_successful = false

	struct student* next;
};

struct student* registration(struct student* head, string name, string surname, int student_num, float midterm, float final);		// for new registration

struct student* delete_first(struct student* head);										// These three functions were written only in order to be used by "delete_student" function 
struct student* delete_last(struct student* head);
struct student* delete_intermediate(struct student* head, int student_num);
struct student* delete_student(struct student* head, int student_num);					// to delete student 

bool find_student(struct student* head, int number);									// to find any student
void display_all_students(struct student* head);										// to display all students in the list
void display_class_status(struct student* head);										// to display class status


int main() {

	string name, surname;
	int student_num;
	float midterm, final;

	int choice;

	struct student* head = NULL;

	cout << "******Student Registration Application*******" << endl << endl;

	while (true) {

		cout << "---------------------------------------------" << endl;
		cout << "1 -->> New student registration" << endl;
		cout << "2 -->> Delete student" << endl;
		cout << "3 -->> Find registration" << endl;
		cout << "4 -->> Display all of students information" << endl;
		cout << "5 -->> Display class status" << endl;
		cout << "0 -->> Exit" << endl;
		cout << "---------------------------------------------" << endl;

		cin >> choice;

		if (choice == 1) {
			cout << "Student Name    : ";	cin >> name;
			cout << "Student Surname : ";	cin >> surname;
			cout << "Student Number  : ";	cin >> student_num;

		check_midterm:

			cout << "Midterm : ";			cin >> midterm;

			if ((midterm > 100) || (midterm < 0)) {
				cout << "Invalid midterm value TRY AGAIN..." << endl;
				goto check_midterm;
			}

		check_final:

			cout << "Final : ";				cin >> final;

			if ((final > 100) || (final < 0)) {
				cout << "Invalid final value TRY AGAIN..." << endl;
				goto check_final;
			}

			head = registration(head, name, surname, student_num, midterm, final);
		}
		else if (choice == 2) {
			cout << "Enter the student number want to be deleted : ";
			cin >> student_num;
			head = delete_student(head, student_num);
		}
		else if (choice == 3) {
			cout << "Enter the student number want to be found : ";
			cin >> student_num;
			bool flag = find_student(head, student_num);
		}
		else if (choice == 4) {
			display_all_students(head);
		}
		else if (choice == 5) {
			display_class_status(head);
		}
		else if (choice == 0) {
			system("cls");
			cout << "Exit is successful..." << endl;
			return 0;
		}
		else {
			system("cls");
			cout << "!!!! Please enter the number between 1-5 or exit by pressing 0" << endl;
		}
	}
}

struct student* registration(struct student* head, string name, string surname, int student_num, float midterm, float final) {

	system("cls");

	struct student* person = new student();

	person->name = name;
	person->surname = surname;
	person->student_number = student_num;
	person->midterm = midterm;
	person->final = final;
	person->average = ((0.6F * final) + (0.4F * midterm));

	bool flag = false;							// The flag which checks whether the same student number is entered

	if (person->average < 50.0F || person->final < 45)
		person->is_successful = false;
	else
		person->is_successful = true;

	if (head == NULL) {

		head = person;
		head->next = NULL;

		cout << person->name << " " << person->surname << " added as first registration..." << endl;
	}

	else {

		struct student* temp = head;

		while (temp != NULL) {

			if (temp->student_number == student_num) {

				cout << student_num << " Same student number can not be entered TRY AGAIN..." << endl;
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

		person->next = head;
		head = person;

		cout << person->name << " " << person->surname << " added..." << endl;
	}

	return head;
}

struct student* delete_first(struct student* head) {

	if (head->next == NULL) {

		cout << head->name << " " << head->surname << " Last student deleted..." << endl;

		delete head;
		head = NULL;
	}

	else {

		struct student* temp = head->next;

		cout << head->name << " " << head->surname << " deleted..." << endl;

		delete head;
		head = temp;
	}

	return head;
}


struct student* delete_last(struct student* head) {

	struct student* temp1 = head;

	while (temp1->next->next != NULL)
		temp1 = temp1->next;

	struct student* temp2 = temp1->next;

	cout << temp2->name << " " << temp2->surname << " deleted..." << endl;

	delete temp2;
	temp1->next = NULL;

	return head;
}


struct student* delete_intermediate(struct student* head, int student_num) {

	struct student* temp1 = head;

	while (temp1->next != NULL) {

		if (temp1->next->student_number == student_num) {

			struct student* temp2 = temp1->next->next;

			cout << temp1->next->name << " " << temp1->next->surname << " deleted..." << endl;

			delete temp1->next;
			temp1->next = temp2;

			break;
		}

		temp1 = temp1->next;
	}

	return head;
}


struct student* delete_student(struct student* head, int student_num) {

	system("cls");

	struct student* temp = head;

	bool flag = false;							// if there is student_num in the class flag = true  or else  flag = false
	int total_students = 1;						// to calculate total number of the students
	int student_index = 0;						// The index of the student number want to be deleted

	if (head == NULL) {

		cout << "Class is EMPTY..." << endl;
	}

	else {

		while (temp->next != NULL) {
			total_students++;
			temp = temp->next;
		}

		temp = head;

		for (int i = 0; i < total_students; i++) {

			if (temp->student_number == student_num) {

				student_index++;
				flag = true;
				break;
			}

			else {

				student_index++;
				flag = false;
				temp = temp->next;
			}
		}
	}

	temp = head;

	if (flag) {

		if (student_index == 1) {													// If the student number want to be deleted is first 
			head = delete_first(head);
		}

		else if ((student_index == total_students) && (total_students != 1)) {		// If the student number want to be deleted is last  
			head = delete_last(head);
		}

		else {																		// If the student number want to be deleted is intermediate
			head = delete_intermediate(head, student_num);
		}
	}

	else {
		cout << student_num << " student could NOT be deleted..." << endl;
	}

	return head;
}


bool find_student(struct student* head, int student_num) {

	system("cls");

	bool flag = false;

	struct student* temp = head;

	if (head == NULL) {
		cout << "Class is EMPTY..." << endl;
		return flag;
	}

	else {

		while (temp != NULL) {

			if (temp->student_number == student_num) {

				cout << "****************************************" << endl;
				cout << "Name : " << temp->name << endl;
				cout << "Surname : " << temp->surname << endl;
				cout << "Student number : " << temp->student_number << endl;
				cout << "Midterm : " << temp->midterm << endl;
				cout << "Final : " << temp->final << endl;
				cout << "Average : " << temp->average << endl;
				cout << "is_successful : " << temp->is_successful << endl;
				cout << "****************************************" << endl;

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
		cout << student_num << " student could NOT be found..." << endl;

	return flag;
}


void display_all_students(struct student* head) {

	system("cls");

	if (head == NULL)
		cout << "Class is EMPTY..." << endl;

	else {

		struct student* temp = head;


		while (temp->next != NULL) {

			cout << "****************************************" << endl;
			cout << "Name : " << temp->name << endl;
			cout << "Surname : " << temp->surname << endl;
			cout << "Student number : " << temp->student_number << endl;
			cout << "Midterm : " << temp->midterm << endl;
			cout << "Final : " << temp->final << endl;
			cout << "Average : " << temp->average << endl;
			cout << "is_successful : " << temp->is_successful << endl;

			temp = temp->next;
		}

		cout << "****************************************" << endl;

		cout << "Name : " << temp->name << endl;
		cout << "Surname : " << temp->surname << endl;
		cout << "Student number : " << temp->student_number << endl;
		cout << "Midterm : " << temp->midterm << endl;
		cout << "Final : " << temp->final << endl;
		cout << "Average : " << temp->average << endl;
		cout << "is_successful : " << temp->is_successful << endl;

		cout << "****************************************" << endl;
	}
}

void display_class_status(struct student* head) {

	system("cls");

	struct student* temp = head;

	size_t class_size = 0;
	size_t successful = 0;
	size_t unsuccessful = 0;

	float total_grade = 0;
	float class_average = 0;

	if (head == NULL)
		cout << "Class is EMPTY..." << endl;

	else {

		while (temp != NULL) {

			class_size++;
			total_grade += temp->average;

			if (temp->is_successful)
				successful++;
			else
				unsuccessful++;

			temp = temp->next;
		}

		class_average = total_grade / class_size;

		cout << "**********************" << endl;
		cout << "Class Size    : " << class_size << endl;
		cout << "Class Average : " << class_average << endl;
		cout << "Successful    : " << successful << endl;
		cout << "Unsuccessful  : " << unsuccessful << endl;
		cout << "**********************" << endl;

		temp = head;

		cout << endl << "-------->>" "Successful Students" << "<<--------" << endl;

		for (size_t i = 0; i < class_size; i++) {

			if (temp->is_successful) {
				cout << "Student Number :" << " " << temp->student_number << "     " << temp->name << " " << temp->surname << endl;
			}
			temp = temp->next;
		}

		temp = head;

		cout << endl << "------->>" "Unsuccessful Students" << "<<-------" << endl;

		for (size_t i = 0; i < class_size; i++) {

			if (temp->is_successful == false) {
				cout << "Student Number :" << " " << temp->student_number << "     " << temp->name << " " << temp->surname << endl;
			}
			temp = temp->next;
		}

		cout << endl;
	}

}


