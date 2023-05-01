#include<stdio.h>
#include<stdlib.h>

void merge (int* data, int start, int mid, int end);
void mergeSort (int* data, int start, int end);
void printArray (int* data, int numOfElements);

int main(void) {
	int data[] = {37, 10, 22, 30, 35, 13, 25, 24};

	int dataSize = sizeof(data) / sizeof(int);

	printArray(data, dataSize); // 정렬 전 배열 출력
	mergeSort(data, 0, dataSize - 1); // 병합 정렬
	printArray(data, dataSize); // 정렬 후 배열 출력

	return 0;
}

void mergeSort (int* data, int start, int end){
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		mergeSort(data, start, mid);
		mergeSort(data, mid + 1, end);
		merge(data, start, mid, end);
	}
}

void merge (int* data, int start, int mid, int end){
	int* tempData;

	int numOfData = (end - start) + 1;
	int fi, ri, mi;

	tempData = (int*)malloc( sizeof(int)*numOfData);
	if(tempData == NULL) return;

	fi = start;
	ri = mid + 1;
	mi = 0;

	while (mi < numOfData)
	{
		if (data[fi] <= data[ri])
		{
			if (fi <= mid) tempData[mi++] = data[fi++];
			else tempData[mi++] = data[ri++];
		} else
		{
			if (ri <= end) tempData[mi++] = data[ri++];
			else tempData[mi++] = data[fi++];
		}
	}

	for (int i = 0; i < numOfData; i++)
		data[start + i] = tempData[i];

	free(tempData);	
	
}

void printArray (int* data, int numOfElements){
	int index;

	for (index = 0; index < numOfElements; index++)
		printf("%d, \t", data[index]);
	printf("\n");
}