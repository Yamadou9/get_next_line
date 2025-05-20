/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:27:03 by ydembele          #+#    #+#             */
/*   Updated: 2025/05/20 13:15:04 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = c;
		i++;
	}
	return (s);
}

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
	if (!buffer)
		return (res);
	line = malloc(sizeof(char) * (ft_len(res, 0) + n + 1));
	if (line == NULL)
		return (free(res), NULL);
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
	return (free(res), line);
}

char	*next_line(char *tab, int fd)
{
	char	*res;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	res = NULL;
	if (*tab)
	{
		res = ft_njoin(res, tab, ft_len(tab, '\n'));
		if (res == NULL)
			return (free(buffer), NULL);
		// if (ft_strchr(tab, '\n'))
		ft_buffer_rest(tab, tab);
		// else
		// 	tab[0] = '\0';
	}
	while ((ft_strchr(res, '\n') == 0) && read(fd, buffer, BUFFER_SIZE) > 0)
	{
		res = ft_njoin(res, buffer, ft_len(buffer, '\n'));
		if (res == NULL)
			return (free(buffer), NULL);
		ft_buffer_rest(tab, buffer);
	}
	if (read(fd, 0, 0) == 0 && (res == NULL))
		return (free(buffer), NULL);
	return (free(buffer), res);
}

char	*get_next_line(int fd)
{
	char		*next;
	static char	tab[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	next = next_line(tab, fd);
	return (next);
}

int main(int ac, char **av)
{
	char	*res;
	int		fd;
	int		i;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	i = 0;
	res = get_next_line(fd);
	printf("%s", res);
	while (res)
	{
		res = get_next_line(fd);
		printf("%s", res);
		free(res);
	}
	write(1, res, ft_len(res, 0));
	free(res);



}
