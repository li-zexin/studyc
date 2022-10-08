/*
 * atoi-test.c
 *
 *  Created on: 2022年10月8日
 *      Author: zexin.li
 */

#include <stdio.h>
#include <stdlib.h>

void test_atoi() {
	printf("请输入编号: ");
	fflush(stdout);

	while (1) {
		char str[2];
		str[0] = getchar(); // 获取第一个字符
		if (str[0] == '\n') { // 如果是换行, 直接退出
			break;
		}

		str[1] = getchar(); // 获取第二个字符
		int num = atoi(str); // 将数字字符转成int类型
		printf("%d对应的ascii字符是:%c\n", num, num); // 打印结果
		if (str[1] == '\n') { // 如果第二个字符是换行, 不再读取
			break;
		}
	}

}
