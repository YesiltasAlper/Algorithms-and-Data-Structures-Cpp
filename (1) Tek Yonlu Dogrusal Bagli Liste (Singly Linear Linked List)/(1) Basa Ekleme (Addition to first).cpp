#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct student {
	int student_number;
	struct student* next;
};


struct student* basa_ekle(struct student* head, int student_num) {

	struct student* node = new student();								// Heap alaninda dugum olusturulur ve baslangic adresi node degiskenine atanir
	node->student_number = student_num;									// Dugum datalari girilir

	bool flag = false;													// Ayni ogrenci numarasinin girilip girilmedigini kontrol eden flag

	if (head == NULL) {													// Eger Heap alanindan bellek tahsis edilmemisse,henuz olusan dugum yoksa

		head = node;				    								// Artik dugum olustugu icin en bastaki dugumu gosteren head'e yeni olusan dugumun adresi atanir
		head->next = NULL;												// Listede henuz tek dugum oldugu icin olusan dugumun next'ine NULL atanir

		cout << student_num << " numarali ogrenci ilk ogrenci olarak basa eklendi..." << endl;
	}

	else {																// Eger Heap alanindan bellek tahsis edilmisse,listede en az 1 dugum varsa

		struct student* temp = head;

		while (temp != NULL) {											// Listedeki tum dugumlere bakilir			

			if (temp->student_number == student_num) {					// Eger student_num daha once girilmisse ayni student_num tekrar girilemeyecegi icin student_num degeri basa eklenemez

				cout << student_num << " numarali ogrenci zaten var ayni ogrenci numarasi girilemez TEKRAR DENEYINIZ..." << endl;
				flag = false;
				break;
			}

			else {														// student_num degeri daha once girilmemisse student_num degeri basa eklenebilir

				flag = true;
				temp = temp->next;
			}
		}
	}

	if (flag) {															// Eger ayni student_num girilmemisse basa ekleme yapilir

		node->next = head;												// Olusan yeni dugumun next'ine en bastaki dugum atanir.Boylece olusan yeni dugum en bastaki dugum olarak guncellenir
		head = node;													// head guncellenir

		cout << student_num << " numarali ogrenci basa eklendi..." << endl;
	}

	return head;
}

int main() {

	struct student* head = NULL;

	head = basa_ekle(head, 10);
	head = basa_ekle(head, 20);
	head = basa_ekle(head, 30);
	head = basa_ekle(head, 40);

	struct student* temp = head;

	cout << endl << "*********************" << endl;

	while (temp->next != NULL) {
		cout << temp->student_number << "    ";
		temp = temp->next;
	}

	cout << temp->student_number << "    " << endl;

	cout << "*********************" << endl;
}

