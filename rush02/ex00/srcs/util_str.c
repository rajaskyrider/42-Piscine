/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:39:57 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/28 19:04:14 by cponce-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

char	*ft_dup(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dup)
		return (0);
	while (src[i] != 0)
	{
		dup[i] = src[i];
		i++;
	}
	dup [i] = 0;
	return (dup);
}

char	*ft_strrdup(char *src)
{
	int		size;
	int		i;
	char	*dup;
	int		start;

	i = -1;
	size = 0;
	while (src[++i] != ':')
		;
	while (src[++i] <= 32)
		;
	start = i;
	while (src[i++] != 0)
		size++;
	i = 0;
	dup = (char *)malloc(sizeof(char) * size + 1);
	if (!dup)
		return (0);
	while (src[start] != 0)
	{
		dup[i++] = src[start];
		start++;
	}
	dup [i] = 0;
	return (dup);
}

char	*ft_strrcat(char *dest, char src, int linesize)
{
	int		i;
	int		j;
	char	*ans;

	i = 0;
	j = 0;
	ans = (char *)malloc (sizeof(char) * (linesize + 1));
	while (i < linesize && dest[i] != 0)
	{
		ans[i] = dest[i];
		i++;
	}
	free(dest);
	ans[i] = src;
	ans[i + 1] = 0;
	return (ans);
}
