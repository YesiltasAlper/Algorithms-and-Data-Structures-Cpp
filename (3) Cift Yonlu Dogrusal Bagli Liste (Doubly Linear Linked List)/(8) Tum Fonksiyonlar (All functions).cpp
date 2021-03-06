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

		head = node;				    								// Artik dugum olustugu icin en bastaki dugumu gosteren head'e yeni olusan dugumun adresi atanir
		head->next = NULL;												// Listede henuz tek dugum oldugu icin olusan dugumun next'ine NULL atanir
		head->previous = NULL;											// Listede henuz tek dugum oldugu icin olusan dugumun previous'una NULL atanir

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
		head->previous = node;											// Burada head artik listenin 2.dugumudur.Bu sebeple head'in previous'una yeni olusan dugum adresi atanir
		head = node;													// head guncellenir
		head->previous = NULL;											// En bastaki dugumun previous'una NULL atanir

		cout << student_num << " numarali ogrenci basa eklendi..." << endl;
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

	else if ((head->next == NULL) && (head->previous == NULL))
		cout << "Listede 1 dugum var araya ekleme YAPILAMAZ en az 2 dugum olmali..." << endl;

	else {																// Eger listede 2 veya daha fazla dugum varsa araya eklenebilir

		struct student* node = new student();							// Heap alaninda dugum olusturulur ve baslangic adresi node degiskenine atanir
		node->student_number = student_num;								// Dugum datalari girilir

		struct student* temp1 = head;

		while (temp1 != NULL) {											// Listedeki tum dugumlere bakilir

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

		while (temp1 != NULL) {											// Tum dugumlere bakilir ve range_val durumlari kontrol edilir  

			if ((temp1->student_number == range_val) && (temp1->next != NULL)) {			// Eger range_val degeri var ise ve sonda degil ise bu durumda range_val degeri uygundur

				flag2 = true;
				index_range_val++;
				break;
			}

			else if ((temp1->student_number == range_val) && (temp1->next == NULL)) {		// Eger range_val degeri var ise ama sonda ise bu durumda range_val degeri uygun degildir

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

			for (int i = 0; i < index_range_val - 1; i++) {				// Dongu sonunda temp1 degiskeni range_val'in oldugu dugumun adresini tutar.temp2 bu dugumden bir sonraki dugumu tutar
				temp1 = temp1->next;									// Bu iki dugum arasina olusturulan yeni dugum (node) eklenir.
				temp2 = temp2->next;
			}

			temp1->next = node;											// range_val'in oldugu dugumun next'ine olusturdugumuz dugum atanir
			node->previous = temp1;										// Olusturulan node dugumunun previous'una range_val'in oldugu dugum atanir
			node->next = temp2;											// olusan dugumun next'ine temp2 atanir
			temp2->previous = node;										// Araya eklenen dugumun bir sonraki dugumunun previous'una araya eklenen dugum adresi atanir

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

		head = node;				    								// Artik dugum olustugu icin en bastaki dugumu gosteren head'e yeni olusan dugumun adresi atanir
		head->previous = NULL;											// Listede henuz tek dugum oldugu icin olusan dugumun previous'una NULL atanir
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

		temp2->next = node;												// Listedeki son dugumun (temp2) next'ine olusan dugum atanir ve son dugum node olarak guncellenir
		node->previous = temp2;											// Olusan dugumun previous'una eski son dugumun adresi atanir
		node->next = NULL;												// Olusan yeni dugum sona eklendigi icin next'ine NULL atanir

		cout << student_num << " numarali ogrenci sona eklendi..." << endl;
	}

	return head;
}

struct student* bastan_sil(struct student* head) {

	system("cls");

	if (head == NULL)													// Eger listede dugum yoksa,Heap alanindan bellek tahsis edilmemisse
		cout << "Liste bos silme YAPILAMAZ..." << endl;

	else {																// Eger Heap alanindan bellek tahsis edilmisse,listede en az 1 dugum varsa

		if ((head->previous == NULL) && (head->next == NULL)) {			// Eger listede 1 dugum varsa

			delete head;												// Dugum silinir 
			head = NULL;												// Artik listede dugum kalmadigi icin head'e NULL atanir

			cout << "Son ogrenci bastan silme basarili..." << endl;
		}

		else {															// Eger listede 2 veya daha fazla dugum varsa

			struct student* temp = head->next;							// Listenin 2. dugumu temp'e atanir

			delete head;												// Ilk dugum silinir
			head = temp;												// Ilk dugum bastan silindigi icin yeni ilk dugum temp (listenin eski 2. dugumu) olur
			head->previous = NULL;										// Ilk dugumun previous'u NULL gostermelidir bu yuzden head'in previous'una NULL atanmalidir.

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
	else if ((head->previous == NULL) && (head->next == NULL)) {
		cout << "Listede 1 dugum var aradan silme YAPILAMAZ en az 3 dugum olmali..." << endl;
		flag = false;
	}
	else if ((head->previous == NULL) && (head->next->next == NULL)) {
		cout << "Listede 2 dugum var aradan silme YAPILAMAZ en az 3 dugum olmali..." << endl;
		flag = false;
	}

	else {

		struct student* temp1 = head;

		while (temp1->next != NULL) {									// Tum dugumlere bakilir
																		// temp1->next->student_number yazilarak eger silinmek istenen student_num listede varsa kosulu olusturuldu cunku
			if (temp1->next->student_number == student_num) {			// aradan silme yapilacagi icin dugum silinmek istenmeyecektir ve eger ilk dugum silinirse aradan silme basarisiz olur

				if (temp1->next->next == NULL) {						// Eger silinmek istenen student_num son dugume ait ise	

					cout << "Son ogrenci numarasi aradan SILINEMEZ lutfen aradan bir ogrenci numarasi seciniz..." << endl;
					flag = false;
				}

				else {													// Eger silinmek istenen student_num listede varsa ve student_num ilk dugumde ve son dugumde degilse

					struct student* temp2 = temp1->next->next;			// temp2'ye silinmek istenen student_num'a ait dugumden bir sonraki dugumun adresi atanir
					struct student* temp3 = temp1->next->next->previous;// temp3 degiskeni,silinmek istenen student_num degiskenine sahip olan dugumden bir sonraki dugumun previous'unu tutar

					delete temp1->next;									// silinmek istenen student_num'a ait olan dugum silinir
					temp1->next = temp2;								// silinmek istenen dugumden bir onceki dugumun next'ine ,silinmek istenen dugumden bir sonraki dugumun adresi atanir
					temp3 = temp1;										// silinmek istenen dugumden bir sonraki dugumun previous'una,silinmek istenen dugumden bir onceki dugumun adresi atanir

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

		if ((head->previous == NULL) && (head->next == NULL)) {			// Eger listede 1 dugum varsa

			delete head;												// Dugum silinir
			head = NULL;												// Artik listede dugum kalmadigi icin head'e NULL atanir

			cout << "Son ogrenci sondan silme basarili..." << endl;
		}

		else {															// Eger listede 2 veya daha fazla dugum varsa

			struct student* temp1 = head;

			while (temp1->next->next != NULL) {							// Bu dongunun sonunda temp1 degiskeni sondan bir onceki dugumun adresini tutar
				temp1 = temp1->next;
			}

			struct student* temp2 = temp1->next;						// temp2 degiskeni son dugumun adresini tutar

			delete temp2;												// Son dugum silinir
			temp1->next = NULL;											// Son dugum silindigi icin sondan bir onceki dugum artik yeni son dugum olur.Bu sebeple son dugumun next'i NULL olmalidir

			cout << "Sondan silme basarili..." << endl;
		}
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

	struct student* temp = head;

	while (temp != NULL) {

		if (temp->student_number == student_num) {

			flag = true;
			break;
		}

		else {

			flag = false;
			temp = temp->next;
		}

		index += 1;
	}

	if (flag)
		cout << student_num << " numarali ogrenci bulundu " << "ve dugum numarasi : " << index << endl;

	else
		cout << student_num << " numarali ogrenci BULUNAMADI..." << endl;

	return flag;
}

void display(struct student* head) {

	system("cls");

	if (head == NULL)
		cout << "Liste bos gosterilecek ogrenci numarasi YOK..." << endl;

	else {

		struct student* temp = head;

		while (temp->next != NULL) {
			cout << temp->student_number << "    ";
			temp = temp->next;
		}

		cout << temp->student_number << "    " << endl;
	}
}

int main() {

	struct student* head = NULL;

	int student_num;
	int range_val;			// Sadece araya ekleme icin kullanilir.Araya eklenmek istenen student_num degerinin hangi student_num degeri sonrasi eklenecegini tutar
	int secim;

	while (true) {

		cout << "---------------------------------" << endl;
		cout << "1 -->> Basa Ekle " << endl;
		cout << "2 -->> Araya Ekle " << endl;
		cout << "3 -->> Sona Ekle " << endl;
		cout << "4 -->> Bastan Sil " << endl;
		cout << "5 -->> Aradan Sil " << endl;
		cout << "6 -->> Sondan Sil " << endl;
		cout << "7 -->> Arama Yap " << endl;
		cout << "8 -->> Yazdir " << endl;
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
		else if (secim == 4)
			head = bastan_sil(head);

		else if (secim == 5) {
			cout << "Aradan silinmek istenen ogrencinin numarasi : ";
			cin >> student_num;
			head = aradan_sil(head, student_num);
		}
		else if (secim == 6)
			head = sondan_sil(head);

		else if (secim == 7) {
			cout << "Aranmak istenen ogrencinin numarasi : ";
			cin >> student_num;
			bool flag = arama(head, student_num);
		}
		else if (secim == 8)
			display(head);

		else if (secim == 0) {
			system("cls");
			cout << "Basariyla cikis yapildi..." << endl;
			return 0;
		}
		else {
			system("cls");
			cout << "Gecersiz sayi.. lutfen 1-8 arasinda bir sayi giriniz veya 0'a basarak programi sonlandiriniz... " << endl;
		}
	}
}
