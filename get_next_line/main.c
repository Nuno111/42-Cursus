#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *line = NULL;

    int b = open("41_no_nl", O_RDWR);

    get_next_line(b, &line);
    printf("%s", line);
    free(line);
    get_next_line(b, &line);
    printf("%s", line);
    free(line);
}
