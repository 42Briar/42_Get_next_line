#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

/*
-D<macroname>=<value>
		Adds  an implicit #define into the predefines buffer which is read before the source file is
		preprocessed.
 */




char *get_next_line(int fd);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);



#endif