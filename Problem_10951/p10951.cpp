#include <stdio.h>
#pragma warning (disable : 4996)


int main(void) {
	int b, c;
	while (true)
	{	
		// scanf returns the number of successfully received variables
		int valid = scanf("%d %d", &b, &c);
		// if "valid" are not 2, break and terminates while statement
		if (valid!=2) {
			break;
		}
		printf("%d\n", b + c);
	}
	return 0;
}