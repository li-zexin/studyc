/*
 * common-function.c
 *
 *  Created on: 2022年10月7日
 *      Author: zexin.li
 */

/**
 * 获取到一个数字的位数
 */
int numberDigits(int num) {
	if (num < 0) {
		num = -num;
	}
	int i = 0;
	do {
		num = num / 10;
		i++;
	} while (num != 0);
	return i;
}

