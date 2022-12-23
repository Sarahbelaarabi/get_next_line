#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    while(s[len])
        len++;
    return (len);
}

char    *ft_strchr(const char *s, int c)
{
    while ((char)c != *s)
    {
        if (!*s)
            return (0);
        s++;
    }
    return ((char *)s);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int l;
    int i;
    int j;
	
    l = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
    i = -1;
	while (s1[++i])
        str[i] = s1[i];
    j = -1;
    while (i < l)
        str[i++] = s2[++j];
    str[i] = '\0';
	free(s1);
	return (str);
}


char    *ft_strdup(char *src)
{
    int        i;
    char    *str;

    i = 0;
    str = malloc((ft_strlen(src) + 1) * sizeof(char));
    if (!str)
        return (NULL);
    while (src[i])
    {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}