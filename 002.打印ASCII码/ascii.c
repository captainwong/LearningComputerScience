#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	for (int i = 0; i < 128; i++) {
		if (isprint(i)) {
			printf("%3d: %c\n", i, i);
		} else {
			printf("%3d: ²»¿É´òÓ¡\n", i);
		}
	}

	system("pause");
}
