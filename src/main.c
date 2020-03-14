#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <CL/cl.h>
#include "oFile.h"
#include "path.h"
#include "commandline.h"

int main(int argc, char *argv[]) {

	parseArgs(argc, argv);

	//load all jpgs into struct and create a linked list
	setFile("IMG_0631.JPG\0"); //to be replaced by some enumeration function
	setPWD(argv[0]);


	files = (oFile*)malloc(MAX_FILES * sizeof(oFile));
	
	for (int i = 0; i < MAX_FILES; i++) {
		char *fullpath = (char*)malloc((strlen(pwd) + strlen(filename))*sizeof(char));
		strcat(strcpy(fullpath, pwd), filename);
		files[i] = initFile(fullpath, filename);
	}

	printf("Press Any Key to Continue\n");
	getchar();

	free(files);

	return 0;
}
