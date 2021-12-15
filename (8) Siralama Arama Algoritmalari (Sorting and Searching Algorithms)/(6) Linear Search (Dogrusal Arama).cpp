#include <iostream>

using namespace std;

#define		SIZE	5

bool linear_search(int* array, int sayi, int* index) {

	bool flag = false;

	for (int i = 0; i < SIZE; i++) {

		if (array[i] == sayi) {
			flag = true;
			break;
		}

		(*index)++;
	}

	return flag;
}

int main() {

	int dizi[SIZE] = { 8,4,6,2,3 };
	int sayi;
	int index = 0;

	cout << "Aranan sayi : ";
	cin >> sayi;

	bool flag = linear_search(dizi, sayi, &index);

	if (flag)
		cout << "Aranan sayi " << sayi << " bulundu ve index : " << index;
	else
		cout << "Aranan sayi " << sayi << " bulunamadi...";
}

