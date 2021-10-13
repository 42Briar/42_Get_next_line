#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

/*
-D<macroname>=<value>
		Adds  an implicit #define into the predefines buffer which is read before the source file is
		preprocessed.
 */




char *get_next_line(int fd);




#endif