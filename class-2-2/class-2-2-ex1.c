#include<stdio.h>
#include<string.h>

void insertionSort (int* data, const int size);
void printArray (int* data, const int size);

int main(void) {
	int data[] = {39, 2, 80, 45, 15};

	const int dataSize = sizeof(data) / sizeof(int);

	printArray(data, dataSize); // 정렬 전 배열 출력
	insertionSort(data, dataSize); // 삽입 정렬 실행
	printArray(data, dataSize); // 정렬 후 배열 출력

	return 0;
}

void insertionSort (int* data, const int size){
	int i, j, isrt;

	for(i = 1; i <= size; i++){
		isrt = data[i];
		j = i - 1;

		while ( j >= 0 && isrt < data[j]){
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = isrt; 
	}
}

void printArray (int* data, const int size){
	printf("[ ");
	for (int i = 0; i < size - 1; i++)
	{
		printf("%d, ", data[i]);
	}
	printf("%d", data[size - 1]);
	printf("\n");
}