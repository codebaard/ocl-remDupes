#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "path.h"

void setPWD(const char argv[]) {

	delimiter = 0x5C; // "\\"

	int i = strlen(argv);

	//for (; i <= 0; --i){
	while (i>=0){

		printf("%x, %c\n", argv[i], argv[i]);
		if (argv[i] == delimiter) {
			printf("Gotcha!");
		}
		--i;
	}
}