/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:54:55 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/29 09:45:10 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_res(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++ ;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	issame;

	i = 0;
	issame = 0;
	while (s1[i] != 0 || s2[i] != 0)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (issame);
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (i < argc - 1)
	{
		k = 1;
		while (k < argc - 1)
		{
			if (ft_strcmp(argv[k], argv[k + 1]) > 0)
				ft_swap(&argv[k], &argv[k + 1]);
			k++;
		}
		i++;
	}
	print_res(argc, argv);
	return (0);
}
