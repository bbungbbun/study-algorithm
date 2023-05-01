#include<stdio.h>

void bubbleSort (int* data, const int size);
void printArray (int* data, const int size);

int main(void) {
	int data[] = {39, 2, 89, 45, 15};

	int dataSize = sizeof(data) / sizeof(int);

	printArray(data, dataSize); // 정렬 전
	bubbleSort(data, dataSize); // 버블 정렬
	printArray(data, dataSize); // 정렬 후

	return 0;
}

void bubbleSort (int* data, const int size){
	int i, j, tmp;
	for(i = size - 1; i > 0; i--){
		for (j = 0; j < i; j++)
		{
			if (data[j] > data[j + 1])
			{
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
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