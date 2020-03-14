#include "commandline.h"

void parseArgs(int argc, char *argv[]) {

	//set up *args[]
	args = (arg**)malloc(argc * sizeof(arg));

	int i = 0;
	int j = 0;
	do {
		args[j] = (arg*)malloc(2 * sizeof(char) + strlen(argv[i]) * sizeof(char));

		if (j == 0) { //first argument is always application path		
			args[j]->flag = "-a"; //application
		}
		else { //all other
			args[j]->flag = argv[i-1];
		}

		args[j]->parameter = argv[i];

		puts(args[j]->flag);
		puts(args[j]->parameter);
		i += 2;
		j++;

	} while (i < argc);
}