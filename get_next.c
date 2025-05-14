/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:27:03 by ydembele          #+#    #+#             */
/*   Updated: 2025/05/14 16:05:30 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10

#endif
int	ft_strchr(const char *s, int c)
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
char	*ft_njoin(char *res, char *buffer, int n)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = malloc(sizeof(char) * (ft_len(res, 0) + n + 1));
	if (line == NULL)
		return ("caca");
	if (res != NULL)
	{
		while (res[i])
		{
			line[i] = res[i];
			i++;
		}
	}
	while (j < n)
		line[i++] = buffer[j++];
	line[i] = 0;
	return (line);
}

char	*next_line(char *tab, int fd)
{
	char	*res;
	char	*buffer;

	buffer = calloc(BUFFER_SIZE, sizeof(char));
	res = NULL;

	if (ft_len(tab, 0) != 0)
		res = ft_njoin(res, tab, ft_len(tab, '\n'));
	ft_metzero(tab);
	while ((ft_strchr(res, '\n') == 0) && read(fd, buffer, BUFFER_SIZE) >= 0)
	{
		res = ft_njoin(res, buffer, ft_len(buffer, '\n'));
		if (res == NULL)
			return (NULL);
		ft_buffer_rest(tab, buffer);
		if(ft_len(res, 0) != ft_len(res, '\n'))
			return (res);
	}
	return (res);
}

char	*get_next(int fd)
{
	char		*next;
	static char	tab[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ("ca");
	next = next_line(tab, fd);
	return (next);
}
int main(int ac, char **av)
{
	(void)ac;
	char    *res;
	res = get_next(open(av[1], O_RDONLY));
	write(1, res, ft_len(res, 0));
	res = get_next(open(av[1], O_RDONLY));
	write(1, res, ft_len(res, 0));
	res = get_next(open(av[1], O_RDONLY));
	write(1, res, ft_len(res, 0));

}
