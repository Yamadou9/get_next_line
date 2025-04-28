#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000000

#endif
int		ft_strchr(const char *s, int c);

void	ft_metzero(char *s)
{
	int		i;

	i = 0;
	while(s[i])
		s[i++] = 0;
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0; 
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	ft_strcpy(char	*dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(dest == NULL))
	{ 
		while (dest[i])
			i++;
	}
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = 0;
}
int		ft_len(char *s)
{
	int		i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *dest, char *src)
{
	char	*res;
	int		i;
	int		j;

	if (!dest && !src)
		return (NULL);
	i = 0;
	j = 0;
	if (dest)
		res = malloc(sizeof(char) * (ft_len(dest) + ft_len(src) + 1));
	else
		res = malloc(sizeof(char) * (ft_len(src) + 1));
	while (dest && dest[i])
	{
		res[i] = dest[i];
		i++;
	}
	while (src && src[j])
	{
		res[i] = src[j];
		i++;
		j++;
	}
	res[i] = 0;
	return (res);
}

char    **ft_recup(char *dest, char *src)
{
	char	**res;
	int			i;
	int			j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * 3);
	if (ft_strchr(dest, '\n') == 1)
	{
		res[0] = malloc(sizeof(char) * (ft_strlen(dest) + 1));
		while (i < ft_strlen(dest))
		{
			res[0][i] = dest[i];
			i++;
		}
		res[0][i++] = '\n';
		res[0][i] = 0;
		res[1] = malloc(sizeof(char) * (ft_len(dest) - ft_strlen(dest) + ft_len(src)));
		while(dest[i])
		{
			res[1][j] = dest[i];
			j++;
			i++;
		}
		res[2] = NULL;
		return (res);
	}
	else
	{
		res[0] = malloc(sizeof(char) * (ft_len(dest) + ft_strlen(src) + 1));
		while (dest[i])
		{
			res[0][i] = dest[i];
			i++;
		}
		while (j < ft_strlen(src))
			res[0][i++] = src[j++];
		if (ft_len(src) != ft_strlen(src))
			res[0][i++] = '\n';
		res[0][i] = 0;
		j++;
		if ((ft_len(src) - ft_strlen(src)) <= 0)
		{
			res[1] = NULL;
			res[2] = NULL;
			return (res);
		} 
		res[1] = malloc(sizeof(char) * (ft_len(src) - ft_strlen(src) + 1));
		i = 0;
		while (src[j])
		{
			res[1][i++] = src[j++];
		}
		res[1][i] = 0;
		res[2] = NULL;
		return (res);
	}
}

char    *get_next_line(int fd)
{
	char    *res;
	char    *r;
	char	**stock;
	static char tab[100000];

	res = NULL;
	r = calloc(BUFFER_SIZE, sizeof(char));
	if ((ft_len(tab) != ft_strlen(tab)))
	{	
		stock = ft_recup(tab, "\0");
		res = ft_strjoin(res, stock[0]);
		ft_metzero(tab);
		ft_strcpy(tab, stock[1]);
		free(stock[0]);
                free(stock[1]);
                free(stock[2]);
	}
	else
	{
		while ((ft_strchr(res, '\n') == 0) && read(fd, r, BUFFER_SIZE))
		{
			stock = ft_recup(tab, r);
			res = ft_strjoin(res, stock[0]);
			ft_metzero(tab);
			ft_strcpy(tab, stock[1]);
			free(stock[0]);
                	free(stock[1]);
        	        free(stock[2]);
		}
	}
	free(r);
	return (res);
}

int main(int ac, char **av)
{
	(void)ac;
	char    *res;;
	int fd = open(av[1], O_RDONLY);
	res = get_next_line(fd);
	write(1, res, ft_len(res));
	res = get_next_line(fd);
        write(1, res, ft_len(res));
	res = get_next_line(fd);
        write(1, res, ft_len(res));
	res = get_next_line(fd);
	write(1, res, ft_len(res));
	res = get_next_line(fd);
	res = get_next_line(fd);
	res = get_next_line(fd);
	res = get_next_line(fd);
}
