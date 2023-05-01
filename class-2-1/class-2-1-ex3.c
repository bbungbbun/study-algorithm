#include<stdio.h>
#include<string.h>

void bubbleSort (char* data, const int size);
void printArray (char* data, const int size);

int main(void) {
	char* data[] = {"Tom", "Jane", "Peter", "Austine", "Bob"};

	const int dataSize = sizeof(data) / sizeof(char*);

	printArray(data, dataSize);
	bubbleSort(data, dataSize);
	printArray(data, dataSize);

	return 0;
}

void bubbleSort (char* data, const int size){
	int i, j;
	char* tmp;

	for(i = size - 1; i > 0; i--){
		for (j = 0; j <= i; j++)
		{
			if (strcmp(data[j], data[j+1]) > 0)
			{
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}

void printArray (char* data, const int size){

	int i;

	printf("[ ");
	for (i = 0; i < size - 1; i++)
	{
		printf("%s, ", data[i]);
	}
	printf("%s ]", data[i]);
	printf("\n");
}