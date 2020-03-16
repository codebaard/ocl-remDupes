#pragma once 

#include <stdio.h>
#include <stdlib.h>

#define HASH_LENGTH 33 //MD5 + '\0'

// Check address space
#if _WIN32 || _WIN64
	#if _WIN64
		#define ENV64BIT
	#else
		#define ENV32BIT
	#endif
#endif

#if defined(ENV64BIT)
	#define ADRESS_SPACE_MAPPING 8
#elif defined(ENV32BIT)
	#define ADRESS_SPACE_MAPPING 4
#endif

typedef struct oFile {
	char *path;
	char *filename;
	unsigned char *buffer;
	unsigned char hash[HASH_LENGTH];
	size_t filesize;
	struct oFile *nextFile;
} oFile;

typedef struct filebuffer {
	size_t elementCount;
	size_t FileBufferSize;
	size_t HashBufferSize;
	unsigned char **imageBuf;
	unsigned char **hashBuf;
} filebuffer;

oFile *start; //list of file-structs
oFile *ptrElement; //ptr to several elements within list

filebuffer *FileBuffer;

oFile initFile(char *path, char *name);
void appendFile(char *path, char *filename);

extern void(*pAppendFile)(char*, char*);
//extern size_t(*pGetElementCount)();
void prepareFileBuffer();

//void closeFiles(); //close all filestreams after finished operation

size_t determineFileSize(FILE *f);