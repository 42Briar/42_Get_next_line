#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

#define BUFFER_SIZE 10
#define MAX_FD 1024
/*
-D<macroname>=<value>
		Adds  an implicit #define into the predefines buffer which is read before the source file is
		preprocessed.
 */

char *get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t n, size_t size);
void	*ft_memset(void *dst, int c, size_t len);



#endif