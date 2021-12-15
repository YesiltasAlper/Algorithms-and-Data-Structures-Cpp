#include <iostream>

using namespace std;

#define		SIZE	5

void insertion_sort(int * array, int size) {

	cout << "*****Insertion sort oncesi*****" << endl;

	for (int i = 0; i < SIZE; i++)
		cout << array[i] << "   ";

	for (int i = 0; i < (SIZE - 1); i++) {

		for (int j = (i + 1); j > 0; j--) {

			if (array[j] < (array[j - 1])) {

				int temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
	}

	cout << endl << "*****Insertion sort sonrasi*****" << endl;

	for (int i = 0; i < SIZE; i++)
		cout << array[i] << "   ";

}


int main() {
	
	int dizi[SIZE] = { 8,4,6,2,3 };

	insertion_sort(dizi, SIZE);
}

/*

	dizi[5] = {8 , 4 , 6 , 2 ,3};

	dizi[0] = 8		dizi[1] = 4		dizi[2] = 6		dizi[3] = 2		dizi[4] = 3

	SIZE = Dizi boyutu = 5

	(i = 0)		1.dongu	 -->   [8  4]  6  2	 3	 -->   [4  8]  6  2	 3  		

	(i = 1)		2.dongu	 -->   [4  8  6]  2	 3   -->   [4  6  8]  2  3   -->   [4  6  8]  2  3    	   	  

	(i = 2)		3.dongu	 -->   [4  6  8  2]  3   -->   [4  6  2  8]  3   -->   [4  2  6  8]  3   -->   [2  4  6  8]  3  	  

	(i = 3)		4.dongu	 -->   [2  4  6  8  3]	 -->   [2  4  6  3  8]	 -->   [2  4  3  6  8]   -->   [2  3  4  6  8]   -->   [2  3  4  6  8]		     
*/

