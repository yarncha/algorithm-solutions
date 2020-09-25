#include <stdio.h>
#pragma warning (disable : 4996)

int main(void) {
	int b, c;
	while (true)
	{
		scanf("%d %d", &b, &c);
		printf("%d\n", b + c);
	}
	return 0;
}