#include <stdio.h>
#include <stdlib.h>

#include "oFile.h"
#include "path.h"
#include "commandline.h"
#include "fsOps.h"
#include "oclEngine.h"

int main(int argc, char *argv[]) {

	ApplicationPaths *pths = (ApplicationPaths*)malloc(sizeof(ApplicationPaths));

	parseArgs(argc, argv);

	setParameters(APPLICATION_PATH_CLI_PARAM, &pths->applicationPath);
	setParameters(WORKING_DIRECTORY_PATH_CLI_PARAM, &pths->pwd);

	LoadDirectoryContents(pths->pwd, appendFile);
	prepareFileBuffer();

	initEngine();
	createOclMemBuffer(FileBuffer->elementCount, 
						FileBuffer->FileBufferSize, 
						FileBuffer->HashBufferSize,
						FileBuffer->imageBuf,
						FileBuffer->hashBuf);

	printf("Press Any Key to Continue\n");
	getchar();

	free(start);

	return 0;
}
