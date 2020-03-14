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

	LoadDirectoryContents(pths->pwd, appendFile);

	printf("Press Any Key to Continue\n");
	getchar();

	free(start);

	return 0;
}
