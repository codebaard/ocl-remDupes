#pragma once 

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 10000000

typedef struct oFile {
	const char *filename;
	FILE *fp;
	size_t filesize;
} oFile;

oFile *files;

oFile initFile(const char *name);

void closeFiles(); //close all filestreams after finished operation