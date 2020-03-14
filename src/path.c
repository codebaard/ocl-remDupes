#include "path.h"

void setPWD(const char *argv) {

	delimiter = PATH_DELIMITER; // "\\"

	size_t i = strlen(argv);

	while (i>=0){

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

void enumerateFiles() {

}

void changePWD(const char *newWD) {

}


