#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "ssu_runtime.h"

static void ssu_charatatime(char *str);

int main(void)
{
	pid_t pid;

	gettimeofday(&begin_t, NULL);

	if ((pid = fork()) < 0) {
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	else if (pid == 0) {
		ssu_charatatime("output from child\n");
	}
	else {
		ssu_charatatime("output from parent\n");
	}

	gettimeofday(&end_t, NULL);

	printf("\n%d's runtime", getpid());
	ssu_runtime(&begin_t, &end_t);

	exit(0);
}

static void ssu_charatatime(char *str) 
{
	char *ptr;
	int print_char;

	setbuf(stdout, NULL);

	for (ptr = str; (print_char = *ptr++) != 0;) {
		putc(print_char, stdout);
		usleep(10);
	}
	
}
