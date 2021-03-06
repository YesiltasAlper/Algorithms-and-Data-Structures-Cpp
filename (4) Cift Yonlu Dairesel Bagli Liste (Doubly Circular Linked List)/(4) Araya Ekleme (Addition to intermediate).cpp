#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct student {
	int student_number;
	struct student* previous;
	struct student* next;
};


struct student* basa_ekle(struct student* head, int student_num) {

	system("cls");

	struct student* node = new student();								// Heap alaninda dugum olusturulur ve baslangic adresi node degiskenine atanir
	node->student_number = student_num;									// Dugum datalari girilir

	bool flag = false;													// Ayni ogrenci numarasinin girilip girilmedigini kontrol eden flag

	if (head == NULL) {													// Eger Heap alanindan bellek tahsis edilmemisse,henuz olusan dugum yoksa

		head = node;				    								// Artik dugum olustugu icin en bastaki dugumu gssteren head'e yeni olusan dugumun adresi atanir
		head->next = head;												// Listede henuz tek dugum oldugu icin olusan dugumun next'i yine head'i gosterir
		head->previous = head;											// Listede henuz tek dugum oldugu icin olusan dugumun previous'u head'i gosterir

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
		head->previous = node;											// Basa ekleme yapildigindan bastaki dugum degistigi icin head burada ikinci dugum olmustur.head'in previous'u ilk dugumu gostermelidir
		head = node;													// head guncellenir
		head->previous = temp2;											// En bastaki dugumun previous'u son dugumun adresini gosterir
		temp2->next = head;												// son dugumun next'i yeni olusan dugumun adresini tutar

		cout << student_num << " numarali ogrenci basa eklendi basarili..." << endl;
	}

	return head;
}


struct student* araya_ekle(struct student* head, int range_val, int student_num) {

	system("cls");

	int index_range_val = 0;											// Girilen range_val degerinin kacinci dugumde oldugunu bulur

	bool flag1 = false;													// Ayni ogrenci numarasinin girilip girilmedigini belirler
	bool flag2 = false;													// range_val durumlari icin tutulan flag

	if (head == NULL)													// Eger listede dugum yoksa,Heap alanindan bellek tahsis edilmemisse
		cout << "Liste bos araya ekleme YAPILAMAZ..." << endl;

	else if ((head->next == head) && (head->previous == head))
		cout << "Listede 1 dugum var araya ekleme YAPILAMAZ en az 2 dugum olmali..." << endl;

	else {																// Eger listede 2 veya daha fazla dugum varsa araya ekleme yapilabilir

		struct student* node = new student();							// Heap alaninda dugum olusturulur ve baslangic adresi node degiskenine atanir
		node->student_number = student_num;								// Dugum datalari girilir

		struct student* temp1 = head;
		int counter = 1;												// Kac tane dugum oldugu bulunur

		while (temp1->next != head) {									// Listede kac tane dugum sayisi oldugu bulunur
			counter++;
			temp1 = temp1->next;
		}

		temp1 = head;

		for (int i = 0; i < counter; i++) {

			if (temp1->student_number == student_num) {					// Eger student_num daha once girilmisse ayni student_num tekrar girilemeyecegi icin student_num degeri araya eklenemez

				flag1 = false;
				cout << student_num << " numarali ogrenci zaten var ayni ogrenci numarasi girilemez TEKRAR DENEYINIZ..." << endl;
				break;
			}

			else {														// student_num degeri daha once girilmemisse student_num degeri araya eklenebilir

				flag1 = true;
				temp1 = temp1->next;
			}
		}

		temp1 = head;

		for (int i = 0; i < counter; i++) {								// Tum dugumlere bakilir ve range_val durumlari kontrol edilir  

			if ((temp1->student_number == range_val) && (temp1->next != head)) {			// Eger range_val degeri var ise ve sonda degil ise bu durumda range_val degeri uygundur
				flag2 = true;
				index_range_val++;
				break;
			}

			else if ((temp1->student_number == range_val) && (temp1->next == head)) {		// Eger range_val degeri var ise ama sonda ise bu durumda range_val degeri uygun degildir
				flag2 = false;
				index_range_val++;
				cout << "Son dugume ekleme YAPILAMAZ..." << endl;
				break;
			}

			else {														// Eger range_val degeri listede yoksa bu durumda range_val degeri uygun degildir
				flag2 = false;
				index_range_val++;
				temp1 = temp1->next;
			}
		}

		if ((flag1 == true) && (flag2 == true)) {						// Eger student_num daha once girilmemisse ve range_val degeri listede varsa ve sonda degilse araya ekleme yapilir

			temp1 = head;
			struct student* temp2 = temp1->next;

			for (int i = 0; i < index_range_val - 1; i++) {				// Dongu sonunda temp1 degiskeni range_val'in oldugu dugumun adresini tutar.temp2 ise bu dugumden bir sonraki dugumu tutar
				temp1 = temp1->next;									// Bu iki dugum arasina olusturulan yeni dugum (node) eklenir
				temp2 = temp2->next;
			}

			temp1->next = node;											// range_val'in oldugu dugumun next'ine olusturulan yeni dugum atanir
			node->previous = temp1;										// Olusturulan node dugumunun previous'una range_val'in oldugu dugum atanir
			node->next = temp2;											// olusturulan dugumun next'ine temp2 atanir
			temp2->previous = node;										// Araya eklenen dugumun bir sonraki dugumunun previous'una araya eklenen dugumun adresi atanir

			cout << student_num << " numarali ogrenci araya eklendi..." << endl;
		}

		else {
			cout << student_num << " numarali ogrenci araya ekleme BASARISIZ..." << endl;
		}

	}

	return head;
}


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

	int secim;
	int student_num;
	int range_val;			// Sadece araya ekleme icin kullanilir.Araya eklenmek istenen student_num degerinin hangi student_num degeri sonrasi eklenecegini tutar

	while (true) {

		cout << "---------------------------------" << endl;
		cout << "1 -->> Basa ekle" << endl;
		cout << "2 -->> Araya ekle" << endl;
		cout << "3 -->> Sona ekle" << endl;
		cout << "4 -->> Yazdir" << endl;
		cout << "0 -->> Cikis" << endl;
		cout << "---------------------------------" << endl;

		cin >> secim;

		if (secim == 1) {
			cout << "Basa eklenmek istenen ogrencinin numarasi : ";
			cin >> student_num;
			head = basa_ekle(head, student_num);
		}
		else if (secim == 2) {
			cout << "Araya eklenmek istenen ogrencinin numarasi : ";
			cin >> student_num;
			cout << "Hangi ogrencinin numarasindan sonra eklensin : ";
			cin >> range_val;
			head = araya_ekle(head, range_val, student_num);
		}
		else if (secim == 3) {
			cout << "Sona eklenmek istenen ogrencinin numarasi : ";
			cin >> student_num;
			head = sona_ekle(head, student_num);
		}
		else if (secim == 4) {
			display(head);
		}
		else if (secim == 0) {
			system("cls");
			cout << "Basariyla cikis yapildi..." << endl;
			return 0;
		}
		else {
			system("cls");
			cout << "Gecersiz sayi.. lutfen 1-4 arasinda bir sayi giriniz veya cikis icin 0'a basiniz..." << endl;
		}

	}

}
