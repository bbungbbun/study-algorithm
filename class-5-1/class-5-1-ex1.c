#include<stdio.h>

#define HSIZE 20

void shellSort (int* data, const int size);
void printArray (int* data, const int size);

int main(void) {
	int data[] = {39, 2, 80, 45, 15};

	int dataSize = sizeof(data) / sizeof(int);

	printArray(data, dataSize); // 정렬 전 배열 출력
	shellSort(data, 0, dataSize - 1); // 쉘 정렬
	printArray(data, dataSize); // 정렬 후 배열 출력

	return 0;
}

void shellSort (int* data, const int size){

	int gap, i, j, isrt;

	for (gap = size / 2; 1 <= gap; gap /= 2)
	{
		for (i = gap; i < size; i++)
		{
			isrt = data[i];
			j = i - gap;

			while (j >= 0 && isrt < data[j])
			{
				data[j + gap] = data[j];
				j -= gap;
			}
			data[j + gap] = isrt;
		}
	}
}

void printArray (int* data, const int size){
	printf("[ ");
	for (int i = 0; i < size - 1; i++)
	{
		printf("%d, ", data[i]);
	}
	
	printf("%d ]", data[size - 1]);
	printf("\n");
}