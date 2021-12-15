#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct student {
	int student_number;
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

		temp2->next = node;												// Listedeki son dugumun (temp2) next'ine olusan dugum atanarak son dugum guncellenir
		node->next = head;												// Olusan yeni dugum sona eklendigi icin next'ine head atanir

		cout << student_num << " numarali ogrenci sona eklendi..." << endl;
	}

	return head;
}

struct student* bastan_sil(struct student* head) {

	system("cls");

	if (head == NULL)													// Eger listede dugum yoksa,Heap alanindan bellek tahsis edilmemisse
		cout << "Liste bos silme YAPILAMAZ..." << endl;

	else {																// Eger Heap alanindan bellek tahsis edilmisse,listede en az 1 dugum varsa

		if (head->next == head) {										// Eger listede 1 dugum varsa

			delete head;												// Dugum silinir
			head = NULL;												// Artik listede dugum kalmadigi icin head'e NULL atanir

			cout << "Son ogrenci bastan silme basarili..." << endl;
		}

		else {															// Eger listede 2 veya daha fazla dugum varsa

			struct student* temp1 = head;

			while (temp1->next != head) {								// Tek yonlu dairesel bagli listede son dugumun next'i ilk dugumu gosterir
				temp1 = temp1->next;									// Bastan silme yaptigimiz icin son dugumun next'i degismelidir.Bu sebeple son dugum bulunur
			}															// Dongu sonunda temp1 son dugumu gosterir

			struct student* temp2 = head->next;							// Listenin 2. dugumu temp2'ye atanir
			
			delete head;												// Ilk dugum silinir
			head = temp2;												// Ilk dugum bastan silindigi icin yeni ilk dugum temp2 (listenin eski 2. dugumu) olur
			temp1->next = head; 										// son dugumun next'i guncellenmelidir ve yeni head'i gostermelidir

			cout << "Bastan silme basarili..." << endl;
		}
	}

	return head;
}


struct student* aradan_sil(struct student* head, int student_num) {

	system("cls");

	bool flag = false;													// Aradan silmenin yapilip yapilamadigini kontrol eden flag

	if (head == NULL) {
		cout << "Liste bos aradan silme YAPILAMAZ..." << endl;
		flag = false;
	}
	else if (head->next == head) {
		cout << "Listede 1 dugum var aradan silme YAPILAMAZ en az 3 dugum olmali..." << endl;
		flag = false;
	}
	else if (head->next->next == head) {
		cout << "Listede 2 dugum var aradan silme YAPILAMAZ en az 3 dugum olmali..." << endl;
		flag = false;
	}

	else {

		struct student* temp1 = head;

		while (temp1->next != head) {									// Tum dugumlere bakilir
																		// temp1->next->student_number yazilarak eger silinmek istenen student_num listede varsa kosulu olusturuldu cunku
			if (temp1->next->student_number == student_num) {			// aradan silme yapilacagi icin dugum silinmek istenmeyecektir ve eger ilk dugum silinirse aradan silme basarisiz olur

				if (temp1->next->next == head) {						// Eger silinmek istenen student_num son dugume ait ise	

					cout << "Son ogrenci numarasi aradan SILINEMEZ lutfen aradan bir ogrenci numarasi seciniz..." << endl;
					flag = false;
				}

				else {													// Eger silinmek istenen student_num listede varsa ve student_num ilk dugumde ve son dugumde degilse

					struct student* temp2 = temp1->next->next;			// temp2'ye silinmek istenen student_num'a ait dugumden bir sonraki dugumun adresi atanir
																		// temp1'de ise silinmek istenen student_num'a ait dugumden bir oncekinin adresi vardir
					delete temp1->next;									// silinmek istenen student_num'a ait olan dugum silinir
					temp1->next = temp2;								// silinmek istenen dugumden bir onceki dugumun next'ine ,silinmek istenen dugumden bir sonraki dugumun adresi atanir

					flag = true;
					break;
				}
			}

			temp1 = temp1->next;
		}
	}

	if (flag)
		cout << student_num << " numarali ogrenci aradan silindi..." << endl;
	else
		cout << student_num << " numarali ogrenci aradan silme islemi BASARISIZ..." << endl;

	return head;
}


struct student* sondan_sil(struct student* head) {

	system("cls");

	if (head == NULL)													// Eger listede dugum yoksa,Heap alanindan bellek tahsis edilmemisse
		cout << "Liste bos silme YAPILAMAZ..." << endl;

	else {																// Eger Heap alanindan bellek tahsis edilmisse,listede en az 1 dugum varsa

		if (head->next == head) {										// Eger listede 1 dugum varsa

			delete head;												// Dugum silinir
			head = NULL;												// Artik listede dugum kalmadigi icin head'e NULL atanir

			cout << "Son ogrenci sondan silme basarili..." << endl;
		}

		else {															// Eger listede 2 veya daha fazla dugum varsa

			struct student* temp1 = head;

			while (temp1->next->next != head) {							// Bu dongunun sonunda temp1 degiskeni sondan bir onceki dugumun adresini tutar
				temp1 = temp1->next;
			}

			struct student* temp2 = temp1->next;						// temp2 degiskeni son dugumun adresini tutar

			delete temp2;												// Son dugum silinir
			temp1->next = head;											// Son dugum silindigi icin sondan bir onceki dugum artik yeni son dugum olur.Bu sebeple son dugumun next'i head olmalidir

			cout << "Sondan silme basarili..." << endl;
		}
	}

	return head;
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

	int student_num;
	int secim;

	while (true) {

		cout << "---------------------------------" << endl;
		cout << "1 -->> Sona Ekle " << endl;
		cout << "2 -->> Bastan Sil " << endl;
		cout << "3 -->> Aradan Sil " << endl;
		cout << "4 -->> Sondan Sil " << endl;
		cout << "5 -->> Yazdir " << endl;
		cout << "0 -->> Cikis" << endl;
		cout << "---------------------------------" << endl;

		cin >> secim;

		if (secim == 1) {
			cout << "Sona eklenmek istenen ogrencinin numarasi : ";
			cin >> student_num;
			head = sona_ekle(head, student_num);
		}
		else if (secim == 2) {
			head = bastan_sil(head);
		}
		else if (secim == 3) {
			cout << "Aradan silinmek istenen ogrencinin numarasi : ";
			cin >> student_num;
			head = aradan_sil(head, student_num);
		}
		else if (secim == 4) {
			head = sondan_sil(head);
		}
		else if (secim == 5) {
			display(head);
		}
		else if (secim == 0) {
			system("cls");
			cout << "Basariyla cikis yapildi..." << endl;
			return 0;
		}
		else {
			system("cls");
			cout << "Gecersiz sayi.. lutfen 1-5 arasinda bir sayi giriniz veya 0'a basarak programi sonlandiriniz... " << endl;
		}

	}

}

