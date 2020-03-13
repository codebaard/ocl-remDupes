#include <stdio.h>
#include <stdlib.h>

#include <CL/cl.h>
#include "oFile.h"

int main(int argc, char *argv[]) {

	//load all jpgs into struct and create a linked list
	char filename[] = "D:\\dev\\ocl-remDupes\\ocl-remDupes\\bin\\Debug\\IMG_0631.JPG";

	files = (oFile*)malloc(MAX_FILES * sizeof(oFile));
	
	for (int i = 0; i < MAX_FILES; i++) {
		files[i] = initFile(filename);
	}

	printf("Press Any Key to Continue\n");
	getchar();

	free(files);

	return 0;
}
