#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int
main(int argc, char **argv)
{
	int c;
	bool in_word = false;
	int words = 0;
	int lines = 0;
	int chars = 0;

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

	printf("Char count: %d\n", chars);
	printf("Line count: %d\n", lines);
	printf("Word count: %d\n", words);
	return 0;
}
