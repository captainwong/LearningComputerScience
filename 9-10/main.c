#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcpy

// �������õ���ε��㷨�����Լ򵥷�װ�ɺ���
int is_alpha(int c)
{
	//return (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z');
	// �������ж�һ��ֵ�Ƿ���һ�������ڵ� if ��䣬һ���ʹ������ < ���Ż������� <= ���ţ��Ա��Ķ�
	return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

// ��һ��д�����ȰѺϷ����ַ����������temp���ٸ��ƻ�ȥ
void del_digit(char s[]) {
	char temp[128];
	int j = 0;
	for (int i = 0; i <= (strlen(s) - 1); i++) {
		if (is_alpha(s[i])) {
			temp[j++] = s[i];
		}
	}
	temp[j] = 0; // null ��β
	strcpy(s, temp);
}


// �ڶ���д������ʹ��tempֱ�Ӳ���s
void del_digit2(char s[])
{
	int n = strlen(s);
	for (int i = 0; i < n; ) {
		if (!is_alpha(s[i])) { // �ҵ���һ���Ƿ���λ�ã���������ַ�����������
			strcpy(&s[i], &s[i + 1]); // ����
			n--; // �������ַ��������
		} else {
			i++;
		}
	}
	// ����㷨�ܱ�����Ϊ����Ƿ��ַ��м�������Ҫ����ʣ��������ַ�����ǰ�Ƿ�λ�ã���ʣ����ַ�����Ȼ�п��ܰ����Ƿ��ַ����ᵼ���ظ�����    
}

// ������д������ʹ��tempֱ�Ӳ���s��ͬʱ�ڿ��������ַ�����ǰ�Ƿ�λ��ʱ��ͬʱ�жϺ����ַ��Ƿ�����Ƿ��ַ�
void del_digit3(char s[])
{
	int n = strlen(s);
	for (int i = 0; i < n; ) {
		if (!is_alpha(s[i])) { // �ҵ���һ���Ƿ���λ�ã���������ַ�����������
			int j = i + 1;
			while (!is_alpha(s[j])) { // �������ң�ֱ��j���ַ��Ϸ�
				j++;
			}
			strcpy(&s[i], &s[j]);
			// j-i ���Ѵ�����ַ�����
			n -= j - i;
			// i += j - i; ���Լ�дΪ i = j;
			i = j;
		} else {
			i++;
		}
	}
}

int main()
{
	//char ch[128];
	// �ַ�����string)����һ����str��s���ַ�(character) ����һ������Ϊch��c����������Ҫ����Ӣ�Ĵ���
	char str[128] = "abc123cba";
	//printf("�������ַ���: ");
	//scanf("%s", str);
	del_digit3(str);
	printf("���ºõ��ַ���:\n%s\n", str);

	return 0;
}