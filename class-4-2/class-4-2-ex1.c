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

	for (f = 0; f < fNumber - 1; f++)
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
		rewind(tmpFiles[f].fp);
		frbyte = fread(&(tmpFiles[f].fp),RCDRSIZE,1,tmpFiles[f].fp);
		if(frByte == 0) tmpFiles[f].is_eof = 1;
	}

	int done;

	while (1)
	{
		done = 1;
		for(f=0; f< fNumber; f++)
			if (tmpFiles[f].is_eof) done = 0;

		if(done) break;
		minFile = 0;
		for (f = 0; f < fNumber; f++)
		{
			if (tmpFiles[f].is_eof == 1) continue;
			else{
				minFile = f;
				break;
			}
		}
		for (f = 0; f < fNumber; f++){
			if (tmpFiles[f].is_eof == 1) continue;
			else if(tmpFiles[minFile].min > tmpFiles[f].min)
			{
				minFile = f;
			}
		}

		fwrite(&(tmpFiles[minFile].min),RCDRSIZE, 1, dstFile);

		frByte = fread(&(tmpFiles[minFile].min), RCDRSIZE, 1, tmpFiles[minFile].fp);

		if (frByte == 0) tmpFiles[minFile].is_eof = 1;
			
	} // end of while

	for (f = 0; f < fNumber; f++){
		fclose(tmpFiles[f].fp);
		_unlink(tmpFiles[f].fname);
	}

	fclose(dstFile);

	free(tmpFiles);
	
	int data;

	srcFile = fopen("c://temp//src.data", "rb");

	printf("srcFile: ");

	for (i = 0; i < rcdNumber; i++)
	{
		fread(&data, RCDRSIZE, 1, srcFile);
		printf(" %d", data);
	}

	printf("\n\n");

	fclose(srcFile);

	dstFile = fopen("c://temp//dst.data", "rb")

	printf("dstFile: ");

	for (i = 0; i < rcdNumber; i++)
	{
		fread(&data, RCDRSIZE, 1, dstFile);
		printf(" %d", data);
	}
	
	printf("\n\n");

	fclose(dstFile);

	return 0;
}

void bubbleSort (int* buf, int buflen){
	int i, j, tmp;

	for (i = buflen - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (buf[j] > buf[j + 1])
			{
				tmp = buf[j];
				buf[j] = buf[j + 1];
				buf[j + 1] = tmp;
			}
			
		}
		
	}
	
}
