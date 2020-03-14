#pragma once 

#include <stdio.h>
#include <stdlib.h>

typedef struct oFile {
	char *path;
	char *filename;
	unsigned char *buffer;
	size_t filesize;
	struct oFile *nextFile;
} oFile;

oFile *start; //list of file-structs
oFile *ptrElement; //ptr to several elements within list

oFile initFile(char *path, char *name);

void appendFile(char *path, char *filename);
extern void(*pAppendFile)(char*, char*);

void initList();

//void closeFiles(); //close all filestreams after finished operation

size_t determineFileSize(FILE *f);