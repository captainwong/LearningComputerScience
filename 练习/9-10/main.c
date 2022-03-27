#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcpy

// 像这种用到多次的算法，可以简单封装成函数
int is_alpha(int c)
{
	//return (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z');
	// 像这种判断一个值是否在一个区间内的 if 语句，一般会使用两个 < 符号或者两个 <= 符号，以便阅读
	return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

// 第一种写法：先把合法的字符逐个拷贝到temp，再复制回去
void del_digit(char s[]) {
	char temp[128];
	int j = 0;
	for (int i = 0; i <= (strlen(s) - 1); i++) {
		if (is_alpha(s[i])) {
			temp[j++] = s[i];
		}
	}
	temp[j] = 0; // null 结尾
	strcpy(s, temp);
}


// 第二种写法，不使用temp直接操作s
void del_digit2(char s[])
{
	int n = strlen(s);
	for (int i = 0; i < n; ) {
		if (!is_alpha(s[i])) { // 找到第一个非法的位置，将后面的字符拷贝到这里
			strcpy(&s[i], &s[i + 1]); // 这里
			n--; // 拷贝后，字符串变短了
		} else {
			i++;
		}
	}
	// 这个算法很笨，因为如果非法字符有几个，就要拷贝剩余的所有字符到当前非法位置，而剩余的字符内仍然有可能包含非法字符，会导致重复拷贝    
}

// 第三种写法，不使用temp直接操作s，同时在拷贝后面字符到当前非法位置时，同时判断后面字符是否包含非法字符
void del_digit3(char s[])
{
	int n = strlen(s);
	for (int i = 0; i < n; ) {
		if (!is_alpha(s[i])) { // 找到第一个非法的位置，将后面的字符拷贝到这里
			int j = i + 1;
			while (!is_alpha(s[j])) { // 向后继续找，直到j处字符合法
				j++;
			}
			strcpy(&s[i], &s[j]);
			// j-i 是已处理的字符数量
			n -= j - i;
			// i += j - i; 可以简写为 i = j;
			i = j;
		} else {
			i++;
		}
	}
}

int main()
{
	//char ch[128];
	// 字符串（string)变量一般用str或s，字符(character) 变量一般命名为ch或c，变量命名要符合英文词义
	char str[128] = "abc123cba";
	//printf("请输入字符串: ");
	//scanf("%s", str);
	del_digit3(str);
	printf("更新好的字符串:\n%s\n", str);

	return 0;
}