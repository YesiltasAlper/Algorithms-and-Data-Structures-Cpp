#include <iostream>

using namespace std;

#define		SIZE		5

struct node {

	int number;
	struct node* next;
};

struct queue {
	int counter;
	struct node* front;
	struct node* rear;
};

void ilk_deger(struct queue* kuyruk) {

	kuyruk->counter = 0;
	kuyruk->rear = kuyruk->front = NULL;
}

void ekle(struct queue* kuyruk, int number) {

	system("cls");

	struct node* dugum = new node();
	dugum->number = number;

	if (kuyruk->counter == SIZE) {								// Kuyruk doluysa
		cout << "Kuyruk dolu..." << endl;
	}

	else if (kuyruk->counter == 0) {							// Kuyruk bossa

		dugum->next = NULL;

		kuyruk->front = kuyruk->rear = dugum;
		(kuyruk->counter)++;

		cout << "Ilk dugum olusturuldu ve " << number << " kuyruga eklendi..." << endl;
	}

	else {														// Kuyrukta en az 1 dugum varsa

		dugum->next = kuyruk->rear;

		kuyruk->rear = dugum;
		(kuyruk->counter)++;

		cout << "Dugum olusturuldu ve " << number << " kuyruga eklendi..." << endl;
	}
}

void sil(struct queue* kuyruk) {

	system("cls");

	if (kuyruk->counter == 0) {
		cout << "Kuyruk bos..." << endl;
	}

	else if (kuyruk->counter == 1) {

		cout << kuyruk->front->number << " kuyruktaki son dugum silindi..." << endl;

		delete kuyruk->front;									// Kuyruktaki son dugum silinir
		kuyruk->front = kuyruk->rear = NULL;					// Kuyrukta dugum kalmadigi icin front ve rear NULL gosterir
		(kuyruk->counter)--;
	}

	else {

		struct node* temp = kuyruk->rear;				

		while (temp->next->next != NULL) {						// Kuyruktaki front dugumden bir onceki dugum bulunur
			temp = temp->next;
		}

		cout << kuyruk->front->number << " kuyruktan silindi..." << endl;

		delete kuyruk->front;									// Kuyrugun basindaki dugum silinir
		kuyruk->front = temp;									// front guncellenir
		kuyruk->front->next = NULL;								// kuyrugun en basindaki dugumun next'i NULL olmalidir
		(kuyruk->counter)--;	
	}
}

void display(struct queue* kuyruk) {

	system("cls");

	if (kuyruk->counter == 0) {
		cout << "Kuyruk bos..." << endl;
	}

	else {

		struct node* temp = kuyruk->rear;

		while (temp->next != NULL) {

			cout << temp->number << " --->> ";
			temp = temp->next;
		}
		cout << temp->number << " --->> ";
	}

	cout << endl;
}

int main(){

	struct queue kuyruk;

	ilk_deger(&kuyruk);

	int sayi, secim;

	while (true) {
		cout << "----------------------------" << endl;
		cout << "KUYRUK (QUEUE) UYGULAMASI " << endl;
		cout << "1 -->> Ekle" << endl;
		cout << "2 -->> Sil" << endl;
		cout << "3 -->> Display" << endl;
		cout << "0 -->> Cikis" << endl;
		cout << "----------------------------" << endl;

		cin >> secim;

		if (secim == 1) {
			cout << "Kuyruga eklenmek istenen sayi : ";
			cin >> sayi;
			ekle(&kuyruk, sayi);
		}
		else if (secim == 2) {
			sil(&kuyruk);
		}
		else if (secim == 3) {
			display(&kuyruk);
		}
		else if (secim == 0) {
			system("cls");
			cout << "Cikis basarili...";
			return 0;
		}
		else {
			system("cls");
			cout << "Yanlis sayi girdiniz lutfen 1-3 arasinda bir sayi giriniz veya 0'a basarak cikis yapiniz..." << endl;
		}
	}
}


