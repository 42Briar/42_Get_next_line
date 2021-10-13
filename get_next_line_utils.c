#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

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
