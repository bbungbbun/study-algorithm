#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define BFRSIZE 4

#define RCDRSIZE (sizeof(int))

struct fileInfo
{
	FILE* fp;
	char fname[100];
	int min;
	int is_eof;
};

void bubbleSort (int* buf, int buflen);

int main(void) {

	int i, f;

	FILE* srcFile, *dstFile;

	int dataArr[8] = {80, 50, 10, 40, 20, 60, 70, 30};

	int length = sizeof(dataArr) / sizeof(int);

	srcFile = fopen("c://temp//src.data", "wb");
	fwrite(dataArr, sizeof(int), length, srcFile);
	fclose(srcFile);

	srcFile = fopen("c://temp//src.data", "rb");
	dstFile = fopen("c://temp//src.data", "wb");

	fseek(srcFile, 0L, SEEK_END);

	int rcdNumber = (int)(ftell(srcFile) / RCDRSIZE);

	int fNumber = rcdNumber / BFRSIZE + 1;

	struct fileInfo* tmpFiles 
	= (struct fileInfo*) malloc(sizeof(struct fileInfo)*fNumber);
	
	if (tmpFiles == NULL) return 0;

	int* buffer = (int*)malloc(RCDRSIZE * BFRSIZE);
	if(buffer == NULL) return 0;

	for (i = 0; i < fNumber; i++)
	{
		sprintf(tmpFiles[i].fname, "%stmp_%d.data", "C://temp//", i);
		tmpFiles[i].fp = fopen(tmpFiles[i].fname, "wb");
		tmpFiles[i].min = 0;
		tmpFiles[i].is_eof = 0
	}
	
	fseek(srcFile, 0L, SEEK_SET);

	for (f = 0; f < fNumber; f++)
	{
		fread(buffer, RCDRSIZE, BFRSIZE, srcFile);
		bubbleSort(buffer, BFRSIZE);
		fwrite(buffer, RCDRSIZE, BFRSIZE, tmpFiles[f].fp);
	}

	fread(buffer, RCDRSIZE, rcdNumber % BFRSIZE, srcFile);
	bubbleSort(buffer, rcdNumber % BFRSIZE);
	fwrite(buffer, RCDRSIZE, rcdNumber % BFRSIZE, tmpFiles[f].fp);

	for (f = 0; f < fNumber; f++) 
		fclose(tmpFiles[f].fp);

	for (f = 0; f < fNumber; f++)
		tmpFiles[f].fp = fopen(tmpFiles[f].name, "rb")

	rewind(dstFile);

	int minFile = 0;
	int minValue = 0;
	int frByte;

	for (f = 0; f < fNumber; f++){
		rewind();
		frbyte = fread(&(),RCDRSIZE)
	}
	return 0;
}

void bubbleSort (int* data, int start, int end){

	if (start >= end) return;

	int P, PE, FLE, temp;

	P = start;
	FG = start + 1;
	FLE = end;

	while (FG <= FLE)
	{
		while ((data[FG] <= data[P]) && (FG <= end)) FG++;
		while ((data[FLE] > data[P]) && (FG >= start)) FLE++;
		if (FG >= FLE) break;
		else {
			temp = data[FG];
			data[FG] = data[FLE];
			data[FLE] = temp
		}
		
		temp = data[FLE];
		data[FLE] = data[P];
		data[P] = temp;

		bubbleSort(data, start, FLE - 1);
		bubbleSort(data, FLE + 1, end);
	}
}
