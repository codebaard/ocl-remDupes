//this deals with all the filesystem specific stuff
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void enumerateFS(char* buf[]); //buf = where to put the list of files
void ListDirectoryContents(char *sDir);