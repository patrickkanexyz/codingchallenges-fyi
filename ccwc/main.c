#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>


int
main(int argc, char **argv)
{
	bool c_flag = false;
	bool in_word = false;
	bool l_flag = false;
	bool w_flag = false;
	int c;
	int ch;
	int chars = 0;
	int lines = 0;
	int words = 0;

	while ((ch = getopt(argc, argv, "clw")) != -1) {
		switch(ch) {
		case 'c':
			c_flag = true;
			break;
		case 'l':
			l_flag = true;
			break;
		case 'w':
			w_flag = true;
			break;
		default:
			break;
		}
	}

	while ( (c = getchar()) != EOF ) {
		chars += 1;
		if (c == '\n') {
			lines += 1;
		}
		if (!isspace(c) && !in_word) {
			in_word = true;
			words += 1;
		}
		if (isspace(c) && in_word) {
			in_word = false;
		}
	}

	if (w_flag) {
		printf("\t%d\t%s\n", words, argv[2]);
		return 0;
	}
	if (c_flag) {
		printf("\t%d\t%s\n", chars, argv[2]);
		return 0;
	}
	if (l_flag) {
		printf("\t%d\t%s\n", lines, argv[2]);
		return 0;
	}

	printf("\t%d\t%d\t%d\t%s\n", lines, words, chars, argv[2]);
	return 0;
}
