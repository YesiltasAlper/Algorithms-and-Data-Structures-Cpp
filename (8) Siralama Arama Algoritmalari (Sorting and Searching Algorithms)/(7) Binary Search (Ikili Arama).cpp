#include <iostream>

using namespace std;

#define		SIZE	5

void bubble_sort(int* array, int size) {

	cout << "*****Bubble sort oncesi*****" << endl;

	for (int i = 0; i < SIZE; i++)
		cout << array[i] << "   ";

	for (int i = 0; i < (SIZE - 1); i++) {

		for (int j = 0; j < (SIZE - 1 - i); j++) {

			if (array[j] > (array[j + 1])) {

				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	cout << endl << "*****Bubble sort sonrasi*****" << endl;

	for (int i = 0; i < SIZE; i++)
		cout << array[i] << "   ";

	cout << endl << endl;
}


bool binary_search(int* array, int sayi) {

	int first = 0;
	int last = SIZE - 1;
	int mid = (last + first) / 2;

	bool flag = false;

	while (first <= last) {

		if (array[mid] < sayi)
			first = mid + 1;

		else if (array[mid] == sayi) {
			flag = true;
			break;
		}

		else
			last = mid - 1;

		mid = (first + last) / 2;
	}

	if (first > last)
		flag = false;

	if (flag)
		cout << "Index : " << mid << endl;

	return flag;
}

int main() {

	int dizi[SIZE] = { 8,3,6,4,2};
	int sayi;

	cout << "Aranan sayi : ";
	cin >> sayi;

	bubble_sort(dizi, SIZE);

	bool flag = binary_search(dizi, sayi);

	if (flag)
		cout << "Aranan sayi " << sayi << " bulundu..." << endl;
	else
		cout << "Aranan sayi " << sayi << " bulunamadi..." << endl;

}

/*
	Binary search arama yaparken dizi sirali degilse once kucukten buyuge siralanir.
	Ortanca deger ile aranan sayi karsilastirilir
	Eger aranan sayi ortanca degerden buyukse,ortanca degerin soluna bakilmaz
	Eger aranan sayi ortanca degerden kucukse,ortanca degerin sagina bakilmaz
	Boylece aralik kucultulerek arama yapilir
*/
