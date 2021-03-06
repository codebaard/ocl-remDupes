// the purpose of this is to provide the absolute path for any given filename based on the relative path
// given by commandline
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ApplicationPaths {
	char *pwd; //present working directory
	char *applicationPath; //where the application is at
} ApplicationPaths;

char *filename; //temporary
void setFile(const char *argv);



