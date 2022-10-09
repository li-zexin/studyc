/*
 ============================================================================
 Name        : learnc.c
 Author      : zexin.li
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ___test(){
	printf("test \r ======>>>");
	// test \r
	for(int i = 0; i < 3; i++){
		printf("hello %d\r", i);
		fflush(stdout);
	}
}

void testString();

void test();

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
//	testString();
	test();

	return EXIT_SUCCESS;
}
