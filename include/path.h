// the purpose of this is to provide the absolute path for any given filename based on the relative path
// given by commandline
#pragma once

//#include<stdlib.h>
//#include<string.h>

char *pwd;
char *filename;

char delimiter;

void setPWD(const char *argv);
void setFile(const char *argv);