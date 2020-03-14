//this deals with all the filesystem specific stuff
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void LoadDirectoryContents(char *sDir, void (*appendFileToList)());