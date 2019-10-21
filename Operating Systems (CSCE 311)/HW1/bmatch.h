#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include <ctype.h>
#include <string.h>

#ifndef BMATCH_H
#define BMATCH_H
bool match(char const *a, char const *b) {
	//a is buf, b is word to find
	char const *p = a;
	while(1) {
		p = strstr(p,b);
		if(p == NULL)
			return false;
		if ((p == a) || !isalnum((unsigned char)p[-1])) {
			p += strlen(b);
			if (!isalnum((unsigned char)*p)) {
				return true;
			}
		}
		p += 1;
	}
	return false;
}
#endif