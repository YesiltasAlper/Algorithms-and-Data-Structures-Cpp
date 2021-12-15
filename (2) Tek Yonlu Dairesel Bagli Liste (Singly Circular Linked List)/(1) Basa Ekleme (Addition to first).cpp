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
		head->next = head;												// Listede henuz tek dugum oldugu icin olusan dugumun next'i yine head'i gosterir

		cout << student_num << " numarali ogrenci ilk ogrenci olarak basa eklendi..." << endl;
	}

	else {																// Eger Heap alanindan bellek tahsis edilmisse,listede en az 1 dugum varsa

		struct student* temp1 = head;
		int counter = 1;												// Kac tane dugum oldugu bulunur

		while (temp1->next != head) {									// Listede kac tane dugum sayisi oldugu bulunur
			counter++;
			temp1 = temp1->next;
		}

		temp1 = head;

		for (int i = 0; i < counter; i++) {

			if (temp1->student_number == student_num) {					// Eger student_num daha once girilmisse ayni student_num tekrar girilemeyecegi icin student_num degeri basa eklenemez

				cout << student_num << " numarali ogrenci zaten var ayni ogrenci numarasi girilemez TEKRAR DENEYINIZ..." << endl;
				flag = false;
				break;
			}
			
			else {														// student_num degeri daha once girilmemisse student_num degeri basa eklenebilir

				flag = true;
				temp1 = temp1->next;
			}
		}
	}

	if (flag) {															// Eger ayni student_num girilmemisse basa ekleme yapilir 

		struct student* temp2 = head;

		while (temp2->next != head) {									// Dongu sonlandiginda temp2 degiskeni son dugumun adresini tutar
			temp2 = temp2->next;
		}

		node->next = head;												// Basa ekleme yapacagimiz icin olusan dugumun next'ine head atanir
		head = node;													// head guncellenir
		temp2->next = head;												// son dugumun next'i yeni olusan dugumun adresini tutar

		cout << student_num << " numarali ogrenci basa eklendi basarili..." << endl;
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

	while (temp->next != head) {
		cout << temp->student_number << "    ";
		temp = temp->next;
	}

	cout << temp->student_number << "    " << endl;

	cout << "*********************" << endl;

}

