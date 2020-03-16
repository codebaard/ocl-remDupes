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
	oFile *newFile = (oFile*)malloc(sizeof(oFile));

	newFile->path = (char*)malloc(sizeof(char)*strlen(path));
	newFile->filename = (char*)malloc(sizeof(char)*strlen(name));
	memset(newFile->hash, 0, HASH_LENGTH); //init array
	newFile->nextFile = NULL; //new end of list

	//copy contents
	strcpy(newFile->path, path);
	strcpy(newFile->filename, name);
	newFile->filesize = size;

	//initialize the pointer to this object in the previous one
	
	unsigned char *tmpBuffer = (unsigned char*)malloc(size * sizeof(unsigned char));

	//read the buffer
	if (f) {
		fseek(f, 0, SEEK_SET);
		fread(tmpBuffer, sizeof(unsigned char), size, f);
	}

	else {
		printf("File not opened...some error occured.");
	}

	newFile->buffer = tmpBuffer;
	fclose(f);

	return *newFile;
}

size_t determineFileSize(FILE *f) {

	fseek(f, 0, SEEK_END);    /* file pointer at the end of file */
	return ftell(f);   /* take a position of file pointer un size variable */
}

void appendFile(char *path, char *filename) {
	if (start == NULL) { //first element
		start = (oFile*)malloc(sizeof(oFile));
		FileBuffer = (filebuffer*)malloc(sizeof(filebuffer));
		*start = initFile(path, filename);
		ptrElement = start; //point to first element
		FileBuffer->elementCount = 1;
	}
	else {
		ptrElement->nextFile = (oFile*)malloc(sizeof(oFile));
		*ptrElement->nextFile = initFile(path, filename); //assign new element to "next" of previous
		ptrElement = ptrElement->nextFile; //assign to empty pointer of new last
		FileBuffer->elementCount++;
	}
}

void prepareFileBuffer() {

	//set up iterator
	oFile *iterator = (oFile*)malloc(sizeof(oFile));
	iterator = start;

	//set up filebuffer struct
	FileBuffer->imageBuf = (unsigned char**)malloc(sizeof(unsigned char)*FileBuffer->elementCount*ADRESS_SPACE_MAPPING);
	FileBuffer->hashBuf = (unsigned char**)malloc(sizeof(unsigned char)*FileBuffer->elementCount*ADRESS_SPACE_MAPPING);
	FileBuffer->FileBufferSize = 0;
	FileBuffer->HashBufferSize = 0;

	//iterate over list to fill openCL Host Buffer with addresses from LL
	while (iterator != NULL) {
		FileBuffer->imageBuf = &iterator->buffer;
		*FileBuffer->hashBuf = iterator->hash;
		FileBuffer->FileBufferSize += iterator->filesize * sizeof(unsigned char);
		FileBuffer->HashBufferSize += sizeof(unsigned char)*HASH_LENGTH;

		//next item
		FileBuffer->imageBuf++;
		FileBuffer->hashBuf++;
		iterator = iterator->nextFile;
	}

}