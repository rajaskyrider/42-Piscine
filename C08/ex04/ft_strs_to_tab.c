/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:13:48 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/29 19:21:42 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof (char) * (ft_strlen(src) + 1));
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	t_stock_str			*stt;

	i = 0;
	stt = (t_stock_str *)malloc(sizeof (t_stock_str) * (ac + 1));
	if (!stt)
		return (0);
	while (i < ac)
	{
		stt[i].size = ft_strlen(av[i]);
		stt[i].str = av[i];
		stt[i].copy = ft_strcpy(av[i]);
		i++;
	}
	stt[i] = (t_stock_str){0, 0, 0};
	return (stt);
}
