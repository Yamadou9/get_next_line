/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_untils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:18:05 by ydembele          #+#    #+#             */
/*   Updated: 2025/05/14 15:47:52 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
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

	i = 0;
	j = ft_len(buffer, '\n');
	if (ft_len(buffer, 0) == ft_len(buffer, '\n'))
		return ;
	ft_metzero(tab);
	while (buffer[j])
		tab[i++] = buffer[j++];
	tab[i] = 0;
}

int	ft_len(char *s, char c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s && s[i] != c && s[i])
		i++;
	if (s[i] != 0)
		return (i + 1);
	return (i);
}
