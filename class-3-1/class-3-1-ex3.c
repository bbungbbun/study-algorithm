#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Person
{
	char* name;
	int score;
};

void merge (struct Person* data, int start, int mid, int end);
void mergeSort (struct Person* data, int start, int end);
void printArray (struct Person* data, int length);

int main() {

	struct Person data[] = {
		{"James", 95 },
		{"Tom", 84 },
		{"Jerry", 100 },
		{"Peter", 71 },
		{"Zupiter", 64 },
		{"Abraham", 91 }
	};

	int dataSize = sizeof(data) / sizeof(struct Person);

	printf("Before Sorting: ");
	printArray(data, dataSize); 

	mergeSort(data, 0, dataSize - 1);

	printf("After Sorting: ");
	printArray(data, dataSize); 
	
	return 0;
}

void mergeSort (struct Person* data, int start, int end){
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		mergeSort(data, start, mid);
		mergeSort(data, mid + 1, end);
		merge(data, start, mid, end);
	}
}

void merge (struct Person* data, int start, int mid, int end){
	struct Person* tempData;

	int numOfData = (end - start) + 1;
	int fi, ri, mi;

	tempData = (struct Person*)malloc( sizeof(struct Person)*numOfData);
	if(tempData == NULL) return;

	fi = start;
	ri = mid + 1;
	mi = 0;

	while (mi < numOfData)
	{
		if (fi <= mid){
			if (ri <= end){
				if((strcmp(data[fi].name, data[ri].name) < 0) ||
				   (strcmp(data[fi].name, data[ri].name) == 0))
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

void printArray (struct Person* data, int length){
	int i;

	printf("[ ");

	for (i = 0; i < length - 1; i++)
		printf("(%s, %d), ", data[i].name, data[i].score);
	printf("(%s, %d)] \n\n ", data[i].name, data[i].score);
}