#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "oFile.h"

void(*pAppendFile)(char*, char*) = appendFile;
//size_t(*pGetElementCount)() = getElementCount;

oFile initFile(char *path, char *name) {

	FILE *f;
	f = fopen(path, "rb");

	size_t size = determineFileSize(f);

	//cast pointer to address of oFile obj and request memory
	//size_t objSize = size * sizeof(size_t) + sizeof(char)*strlen(path) + sizeof(char)*strlen(name) + sizeof(size_t);
	//oFile *newFile = (oFile*)malloc(objSize);
	oFile *newFile = (oFile*)malloc(sizeof(oFile));

	newFile->path = (char*)malloc(sizeof(char)*strlen(path));
	newFile->filename = (char*)malloc(sizeof(char)*strlen(name));
	//newFile->nextFile = (oFile*)malloc(sizeof(oFile));
	newFile->nextFile = NULL; //end of list

	//copy contents
	strcpy(newFile->path, path);
	strcpy(newFile->filename, name);
	newFile->filesize = size;

	//initialize the pointer to this object in the previous one
	
	unsigned char *tmpBuffer = (unsigned char*)malloc(size * sizeof(unsigned char));

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

void appendFile(char *path, char *filename) {
	if (start == NULL) { //first element
		start = (oFile*)malloc(sizeof(oFile));
		*start = initFile(path, filename);
		ptrElement = start; //point to first element
	}
	else {
		ptrElement->nextFile = (oFile*)malloc(sizeof(oFile));
		*ptrElement->nextFile = initFile(path, filename); //assign new element to "next" of previous
		ptrElement = ptrElement->nextFile; //assign to empty pointer of new last
	}
}

size_t getElementCount() {
	
	size_t counter = 0;
	oFile *iterator = (oFile*)malloc(sizeof(oFile)); 
	iterator = start;

	while (iterator != NULL) {
		counter++;
		iterator = iterator->nextFile;
	}

	return counter;
}