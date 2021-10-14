#include "get_next_line.h"

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

char	*helper(char **files, char *out, char *buf)
{
	*files = ft_strjoin(*files, buf);
	out = *files;
	*files = NULL;
	return (out);
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
		return (helper(&files[fd], out, buf));
	return (NULL);
}
