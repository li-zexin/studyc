/*
 * string-endchar-test.c
 *
 *  Created on: 2022年10月7日
 *      Author: zexin.li
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numberDigits(int num);

/**
 * 打印字符数组
 */
void printfCharArray(const char *caseName, char charArray[], int arrayLength) {
	printf("%s\t%d\t\t\"%s\"\t\t\t[", caseName, arrayLength, charArray);
	for (int i = 0; i < arrayLength; i++) {
		if (i == 0) {
			printf("%c", charArray[i]);
		} else {
			printf(", %c", charArray[i]);
		}
	}
	printf("]\n");
}

/**
 * 结束符：0、\0、NULL
 */
void testString_case0() {
	char endChar[] = { '\0', 0, NULL };
	int length = sizeof(endChar) / sizeof(endChar[0]);
	for (int i = 0; i < length; i++) {
		char str[4] = { 'a', '0', endChar[i], 'b' };
		int length = sizeof(str) / sizeof(str[0]);
		char *caseName = malloc(strlen(__FUNCTION__) + 1 + numberDigits(i) + 1);
		sprintf(caseName, "%s-%d", __FUNCTION__, i);
		printfCharArray(caseName, str, length);
	}
}

/**
 * 没有结束符，打印乱码
 */
void testString_case1() {
	char str[] = { 'a', '0', 'b' };
	int length = sizeof(str) / sizeof(str[0]);
	printfCharArray(__FUNCTION__, str, length);
}

/*
 * 双引号引用的字符串，不指定字符数组初始长度
 * 猜测：底层在把“a”赋值给str数组时，判断已经是一个数组就没有将“b”赋值给str数组了
 * 所以：字符一定要用单引号
 */
void testString_case2() {
	char str[] = { "a", "0", "b" };
	int length = sizeof(str) / sizeof(str[0]);
	printfCharArray(__FUNCTION__, str, length);

}

/**
 * 双引号引用的字符串，指定字符数组初始长度
 */
void testString_case3() {
	char str[6] = { "a", "0", "b" };
	int length = sizeof(str) / sizeof(str[0]);
	printfCharArray(__FUNCTION__, str, length);
}

/**
 * 数组中间含有结束符，但是故意打印后续字符是仍旧可以继续打印的
 */
void testString_case4() {
	char str[4] = { 'a', '\0', 'b', NULL };
	int length = sizeof(str) / sizeof(str[0]);
	printfCharArray(__FUNCTION__, str, length);
}

void testString() {
	printf("=======>>>%s<<<========\n", __FILE__);
	printf("用例编号\t\t\t数组长度\t\t字符串\t\t\t数组\n");
	testString_case0();
	testString_case1();
	testString_case2();
	testString_case3();
	testString_case4();

}
