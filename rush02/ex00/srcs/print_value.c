/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cponce-q <cponce-q@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:07:33 by cponce-q          #+#    #+#             */
/*   Updated: 2024/01/28 23:07:35 by cponce-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	p_threem(int *tt, char *value, struct s_dict *s_numdict, int maxline)
{
	int		val;
	char	*hundreds;
	int		j;
	int		cnt;

	j = -1;
	cnt = 0;
	hundreds = (char *)malloc(sizeof(char) * 3 + 1);
	while (tt[2] < tt[1])
	{
		hundreds[++j] = value[tt[2]++];
		cnt++;
		if (cnt % 3 == 0)
		{
			hundreds[j + 1] = '\0';
			val = ft_atoi(hundreds);
			p_hds(s_numdict, maxline, val);
			if (val > 0)
				print_digits(tt[0] * 3 + 1, s_numdict, maxline);
			tt[0]--;
			j = -1;
			cnt = 0;
		}
	}
	free(hundreds);
}

void	p_h(struct s_dict *s_numdict, int maxline, char *rem, int num)
{
	int	val;

	val = ft_atoi(rem);
	print_numbers(s_numdict, maxline, val);
	free(rem);
	print_digits(num * 3 + 1, s_numdict, maxline);
}

void	p_hnums(struct s_dict *s_numdict, int maxline, char *value, int digits)
{
	int		numrem[2];
	int		tt[3];
	char	*rem;
	int		i;

	i = 0;
	numrem[0] = digits / 3;
	numrem[1] = digits % 3;
	if (numrem[1] > 0)
	{
		rem = (char *)malloc(sizeof(char) * numrem[1] + 1);
		while (i < numrem[1])
		{
			rem[i] = value[i];
			i++;
		}
		p_h(s_numdict, maxline, rem, numrem[0]);
	}
	numrem[0]--;
	tt[0] = numrem[0];
	tt[1] = digits;
	tt[2] = i;
	p_threem(tt, value, s_numdict, maxline);
}

void	p_utw(struct s_dict *s_numdict, int maxline, int value, int digits)
{
	if (digits == 3)
		p_hds(s_numdict, maxline, value);
}

void	print_numbers(struct s_dict *s_numdict, int maxline, int value)
{
	int	digits;

	digits = countdigits(value);
	if (digits > s_numdict[maxline].digits)
	{
		write(1, "Dict Error", 10);
		return ;
	}
	if (value < 21)
	{
		print_ltw(s_numdict, maxline, value);
	}
	else if (value < 100)
	{
		print_htw(s_numdict, maxline, value);
	}
	else
		p_utw(s_numdict, maxline, value, digits);
}
