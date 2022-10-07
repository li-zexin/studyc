/*
 * string.c
 *
 *  Created on: 2022年10月7日
 *      Author: zexin.li
 */
#include <stdio.h>

void printfCharArray(char *functionName, char str[], int length) {
	printf("%s\t%d\t\"%s\"\t\t\t[", functionName, length, str);
	for (int i = 0; i < length; i++) {
		if (i == 0) {
			printf("%c", str[i]);
		} else {
			printf(", %c", str[i]);
		}
	}
	printf("]\n");
}

/**
 * 没有结束符，打印乱码
 */
void case1() {
	char str[] = { 'a', 'b' };
	int length = sizeof(str) / sizeof(str[0]);
	printfCharArray(__FUNCTION__, str, length);
}

/*
 * 双引号引用的字符串
 * 猜测：底层在把“a”赋值给str数组时，判断已经是一个数组就没有将“b”赋值给str数组了
 * 所以：字符一定要用单引号
 */
void case2() {
	char str[] = { "a", "b" };
	int length = sizeof(str) / sizeof(str[0]);
	printfCharArray(__FUNCTION__, str, length);

}

/**
 * 双引号引用的字符串
 * 同上
 */
void case3() {
	char str[4] = { "a", "b" };
	int length = sizeof(str) / sizeof(str[0]);
	printfCharArray(__FUNCTION__, str, length);
}

void case4() {
	char str[4] = { 'a', '\0', 'b', '\0' };
	int length = sizeof(str) / sizeof(str[0]);
	printfCharArray(__FUNCTION__, str, length);
}

void case5() {
	char str[4] = { 'a', NULL, 'b', NULL };
	int length = sizeof(str) / sizeof(str[0]);
	printfCharArray(__FUNCTION__, str, length);
}

void testString() {
	printf("=======>>>%s<<<=======\n", __FILE__);
	printf("用例编号\t数组长度\t字符串\t\t\t数组\n", __FILE__);
	case1();
	case2();
	case3();
	case4();
	case5();
}
