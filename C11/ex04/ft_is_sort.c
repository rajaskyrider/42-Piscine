/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:32:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/02/01 19:25:33 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	str;

	i = 0;
	str = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
		{
			str = 0;
			break ;
		}
		i++;
	}
	if (str != 1)
	{
		i = 0;
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}
