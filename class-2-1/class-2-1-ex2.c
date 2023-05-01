#include<stdio.h>

void selectionSort (int* data, const int size);
void printArray (int* data, const int size);

int main(void) {
	int data[] = {39, 2, 89, 45, 15};

	const int dataSize = sizeof(data) / sizeof(int);

	printArray(data, dataSize); // 정렬 전 출력
	selectionSort(data, dataSize); // 선택 정렬
	printArray(data, dataSize); // 정렬 후 출력

	return 0;
}

void selectionSort (int* data, const int size){
	int i, j, max, temp;
	for(i = size - 1; i > 0; i--){
		max = i;

		for (j = 0; j <= i; j++)
		{
			if (data[j] > data[max])
			{
				max = j;
			}
		}

		temp = data[max];
		data[max] = data[i];
		data[i] = temp;
	}
}

void printArray (int* data, const int size){
	printf("[ ");
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", data[i]);
	}
	printf("%d ]", data[size - 1]);
	printf("\n");
}