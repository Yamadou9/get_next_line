/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:32:06 by ydembele          #+#    #+#             */
/*   Updated: 2025/05/14 15:19:49 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	ft_len(char *s, char c);
char	*ft_njoin(char *res, char *buffer, int n);
void	ft_buffer_rest(char *tab, char	*buffer);
void	ft_metzero(char *tab);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10

#endif