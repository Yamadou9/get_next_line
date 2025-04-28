#include<stdio.h>

int		ft_strchr(const char *s, int c)
{
	int	i;
	
	i = 0;
	c = c % 256;
	if (s == NULL)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (1);
	return (0);
}
