#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "path.h"

void setPWD(const char *argv) {

	delimiter = 0x5C; // "\\"

	size_t i = strlen(argv);

	while (i>=0){

		printf("%x, %c\n", argv[i], argv[i]);
		if (argv[i] == delimiter) {
			pwd = (char*)malloc((i+1)*sizeof(char));
			pwd[i] = '\0';
			pwd = strncpy(pwd, argv, i);
			strcat(pwd, &delimiter); //add the backslash for full path
			break;
		}
		--i;
	}
}

void setFile(const char *argv) {
	filename = (char*)malloc(strlen(argv) * sizeof(char));
	filename = argv;
}