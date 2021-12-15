#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct student {
	int student_number;
	struct student* next;
};

struct student* sona_ekle(struct student* head, int student_num) {

	struct student* node = new student();								// Heap alaninda dugum olusturulur ve baslangic adresi node degiskenine atanir
	node->student_number = student_num;									// Dugum datalari girilir

	bool flag = false;													// Ayni ogrenci numarasinin girilip girilmedigini kontrol eden flag

	if (head == NULL) {													// Heap alanindan bellek tahsis edilmemisse,henuz olusan dugum yoksa

		head = node;				    								// Artik dugum olustugu icin en bastaki dugumu gosteren head'e yeni olusan dugumun adresi atanir
		head->next = NULL;												// Listede henuz tek dugum oldugu icin olusan dugumun next'ine NULL atanir

		cout << student_num << " numarali ogrenci ilk ogrenci olarak sona ekleme yapildi..." << endl;
	}

	else {																// Heap alanindan bellek tahsis edilmisse,listede en az 1 dugum varsa

		struct student* temp1 = head;

		while (temp1 != NULL) {											// Listedeki tum dugumlere bakilir	

			if (temp1->student_number == student_num) {					// Eger student_num daha once girilmisse ayni student_num tekrar girilemeyecegi icin student_num degeri sona eklenemez

				cout << student_num << " numarali ogrenci zaten var ayni ogrenci numarasi girilemez TEKRAR DENEYINIZ..." << endl;
				flag = false;
				break;
			}

			else {														// student_num degeri daha once girilmemisse student_num degeri sona eklenebilir

				flag = true;
				temp1 = temp1->next;
			}

		}

	}

	if (flag) {															// Eger ayni student_num girilmemisse sona ekleme yapilir 

		struct student* temp2 = head;

		while (temp2->next != NULL) {									// Dongu sonlandiginda temp2 son dugumun adresini tutar
			temp2 = temp2->next;										
		}

		temp2->next = node;												// Listedeki son dugumun (temp2) next'ine olusan dugum atanarak son dugum guncellenir
		node->next = NULL;												// Olusan yeni dugum sona eklenecegi icin next'ine NULL atanir

		cout << student_num << " numarali ogrenci sona eklendi..." << endl;
	}

	return head;
}

int main() {

	struct student* head = NULL;

	head = sona_ekle(head, 10);
	head = sona_ekle(head, 20);
	head = sona_ekle(head, 30);
	head = sona_ekle(head, 40);

	struct student* temp = head;

	cout << endl << "*********************" << endl;

	while (temp->next != NULL) {
		cout << temp->student_number << "    ";
		temp = temp->next;
	}

	cout << temp->student_number << "    " << endl;

	cout << "*********************" << endl;
}
