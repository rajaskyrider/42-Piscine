/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:20:40 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/14 13:24:59 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	start;
	int	end;
	int	i;

	end = size - 1;
	i = 0;
	while (i < size)
	{
		start = 0;
		while (start <= end)
		{
			if (tab[start] > tab[i])
			{
				temp = tab[start];
				tab[start] = tab[i];
				tab[i] = temp;
			}
			start++;
		}
		i++;
	}
}
