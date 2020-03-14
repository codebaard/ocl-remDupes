#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <CL/cl.h>

#include "oFile.h"
#include "path.h"
#include "commandline.h"
#include "fsOps.h"

int main(int argc, char *argv[]) {

	ApplicationPaths *pths = (ApplicationPaths*)malloc(sizeof(ApplicationPaths));

	parseArgs(argc, argv);

	setParameters(APPLICATION_PATH_CLI_PARAM, &pths->applicationPath);
	setParameters(WORKING_DIRECTORY_PATH_CLI_PARAM, &pths->pwd);

	ListDirectoryContents(pths->pwd);

	//load all jpgs into struct and create a linked list
	//setFile("IMG_0631.JPG\0"); //to be replaced by some enumeration function

	//files = (oFile*)malloc(MAX_FILES * sizeof(oFile));
	//
	//for (int i = 0; i < MAX_FILES; i++) {
	//	char *fullpath = (char*)malloc((strlen(pwd) + strlen(filename))*sizeof(char));
	//	strcat(strcpy(fullpath, pwd), filename);
	//	files[i] = initFile(fullpath, filename);
	//}

	//printf("Press Any Key to Continue\n");
	//getchar();

	//free(files);

	return 0;
}
