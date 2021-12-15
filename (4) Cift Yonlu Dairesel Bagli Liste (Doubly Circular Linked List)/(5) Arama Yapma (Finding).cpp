#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct student {
	int student_number;
	struct student* previous;
	struct student* next;
};

struct student* sona_ekle(struct student* head, int student_num) {

	system("cls");

	struct student* node = new student();								// Heap alaninda dugum olusturulur ve baslangic adresi node degiskenine atanir
	node->student_number = student_num;									// Dugum datalari girilir

	bool flag = false;													// Ayni ogrenci numarasinin girilip girilmedigini kontrol eden flag

	if (head == NULL) {													// Heap alanindan bellek tahsis edilmemisse,henuz olusan dugum yoksa

		head = node;				    								// Artik dugum olustugu icin en bastaki dugumu gosteren head'e yeni olusan dugum atanir
		head->next = head;												// Listede henuz tek dugum oldugu icin olusan dugumun next'i yine head'i gosterir
		head->previous = head;											// Listede henuz tek dugum oldugu icin olusan dugumun previous'u head'i gosterir

		cout << student_num << " numarali ogrenci ilk ogrenci olarak sona ekleme yapildi..." << endl;
	}

	else {																// Heap alanindan bellek tahsis edilmisse,listede en az 1 dugum varsa

		struct student* temp1 = head;
		int counter = 1;												// Kac tane dugum oldugu bulunur

		while (temp1->next != head) {									// Listede kac tane dugum sayisi oldugu bulunur
			counter++;
			temp1 = temp1->next;
		}

		temp1 = head;

		for (int i = 0; i < counter; i++) {

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

		while (temp2->next != head) {									// Dongu sonlandiginda temp2 son dugumun adresini tutar
			temp2 = temp2->next;
		}

		temp2->next = node;												// Listedeki son dugumun (temp2) next'ine olusturulan dugum atanir ve son dugum node olarak guncellenir
		node->previous = temp2;											// Son dugum degistigi icin temp2 burada sondan birinci dugum olmustur.node previous'u kendinden bir onceki dugumu gostermelidir
		node->next = head;												// Olusan yeni dugum sona eklendigi icin next'ine head atanir
		head->previous = node;											// En bastaki dugumun previous'u son dugum adresini gosterir.Son dugum node oldugu icin bu guncellenmelidir

		cout << student_num << " numarali ogrenci sona eklendi..." << endl;
	}

	return head;
}

bool arama(struct student* head, int student_num) {

	system("cls");

	if (head == NULL) {													// Eger listede dugum yoksa,Heap alanindan bellek tahsis edilmemisse

		cout << "Liste bos arama YAPILAMAZ..." << endl;
		return 0;
	}

	bool flag = false;													// Aramanin yapilip yapilamadigini gosteren flag
	int index = 1;														// Eger student_num varsa hangi dugumde oldugunu gosteren index
	int counter = 1;													// Kac tane dugum oldugunu gosterir

	struct student* temp = head;

	while (temp->next != head) {										// Listede kac tane dugum oldugu bulunur

		counter++;
		temp = temp->next;
	}

	temp = head;

	for (int i = 0; i < counter; i++) {

		if (temp->student_number == student_num) {
			flag = true;
			break;
		}

		else {
			flag = false;
		}

		temp = temp->next;
		index += 1;
	}

	if (flag)
		cout << student_num << " numarali ogrenci bulundu " << "ve dugum numarasi : " << index << endl;

	else
		cout << student_num << " numarali ogrenci bulunamadi..." << endl;

	return flag;
}


void display(struct student* head) {

	system("cls");

	if (head == NULL)
		cout << "Liste bos gosterilecek ogrenci numarasi YOK..." << endl;

	else {

		struct student* temp = head;

		while (temp->next != head) {
			cout << temp->student_number << "    ";
			temp = temp->next;
		}

		cout << temp->student_number << "    " << endl;
	}
}

int main() {

	struct student* head = NULL;

	int student_num, secim;

	while (true) {

		cout << "---------------------------------" << endl;
		cout << "1 -->> Sona ekle" << endl;
		cout << "2 -->> Arama yap" << endl;
		cout << "3 -->> Yazdir" << endl;
		cout << "0 -->> Cikis" << endl;
		cout << "---------------------------------" << endl;

		cin >> secim;

		if (secim == 1) {
			cout << "Sona eklenmek istenen ogrencinin numarasi : ";
			cin >> student_num;
			head = sona_ekle(head, student_num);
		}
		else if (secim == 2) {
			cout << "Aranmak istenen ogrencinin numarasi : ";
			cin >> student_num;
			bool flag = arama(head, student_num);

		}
		else if (secim == 3) {
			display(head);
		}
		else if (secim == 0) {
			system("cls");
			cout << "Basariyla cikis yapildi..." << endl;
			return 0;
		}
		else {
			system("cls");
			cout << "Gecersiz sayi.. lutfen 1-3 arasinda bir sayi giriniz veya 0'a basarak programi sonlandiriniz... " << endl;
		}
	}
}	
