/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:45:41 by ydembele          #+#    #+#             */
/*   Updated: 2025/05/13 17:13:53 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10

#endif

void	free_all(char **str);
void	ft_metzero(char *s);
int		ft_strlen(char *s);
void	ft_strcpy(char	*dest, char *src);
int		ft_len(char *s, char c);

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
		res = malloc(sizeof(char) * (ft_len(dest, 0) + ft_len(src, 0) + 1));
	else
		res = malloc(sizeof(char) * (ft_len(src, 0) + 1));
	if (res == NULL)
		return (NULL);
	while (dest && dest[i])
	{
		res[i] = dest[i];
		i++;
	}
	while (src && src[j])
		res[i++] = src[j++];
	res[i] = 0;
	return (res);
}

char	**recup1(char **res, char *dest, char *src, int i)
{
	int	j;
	int	taille;

	j = 0;
	res[0] = malloc(sizeof(char) * (ft_len(dest, '\n') + 2));
	if (res[0] == NULL)
		return (NULL);
	while (i <= ft_len(dest, '\n'))
	{
		res[0][i] = dest[i];
		i++;
	}
	res[0][i] = 0;
	taille = (ft_len(dest, 0) - ft_len(dest, '\n') + ft_len(src, 0));
	res[1] = malloc(sizeof(char) * taille + 2);
	if (res[1] == NULL)
		return (NULL);
	while (dest[i])
	{
		res[1][j] = dest[i];
		j++;
		i++;
	}
	res[2] = NULL;
	return (res);
}

char	**recup2(char **res, char *dest, char *src, int i)
{
	int	j;

	j = 0;
	res[0] = malloc(sizeof(char) * (ft_len(dest, 0) + ft_len(src, '\n') + 2));
	if (res[0] == NULL)
		return (NULL);
	while (dest[i])
	{
		res[0][i] = dest[i];
		i++;
	}
	while (j <= ft_len(src, '\n'))
		res[0][i++] = src[j++];
	res[0][i] = 0;
	res[2] = NULL;
	if ((ft_len(src, 0) - ft_len(src, '\n')) <= 0)
	{
		res[1] = NULL;
		return (res);
	}
	res[1] = malloc(sizeof(char) * (ft_len(src, 0) - ft_len(src, '\n') + 1));
	if (res[1] == NULL)
		return (NULL);
	i = 0;
	while (src[j])
		res[1][i++] = src[j++];
	res[1][i] = 0;
	return (res);
}

char	**ft_recup(char *dest, char *src)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * 3);
	if (res == NULL)
		return (NULL);
	if (ft_len(dest, 0) != ft_len(dest, '\n'))
	{
		res = recup1(res, dest, src, i);
		if (res == NULL)
		{
			free_all(res);
			return (res);
		}
		return (res);
	}
	else
	{
		res = recup2(res, dest, src, i);
		if (res == NULL)
		{
			free_all(res);
			return (res);
		}
		return (res);
	}
}

int	gnl(char **stock, char *tab, char *res)
{
	stock = ft_recup(tab, "\0");
	if (stock == NULL)
		return (0);
	res = ft_strjoin(res, stock[0]);
	if (res == NULL)
	{
		free_all(stock);
		return (0);
	}
	ft_metzero(tab);
	ft_strcpy(tab, stock[1]);
	free_all(stock);
	return (0);
}
char	*get_next_line(int fd)
{
	char			*res;
	char			*r;
	char			**stock;
	static char		tab[1024];

	res = NULL;
	r = calloc(BUFFER_SIZE, sizeof(char));
	if ((ft_len(tab, 0) != ft_len(tab, '\n')))
	{	
		/*tab = gnl(stock, tab, res);*/
		stock = ft_recup(tab, "\0");
		if (stock == NULL)
			return (NULL);
		res = ft_strjoin(res, stock[0]);
		if (res == NULL)
		{
			free_all(stock);
			return (NULL);
		}
		ft_metzero(tab);
		ft_strcpy(tab, stock[1]);
		free_all(stock);
	}
	else
	{
		while (ft_len(res, 0) == ft_len(res, '\n') && read(fd, r, BUFFER_SIZE))
		{
			stock = ft_recup(tab, r);
			if (stock == NULL)
				return (NULL);
			res = ft_strjoin(res, stock[0]);
			if (res == NULL)
			{
				free_all(stock);
				return (NULL);
			}
			ft_metzero(tab);
			if (stock[1])
				ft_strcpy(tab, stock[1]);
			free_all(stock);
		}
	}
	free(r);
	return (res);
}

int main(int ac, char **av)
{
	(void)ac;
	char    *res;
	
	int fd = open(av[1], O_RDONLY);
	res = get_next_line(fd);
	write(1, res, ft_len(res, 0));
	free(res);
	res = get_next_line(fd);
        write(1, res, ft_len(res, 0));
		free(res);
	res = get_next_line(fd);
    write(1, res, ft_len(res, 0));
	free(res);
	res = get_next_line(fd);
	write(1, res, ft_len(res, 0));
	free(res);
	res = get_next_line(fd);
    write(1, res, ft_len(res, 0));
	free(res);
	res = get_next_line(fd);
    write(1, res, ft_len(res, 0));
	free(res);
}