#include<stdio.h>
#include<string.h>

void selectionSort (char* data, const int size);
void printArray (char* data, const int size);

int main(void) {
	char* data[] = {"Tom", "Jane", "Peter", "Austine", "Bob"};

	const int dataSize = sizeof(data) / sizeof(char*);

	printf("정렬 전: ");
	printArray(data, dataSize);

	selectionSort(data, dataSize);

	printf("정렬 후: ");
	printArray(data, dataSize);

	return 0;
}

void selectionSort (char* data, const int size){
	int i, j, max;
	char* temp;

	for(i = size - 1; i > 0; i--){
		max = i;

		for (j = 0; j <= i; j++)
		{
			if (strcmp(data[j], data[max]) > 0)
			{
				max = j;
			}
		}
		
		temp = data[max];
		data[max] = data[i];
		data[i] = temp;
	}
}

void printArray (char* data, const int size){

	int i;

	printf("[ ");
	for (i = 0; i < size - 1; i++)
	{
		printf("%s, ", data[i]);
	}
	printf("%s \\n\n", data[i]);
	printf("\n");
}