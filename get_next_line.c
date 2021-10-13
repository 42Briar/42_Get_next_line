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

char	*ft_strrchr2(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{	
		if (s[i] == (unsigned char)c)
			break ;
		i--;
	}
	while (i >= 0)
	{	
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}



char	*get_next_line(int fd)
{
	static char	*prev;
	int			s2lnewline;
	char		buf[BUFFER_SIZE];

	while (1)
	{
		read(fd, buf, BUFFER_SIZE);
		if (findnl(buf))
		{
			prev = ft_strjoin(prev, buf);
			break ;
		}
		prev = ft_strjoin(prev, buf);
	}


	return(ft_substr(prev,  ft_strrchr2, ft_strrchr(prev, '\n')));

	/*
		read into buf
		check buf for newline
		if not strjoin buf onto prev
		else strjoin buf onto prev and break
		find second to last \n in prev
		print everything after
	 */
}

int	main()
{
	int	fd = open("text.txt", O_RDONLY);

	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}
