#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "ssu_runtime.h"

int main(void)
{
	char *fname = "ssu_test.txt";
	FILE *fp;
	long fsize;

	gettimeofday(&begin_t, NULL);

	if ((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "fopen error for %s\n", fname);
		exit(1);
	}

	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	printf("The size of <%s> is %ld bytes\n", fname, fsize);

	gettimeofday(&end_t, NULL);
	ssu_runtime(&begin_t, &end_t);

	exit(0);
}
