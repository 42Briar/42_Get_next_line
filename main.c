#include "get_next_line.h"

#include <fcntl.h>

int	main()
{
	int	fd = open("text.txt", O_RDONLY);
	// int fd2 = open("text2.txt", O_RDONLY);
	// int fd3 = open("text3.txt", O_RDONLY);

	for (int i = 0; i < 16; i++)
		printf("%s", get_next_line(fd));
}

//gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -fsanitize=address -D BUFFER_SIZE=10 && ./a.out