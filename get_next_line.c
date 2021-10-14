#include "get_next_line.h"

#include <fcntl.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	size_t	i1;
	size_t	i2;

	if (!s1)
		return (ft_strdup(s2));
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	out = malloc(sizeof(char) * (i1 + i2 + 1));
	if (!out)
		return (NULL);
	ft_memmove(out, s1, i1);
	free(s1);
	s1 = NULL;
	ft_memmove(out + i1, s2, i2);
	out[i1 + i2] = 0;
	return (out);
}

char	*stringcircumcize(char *files, char *out)
{
	int	i;

	i = 0;
	while (files[i] != '\n' && files[i])
		i++;
	out = ft_substr(files, 0, i + 1);
	if (!out)
		return (NULL);
	ft_memmove(files, files + i + 1, (ft_strlen(files) - i));
	return (out);
}

int	checknl(char *buf)
{	
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*files[MAX_FD];
	int			bread;
	char		*out;
	char		buf[BUFFER_SIZE + 1];

	out = NULL;
	if (checknl(files[fd]))
		return (stringcircumcize(files[fd], out));
	bread = 1;
	while (bread > 0)
	{
		bread = read(fd, buf, BUFFER_SIZE);
		buf[bread] = 0;
		if (bread == 0)
			break ;
		files[fd] = ft_strjoin(files[fd], buf);
		if (checknl(files[fd]))
			return (stringcircumcize(files[fd], out));
	}
	if (files[fd])
	{
		files[fd] = ft_strjoin(files[fd], buf);
		out = files[fd];
		files[fd] = NULL;
		return (out);
	}
	return (NULL);
}

int	main()
{
	int	fd = open("text.txt", O_RDONLY);
	// int fd2 = open("text2.txt", O_RDONLY)

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
