#include "get_next_line.h"

char *return_line(char *sv)
{
    char *line; 
    char *newline_ptr;
    int i;
    int j;
    
    if (!sv) 
        return NULL;

    newline_ptr = ft_strchr(sv,'\n'); 
    if (!newline_ptr)
        return NULL;

    i = newline_ptr - sv; 
    line = malloc(i + 2);
    if (!line)
        return NULL;
    j =-1;
    while (++j < i)
        line[j] = sv[j];

    line[i++] = '\n';
    line[i] = '\0';

    return(line);
}


char *return_next_line(char *sv)
{
    char *str;
    str = NULL;
    if (ft_strchr(sv, '\n'))
    {
        str = ft_strdup(ft_strchr(sv, '\n') + 1);
        if (!str)
        {
            free(sv);
            return (NULL);
        }
    }
    free(sv);
    return (str);
}

char *get_next_line(int fd)
{
    static char *sv;
    char *rtn;
    int rd;
    char *buf;

    if (fd < 0 || fd == 1 || fd ==2 || read(fd,0,0) || BUFFER_SIZE <= 0)
        return (NULL);

    buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
        return (NULL);
    rd = 1;
    while (!ft_strchr(sv,'\n') && rd != 0)
    {
       rd = read (fd, buf, BUFFER_SIZE); 
       if (rd <= 0)
       {
        free(buf);
        return (NULL);
       }
       buf[rd] = '\0';
       sv = ft_strjoin(sv,buf);
    }
    free (buf);
    rtn = return_line(sv);
    sv =  return_next_line(sv);
    return (rtn);
}
