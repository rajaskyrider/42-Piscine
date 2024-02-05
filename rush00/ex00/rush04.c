/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe, vflores-	                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:24:32 by rpandipe, vflores-#+#    #+#             */
/*   Updated: 2024/01/14 16:18:19 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	top_bottom(int col, char c, char d, char e)
{
	int	j;

	j = 1;
	write (1, &c, 1);
	if (j == col)
		write(1, &"\n", 1);
	while (j < col)
	{
		if (j == col - 1)
		{
			ft_putchar(e);
			write(1, &"\n", 1);
		}
		else
			ft_putchar(d);
		j++;
	}
}

void	sides(int col, char d)
{
	int	j;

	j = 1;
	write(1, &d, 1);
	if (j == col)
		write(1, &"\n", 1);
	while (j < col)
	{
		if (j == col - 1)
		{
			ft_putchar(d);
			write(1, &"\n", 1);
		}
		else
			write(1, &" ", 1);
		j++;
	}
}

void	rush(int x, int y)
{
	int		i;
	char	c;
	char	d;
	char	e;

	c = 'A';
	d = 'B';
	e = 'C';
	i = 0;
	if (y >= 1 && x >= 1)
	{
		while (i < y)
		{
			if (i == 0)
				top_bottom(x, c, d, e);
			else if (i == y - 1)
				top_bottom(x, e, d, c);
			else
				sides(x, d);
			i++;
		}
	}
}
