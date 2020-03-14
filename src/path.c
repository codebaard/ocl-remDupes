#include "path.h"



void setFile(const char *argv) {
	filename = (char*)malloc(strlen(argv) * sizeof(char));
	filename = argv;
}

//void enumerateFiles() {
//
//}


