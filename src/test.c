/*
 * atoi-test.c
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
void test1() {
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


/**
 * 两数相除.
 * TODO 优化1: 计算的结果要优化
 * 1.1 能除尽的直接显示
 * 1.2 不能除尽显示分数
 * 思路: 如何知道一个数能除尽
 * TODO 优化2: 入参类型需要从整数类型切换为字符串类型
 */
//char* chu(int a, int b) {
//	if (a % b == 0) {
//		char result[] = itoa(a / b);
//		return result;
//	}
//	int yue = 2;
//	while (yue <= a || yue <= b) {
//		if (a % yue == 0 && b % yue == 0) {
//			a /= yue;
//			b /= yue;
//			yue = 2;
//		}
//		yue++;
//	}
//	itoa(a);
//	return 0;
//}

/**
 * 求解一元二次方程ax²+bx+c=0的解。其中a、b、c在键盘输入。根据根的情况，分别显示有“两个根分别是”、“一个根是”或者“无解”。
 */
void test2() {
	printf("求解一元二次方程ax²+bx+c=0的解 \n请输入a、b、c的值(逗号分割):");
	fflush(stdout);

	int a, b, c;
	scanf("%d,%d,%d", &a, &b, &c);

	int derta = b * b - 4 * a * c;
	if (derta > 0) {
		int dertasqrt = sqrt(derta);
		float x1 = (-b + dertasqrt) / (2 * a);
		float x2 = (-b - dertasqrt) / (2 * a);
		printf("两个根分别是: x1 = %f, x2 = %f\n", x1, x2);
	} else if (derta == 0) {
		float x1 = -b / (2 * a);
		printf("一个根是: x1 = x2 = %f\n", x1);
	} else {
		printf("无解\n");
	}
}

void test() {
//	test1();
	test2();
}
