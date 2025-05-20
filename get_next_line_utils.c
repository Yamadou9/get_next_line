/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:18:05 by ydembele          #+#    #+#             */
/*   Updated: 2025/05/18 20:41:27 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <stdint.h>
#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n);
int		ft_strchr(const char *s, int c);

char	*ft_strdup(char *s)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * ft_len(s, 0) + 1);
	if (res == NULL)
		return (NULL);
	while (i < ft_len(s, 0))
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*s;
	size_t	t;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (0);
	t = nmemb * size;
	s = malloc(size * nmemb);
	if (s == NULL)
		return (NULL);
	ft_memset(s, 0, t);
	return (s);
}

void	ft_metzero(char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
		s[i++] = 0;
}

void	ft_buffer_rest(char *tab, char	*buffer)
{
	int		i;
	int		j;
	char	*temp;

	temp = ft_strdup(buffer);
	if (temp == NULL)
		return ;
	i = 0;
	j = ft_len(temp, '\n');
	if (ft_strchr(temp, '\n') == 0)
		return (free(temp), ft_metzero(tab));
	while (temp[j])
		tab[i++] = temp[j++];
	tab[i] = 0;
	free(temp);
}

int	ft_len(char *s, char c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] != 0)
		return (i + 1);
	return (i);
}
