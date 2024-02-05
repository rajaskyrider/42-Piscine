/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cponce-q <cponce-q@student.42luxembou      +#+  +:+       +#+        */
/*       rpandipe                                 +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:20:33 by cponce-q          #+#    #+#             */
/*   Updated: 2024/01/28 19:03:52 by cponce-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = -1;
	nb = 0;
	while (str[++i] < '0' || str[i] > '9')
		;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb);
}

int	countdigits(int number)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	while ((int)number > 0)
	{
		count++;
		number /= 10;
	}
	return (count);
}
