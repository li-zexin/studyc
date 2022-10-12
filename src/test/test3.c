/*
 * 编写函数，计算字符串中各字符ASCII码值的和。如果包含非数字，则返回-1
 * 使用键盘输入本人手机号码，测试函数的正确性
 *
 *  Created on: 2022年10月12日
 *      Author: zexin.li
 */
#include <stdio.h>
#include <string.h>

/**
 * 定义变长数组
 */
struct CharList {
	int len;
	char arr[];
};

/**
 * 计算字符ASCII
 */
int test3_compute(char *str) {
	int result = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return -1;
		}
		result += str[i];
	}
	return result;
}

/**
 * 读取键盘输入的字符
 */
struct CharList test3_getnum() {

	struct CharList charList;
	charList.len = 0;

	char temp;
	while ((temp = getchar()) != '\n') {
		charList.arr[charList.len++] = temp;
	}
	charList.arr[charList.len++] = '\0';

	return charList;
}

void test3_main() {
	printf("请输入您的手机号码:");
	fflush(stdout);

	struct CharList charList = test3_getnum();
	printf("您的手机号是:%s\n", charList.arr);

	int result = test3_compute(charList.arr);
	printf("各字符ASCII码值的和为:%d\n", result);
}
