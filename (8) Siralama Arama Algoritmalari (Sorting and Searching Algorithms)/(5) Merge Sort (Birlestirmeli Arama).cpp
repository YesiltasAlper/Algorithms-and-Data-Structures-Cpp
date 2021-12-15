#include <iostream>

using namespace std;

int arr[] = { 8,3,2,6,4,1,5,7 };

#define		SIZE	(sizeof(arr) / sizeof(arr[0]))

void merge(int first, int middle, int last) {

	int temp[SIZE];

	int i = 0, j = 0, k = 0;

	for (i = first; i < SIZE; i++)
		temp[i] = arr[i];

	i = k = first;
	j = middle + 1;

	while (i <= middle && j <= last) {

		if (temp[i] <= temp[j])
			arr[k++] = temp[i++];
		else
			arr[k++] = temp[j++];
	}

	while (i <= middle)
		arr[k++] = temp[i++];
}

void sort(int first, int last) {

	if (first < last) {

		int middle = (first + last) / 2;

		sort(first, middle);
		sort(middle + 1, last);
		merge(first, middle, last);
	}
}

int main() {

	sort(0, SIZE - 1);

	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << "  ";
}

/*
	arr[] = { 8,3,2,6,4,1,5,7 };

	8	3	2	6	4	1	5	7

	8	3	2	6		4	1	5	7

	8	3		2	6		4	1		5	7

	8		3		2		6		4		1		5		7

	3	8		2	6		1	4		5	7

	2	3	6	8		1	4	5	7

	1	2	3	4	5	6	7	8

*/
