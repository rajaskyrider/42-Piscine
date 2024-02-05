/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:54:32 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/30 15:17:05 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *src)
{
	int	i;

	i = -1;
	while (src[++i] != 0)
	{
		write(1, &src[i], 1);
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nbr)
{
	long	nb;
	char	c;

	nb = (long)nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		write(1, &"\n", 1);
		ft_putstr(par[i].copy);
		i++;
	}
}
