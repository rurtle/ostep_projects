/*
 * @name	wcat.c
 *
 * @brief	Simple implementation of `cat` utility. For more details, please refer to -
 *
 * 		https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/initial-utilities#wcat
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

#define BUFF_LEN	256

/*
 * @brief	Utility function to read a file
 */
int read_file_through_wcat(char *pathname)
{
	int ret = 0;
	int errsv = 0;
	char buffer[BUFF_LEN] = "";
	FILE *fp = fopen(pathname, "r");
	if (fp == NULL) {
		printf("wcat: cannot open file\n");
		ret = 1;
	} else {
		/* File opened successfully. Time to read from it */
		while (fgets(buffer, BUFF_LEN, fp) != NULL) {
			printf("%s", buffer);
		}
		/* Done reading the file. Close it! */
		errno = 0;
		if (fclose(fp) != 0) {
			errsv = errno;
			printf("Error: file close failed <%d>", errsv);
		}
	}
	return ret;
}

/*
 * @brief	Driver function
 */
int main(int argc, char *argv[])
{
	int ret = -1;
	/* If no files are specified on the command line */
	if (argc == 1) {
		ret = 0;
	} else {
		/* Print the number of files to read */
		for (int i = 1; i < argc; i++) {
			ret = read_file_through_wcat(argv[i]);
			if (ret != 0)							/* "exit with status code 1" */
				return 1;
		}
	}
	return ret;
}
