#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char *arr;
	arr = malloc(2);
	arr[0] = 'a';
	arr[1] = '\0';
	free(arr);
}
