#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "oFile.h"


oFile initFile(const char *path, const char *name) {

	FILE *f;
	f = fopen(path, "rb");

	size_t size = determineFileSize(f);

	//cast pointer to address of oFile obj and request memory
	size_t objSize = size * sizeof(size_t) + sizeof(char)*strlen(path) + sizeof(char)*strlen(name) + sizeof(size_t);
	oFile *newFile = (oFile*)malloc(objSize);

	newFile->path = path;
	newFile->filename = name;
	newFile->filesize = size;
	
	size_t *tmpBuffer = (size_t*)malloc(size * sizeof(size_t));

	//read the buffer
	if (f) {
		fseek(f, 0, SEEK_SET);
		fread(tmpBuffer, sizeof(size_t), size, f);
	}

	else {
		printf("File not opened...some error occured.");
	}

	newFile->buffer = tmpBuffer;
	fclose(f);

	return *newFile;
}

size_t determineFileSize(FILE *f) {

	fseek(f, 0, 2);    /* file pointer at the end of file */
	return ftell(f);   /* take a position of file pointer un size variable */
}

