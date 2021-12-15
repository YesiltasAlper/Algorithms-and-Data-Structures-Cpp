#include <iostream>

using namespace std;

void swap(int* x, int* y) {

	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int arr[], int first, int last) {

	int pivot = arr[last];      // son eleman pivot secildi
	int i = (first - 1);

	for (int j = first; j <= (last - 1); j++) {

		if (arr[j] < pivot) {

			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[last]);
	return (i + 1);
}


void quicksort(int arr[], int first, int last) {

	if (first < last) {

		int pivot_index = partition(arr, first, last);

		quicksort(arr, first, (pivot_index - 1));
		quicksort(arr, (pivot_index + 1), last);
	}
}


void printArray(int arr[], int size) {

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main() {

	int arr[] = { 15, 12, 13, 14, 6, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "*****Before Sorting*****" << endl;
	printArray(arr, size);

	quicksort(arr, 0, (size - 1));

	cout << "*****After Sorting*****" << endl;
	printArray(arr, size);
}


/*
quicksort(arr,0,5);      ve      size = 6'dir.

first = 0;      last = 5;


// **************************************** DONGU - 1 ***************************************************

pivot_index = partition(arr,0,5);

pivot = arr[5] = 10;
i = first - 1 = - 1;

j = 0;  j <= 4; j++;        (pivottan kucukler sola toplanir)

arr[0] = 15 < 10    false       i = -1
arr[1] = 12 < 10    false       i = -1
arr[2] = 13 < 10    false       i = -1
arr[3] = 14 < 10    false       i = -1
arr[4] = 6  < 10    true        i = 0

swap(&arr[i], &arr[j]);     -->>    swap(&arr[0], &arr[4]);

swap sonrasi    6   12  13  14  15  10  (pivottan kucukler sola toplandi sadece 6)

swap(&arr[i + 1], &arr[last]);  -->>    swap(&arr[1], &arr[5]);

swap sonrasi    6   10  13  14  15  12  (pivottan kucukler pivotun (10) solunda buyukler saginda)

return (i+1)    -->>    return (1)  (pivot index ile return)

quicksort(arr,first,(pivot_index-1))   -->>    quicksort(arr,0,(0));     first < last =  false

quicksort(arr,(pivot_index+1),last)    -->>    quicksort(arr,(2),5)      first < last =  true

// **************************************** DONGU - 2 ***************************************************

pivot_index = partition(arr,2,5);

pivot = arr[5] = 12;
i = first - 1 = 1;

j = 2;  j <= 4; j++;

arr[2] = 13 < 12    false       i = 1
arr[3] = 14 < 12    false       i = 1
arr[4] = 15 < 12    false       i = 1

swap(&arr[i + 1], &arr[last]);  -->>    swap(&arr[2], &arr[5]);

swap sonrasi    6   10  12  14  15  13  (pivottan kucukler pivotun (12) solunda buyukler saginda)

return (i+1)    -->>    return (2)  (pivot index ile return)

quicksort(arr,first,(pivot_index-1))   -->>    quicksort(arr,2,(1));     first < last =  false

quicksort(arr,(pivot_index+1),last)    -->>    quicksort(arr,(3),5)      first < last =  true

// **************************************** DONGU - 3 ***************************************************

pivot_index = partition(arr,3,5);

pivot = arr[5] = 13;
i = first - 1 = 2;

j = 3;  j <= 4; j++;

arr[3] = 14 < 13    false       i = 2
arr[4] = 15 < 13    false       i = 2

swap(&arr[i + 1], &arr[last]);  -->>    swap(&arr[3], &arr[5]);

swap sonrasi    6   10  12  13  15  14  (pivottan kucukler pivotun (13) solunda buyukler saginda)

return (i+1)    -->>    return (3)  (pivot index ile return)

quicksort(arr,first,(pivot_index-1))   -->>    quicksort(arr,3,(1));     first < last =  false

quicksort(arr,(pivot_index+1),last)    -->>    quicksort(arr,(4),5)      first < last =  true

// **************************************** DONGU - 4 ***************************************************

pivot_index = partition(arr,4,5);

pivot = arr[5] = 14;
i = first - 1 = 3;

j = 4;  j <= 4; j++;

arr[4] = 15 < 14    false       i = 3

swap(&arr[i + 1], &arr[last]);  -->>    swap(&arr[4], &arr[5]);

swap sonrasi    6   10  12  13  14  15  (pivottan kucukler pivotun (14) solunda buyukler saginda)

return (i+1)    -->>    return (4)  (pivot index ile return)

quicksort(arr,first,(pivot_index-1))   -->>    quicksort(arr,4,(1));     first < last =  false

quicksort(arr,(pivot_index+1),last)    -->>    quicksort(arr,(5),5)      first < last =  FALSE
*/
