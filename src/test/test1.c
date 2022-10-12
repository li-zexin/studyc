/*
 * test1.c
 *
 *  Created on: 2022年10月8日
 *      Author: zexin.li
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * 使用键盘输入手机号, 将该号码分成两两一组的整数, 输出该整数对应的ASCII字符
 */
void test1_main() {
	printf("请输入编号: ");
	fflush(stdout);
	char str[2];
	// 读取第一个字符. 如果是换行, 说明后续没有字符了, 直接退出; 否则继续执行
	while ((str[0] = getchar()) != '\n') {
		str[1] = getchar(); // 获取第二个字符
		int num = atoi(str); // 将数字字符转成整数类型
		printf("%d对应的ASCII字符是:%c\n", num, num); // 打印结果
		if (str[1] == '\n') { // 如果第二个字符是换行, 不再读取
			break;
		}
	}
}
