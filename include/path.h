// the purpose of this is to provide the absolute path for any given filename based on the relative path
// given by commandline
#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <windows.h>

#define PATH_DELIMITER 0x5c

char *pwd; //present working directory
char *applicationPath; //where the application is at
char *filename; //temporary

char delimiter;

void setPWD(const char *argv);
void setFile(const char *argv);

void enumerateFiles();

void changePWD(const char *newWD);