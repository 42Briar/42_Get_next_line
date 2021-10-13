#include "get_next_line.h"

# include <fcntl.h>



/*
	PROCESS:

	error check: return NULL

	check for line in files, if EOF is in there return NULL
	read into buf and check if there is newline, if not strjoin it onto the string in files
	if there is we break and still strjoin, then we substr between the second to last and last newlines and return that

*/

int check_buf(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}	
	return (0);
}

char *make_substr(char *files)
{
	size_t	i;
	int		end;
	int		start;

	i = ft_strlen(files);
	while(1)
	{
		if (files[i] == '\n')
		{
			end = i;
			break ;
		}
		i--;
	}
	i--;
	while(1)
	{
		if (files[i] == '\n')
		{
			start = i;
			break ;
		}
		i--;
	}
	return(ft_substr(files, start, (end-start)));

}

char	*get_next_line(int fd)
{
	static char	*files[MAX_FD];
	char		*buf;
	int			i;

	i = 0;
	if (fd < 0 || fd > MAX_FD || read(fd, buf, 0) < 0)
		return (NULL);
	while	(files[fd][i])
	{
		if (files[fd][i] == EOF)
			return (NULL);
		i++;
	}
	i = 0;
	while (files[fd][i] != EOF)
	{
		read(fd, buf, BUFFER_SIZE);
		if (!check_buf)
			break ;
		files[fd] = ft_strjoin(files[fd], buf);
		while (files[fd][i])
			i++;
	}
	files[fd] = ft_strjoin(files[fd], buf);
	return(make_substr(files));
}

int	main()
{
	int	fd = open("text.txt", O_RDONLY);

	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}
