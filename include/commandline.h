//this library uses all the commandline arguments to setup the application

#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct arg {
	char* flag;
	char* parameter;
} arg;

arg **args;	//all commandline arguments

void parseArgs(int argc, char *argv[]);