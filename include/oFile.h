#pragma once 

#include <stdio.h>
#include <stdlib.h>

typedef struct oFile {
	char *path;
	char *filename;
	unsigned char *buffer;
	char *MD5hash[32];
	size_t filesize;
	struct oFile *nextFile;
} oFile;

oFile *start; //list of file-structs
oFile *ptrElement; //ptr to several elements within list

oFile initFile(char *path, char *name);

void appendFile(char *path, char *filename);
size_t getElementCount();

extern void(*pAppendFile)(char*, char*);
//extern size_t(*pGetElementCount)();

//void closeFiles(); //close all filestreams after finished operation

size_t determineFileSize(FILE *f);