#include "get_next_line.h"

#define BUFFER_SIZE 42

int findnl(char *buf)
{
	int i;

	while(buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}




char	*get_next_line(int fd)
{
	static char	*prev;
	int			read_ret;
	char		buf[BUFFER_SIZE]




	/*
		read into buf
		check buf for newline
		if not paste buf onto prev
		else paste buf onto prev and break
		find second to last \n in prev
		print everything after
	 */
}

int	main()
{
	int	fd = open("text.txt", O_RDONLY);

	get_next_line(fd);
}
