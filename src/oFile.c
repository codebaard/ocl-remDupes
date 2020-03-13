#include <stdio.h>
#include <stdlib.h>

#include "oFile.h"


oFile initFile(const char name[]) {

	FILE *f;
	size_t *buffer = (size_t*)malloc(MAX_FILE_SIZE * sizeof(size_t));
	int n;
	size_t size = MAX_FILE_SIZE;

	f = fopen(name, "rb");

	//read the buffer
	if (f) {
		n = fread(buffer, size, 1, f);
	}

	else {
		printf("File not opened...some error occured.");
	}

	//cast pointer to address of oFile obj and request memory
	oFile *newFile = (oFile*)malloc(sizeof(oFile));

	newFile->filename = name;
	newFile->fp = f;
	newFile->filesize = MAX_FILE_SIZE;

	//fclose(f);

	return *newFile;

}