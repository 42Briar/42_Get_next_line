#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

#define BUFFER_SIZE 42
#define MAX_FD 1024
/*
-D<macroname>=<value>
		Adds  an implicit #define into the predefines buffer which is read before the source file is
		preprocessed.
 */

char *get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);



#endif