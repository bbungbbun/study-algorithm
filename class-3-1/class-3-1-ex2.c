#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void merge (char** data, int start, int mid, int end);
void mergeSort (char** data, int start, int end);
void printArray (char** data, int length);

int main(void) {
	char* data[] = {"KOR", "ZAL", "ENG", "CAN", "AUS", "BAN", "MAL"};

	int dataSize = sizeof(data) / sizeof(char*);

	printf("Before Sorting: ");
	printArray(data, dataSize); 

	mergeSort(data, 0, dataSize - 1);

	printf("After Sorting: ");
	printArray(data, dataSize); 
	
	return 0;
}

void mergeSort (char** data, int start, int end){
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		mergeSort(data, start, mid);
		mergeSort(data, mid + 1, end);
		merge(data, start, mid, end);
	}
}

void merge (char** data, int start, int mid, int end){
	char** tempData;

	int numOfData = (end - start) + 1;
	int fi, ri, mi;

	tempData = (char**)malloc( sizeof(char*)*numOfData);
	if(tempData == NULL) return;

	fi = start;
	ri = mid + 1;
	mi = 0;

	while (mi < numOfData)
	{
		if (fi <= mid){
			if (ri <= end){
				if((strcmp(data[fi], data[ri]) < 0) ||
				   (strcmp(data[fi], data[ri]) == 0))
					tempData[mi++] = data[fi++];
				else 
					tempData[mi++] = data[ri++];
			} else
				tempData[mi++] = data[fi++];
		} else if (ri <= end)
			tempData[mi++] = data[ri++];
	}

	for (int i = 0; i < numOfData; i++)
		data[start + i] = tempData[i];

	free(tempData);	
}

void printArray (int* data, int length){
	int index;

	for (index = 0; index < length - 1; index++)
		printf("%s, \t", data[index]);
	printf("%s ] \n\n", data[index]);
}