/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:41:32 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/28 20:53:06 by cponce-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

void	print_ltw(struct s_dict *s_numdict, int maxline, int value)
{
	int	index;
	int	len;

	index = find_index(s_numdict, maxline, value);
	len = ft_strlen(s_numdict[index].word);
	write(1, s_numdict[index].word, len);
}

void	print_htw(struct s_dict *s_numdict, int maxline, int value)
{
	int	index;
	int	den;
	int	num;

	num = (value / 10) * 10;
	index = find_index(s_numdict, maxline, (num));
	if (index != 0)
		write(1, s_numdict[index].word, ft_strlen(s_numdict[index].word));
	den = (int)value % 10;
	if (den != 0)
	{
		index = find_index(s_numdict, maxline, den);
		write (1, " ", 1);
		write(1, s_numdict[index].word, ft_strlen(s_numdict[index].word));
	}
}

void	p_hds(struct s_dict *s_numdict, int maxline, int value)
{
	int	num;
	int	den;

	num = (int)value / 100;
	if (num > 0)
	{
		print_ltw(s_numdict, maxline, num);
	}
	if (value >= 100)
	{
		den = 100;
		write(1, " ", 1);
		print_htw(s_numdict, maxline, den);
	}
	if (value - (num * 100) != 0)
	{
		den = (int)value - (num * 100);
		write(1, " ", 1);
		print_htw(s_numdict, maxline, den);
	}
}

void	print_digits(int digits, struct s_dict *s_numdict, int maxline)
{
	int	i;
	int	len;

	i = 0;
	if (digits > 3)
	{
		while (i < maxline)
		{
			if (s_numdict[i].digits == digits)
			{
				len = ft_strlen(s_numdict[i].word);
				write(1, " ", 1);
				write(1, s_numdict[i].word, len);
				write(1, " ", 1);
				break ;
			}
			i++;
		}
	}
}
