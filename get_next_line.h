#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char    *get_next_line(int fd);
char    *return_line(char *sv);
char    *return_next_line(char *sv);
size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char    *ft_strdup(char *src);


#endif