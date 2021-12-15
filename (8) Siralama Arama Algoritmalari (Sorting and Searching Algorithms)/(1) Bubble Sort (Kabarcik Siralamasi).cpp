#include <iostream>

using namespace std;

#define		SIZE	5

void bubble_sort(int * array, int size) {

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

}


int main() {
	
	int dizi[SIZE] = { 8,3,6,4,2 };

	bubble_sort(dizi, SIZE);
}

/*
	Bubble sort siralamasi en buyuk olan elemani bulur ve en saga atar.

	dizi[5] = {8 , 3 , 6 , 4 ,2};

	dizi[0] = 8		dizi[1] = 3		dizi[2] = 6		dizi[3] = 4		dizi[4] = 2

	SIZE = Dizi boyutu = 5

	(i = 0)		1.dongu	 -->   3  8  6  4  2		3  6  8  4  2		3  6  4  8  2		3  6  4  2  8		en son array[3] ve array[4] ' u kiyaslar

	(i = 1)		2.dongu	 -->   3  6  4  2  8		3  4  6  2  8		3  4  2  6  8							en son array[2] ve array[3] ' u kiyaslar

	(i = 2)		3.dongu	 -->   3  4  2  6  8		3  2  4  6  8												en son array[1] ve array[2] ' u kiyaslar

	(i = 3)		4.dongu	 -->   2  3  4  6  8																	en son array[0] ve array[1] ' u kiyaslar
*/

