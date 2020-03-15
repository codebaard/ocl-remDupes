#include "commandline.h"

void parseArgs(int argc, char *argv[]) {

	/*Obviously this parser isn't fool proof
	but it works for now. I might improve it in future versions
	J.N.
	*/

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

		//debug
		//puts(args[j]->flag);
		//puts(args[j]->parameter);

		i += 2;
		j++;

	} while (i < argc);
}

void setParameters(char *flag, char *buf[]) {

	int i = 0;
	do {

		if (flag == APPLICATION_PATH_CLI_PARAM) {
			*buf = setApplicationPath(args[i]->parameter);			
			break;
		}
		else if (!strcmp(flag,args[i]->flag)) {
			*buf = (char*)malloc(sizeof(char)*strlen(args[i]->parameter));
			*buf = args[i]->parameter;
			break;
		}
		i++;
	} while (args[i]);
}

char* setApplicationPath(const char *argv) {

	size_t i = strlen(argv);
	char *tmp = NULL;
	char delim[2] = { PATH_DELIMITER , '\0' };

	while (i >= 0) {

		if (argv[i] == delim[0]) {
			tmp = (char*)malloc((i) * sizeof(char));
			tmp[i] = '\0';
			tmp = strncpy(tmp, argv, i);
			//strcat(tmp, delim); //add the backslash for full path
			break;
		}
		--i;
	}

	return tmp;
}