#include "get_next_line.h"


#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd1;
    char    buf[256];
    int      chars_read;

	//int		fd2;
	//int		fd3;
	fd1 = open("tests/test1.txt", O_RDONLY);
	//fd2 = open("tests/test2.txt", O_RDONLY);
	//fd3 = open("tests/test3.txt", O_RDONLY);
	while ((chars_read = read(fd1, buf, 100)))
    {
        buf[chars_read] = '\0';
        printf("buf-> %s\n", buf);
    }

	close(fd1);
	//close(fd2);
	//close(fd3);
	return (0);
}
