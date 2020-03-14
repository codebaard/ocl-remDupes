//this library uses all the commandline arguments to setup the application

#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define APPLICATION_PATH_CLI_PARAM "-a"
#define WORKING_DIRECTORY_PATH_CLI_PARAM "-p"
#define PATH_DELIMITER 0x5C // 0x5C - "\\"

typedef struct arg {
	char* flag;
	char* parameter;
} arg;

arg **args;	//all commandline arguments

void parseArgs(int argc, char *argv[]);
void setParameters(char *flag, char *buf[]);
char* setApplicationPath(const char *argv);