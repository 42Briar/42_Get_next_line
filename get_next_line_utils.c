#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	strlen;

	strlen = (ft_strlen(s));
	if (!s)
		return (NULL);
	if (start > strlen)
		return (ft_strdup(""));
	if (len > strlen - start)
		return (ft_strdup(s + start));
	out = (char *)malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len && s[start] != 0)
	{
		out[i] = s[start];
		i++;
		start++;
	}
	out[i] = 0;
	return (out);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	i1;
	size_t	i2;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	out = malloc(sizeof(char) * (i1 + i2 + 1));
	if (!out)
		return (NULL);
	ft_memmove(out, s1, i1);
	ft_memmove(out + i1, s2, i2);
	out[i1 + i2] = 0;
	return (out);
}
