/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cponce-q <cponce-q@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:46:35 by cponce-q          #+#    #+#             */
/*   Updated: 2024/01/28 23:27:37 by cponce-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	checkvalue(char *value)
{
	int	i;

	i = 0;
	while (value[i] != 0)
	{
		if (value[i] < '0' || value[i] > '9')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	checkdict(char *name)
{
	int	f_d;

	f_d = open_file(name);
	if (f_d == -1)
		return (0);
	close(f_d);
	return (1);
}

int	start_values(char *value, struct s_dict *s_numdict, int maxl)
{
	int	digits;
	int	maxline;

	maxline = maxl;
	if (checkvalue(value) == 0)
		return (0);
	while (value[0] == '0' && value[1] != 0)
		value++;
	digits = ft_strlen(value);
	if (digits > s_numdict[maxline - 1].digits)
	{
		write(1, "Dict Error2\n", 11);
		return (1);
	}
	p_hnums(s_numdict, maxline, value, ft_strlen(value));
	write(1, "\n", 1);
	return (0);
}
