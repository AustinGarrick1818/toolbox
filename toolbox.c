#include "toolkit.h"
#include <stdio.h>
//#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int _read(char *src) {
	// Currently only outputs file data
	FILE *file = fopen(src, "r");
	if (!file) {
		printf("Error: file not found\n");
		return -1;
	}

	lseek(file, 0, SEEK_SET);
	int file_len = strlen(file);

	// Allocate memory to size of file
	char *buffer = malloc(file_len * sizeof(char));
	if (!buffer) {
		printf("Error: memory allocation error\n");
		fclose(file);
		return -1;
	}

	if (fread(buffer, file_len, 1, file) < 0) {
		printf("Error: failed to read: %s\n", file);
		free(buffer);
		fclose(file);
		return -1;
	}

	// Print data to screen
	printf("\n\ns\n\n", buffer);
	free(buffer);
	fclose(file);

	return 0;
}

int usage(char *file) {
	printf("USAGE: %s <args>\n\n", file);
	printf("-r <file name> - Read file data\n");
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		int file_name = argv[0];
		usage(file_name);
		return -1;
	}

	int opt = argv[1];
	if (strcmp(opt, "-v") == 0) {
		printf("Toolbox v1.0\n");
		return 0;
	} else if (strcmp(opt, "-r") == 0) {
		int src_t = argv[2];
		_read(src_t);
	} else {
		return -1;
	}


	return 0;
}