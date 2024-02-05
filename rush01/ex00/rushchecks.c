/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushchecks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:48:21 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/21 23:08:13 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	checkinput(char *inp, int size)
{
	int		count;
	int		i;
	char	maxs;

	i = 0;
	count = 0;
	maxs = (char) size + '0';
	if (!(inp[i] >= 48 && inp[i] <= 57))
		return (count);
	while (inp[i] != 0)
	{
		if (!((inp[i] >= 48 && inp[i] <= 57) || inp[i] == 32))
			break ;
		else if (inp[i] > maxs)
		{
			count = 0;
			break ;
		}
		else if (inp[i] >= 48 && inp[i] <= 57)
			count++;
		i++;
	}
	return (count);
}

int	check_args(int argc, char **argv, int size)
{
	char	*input;
	int		count;

	if (argc == 1)
	{
		write(1, "Error - Please provide an input\n", 32);
		return (0);
	}
	input = argv[1];
	count = checkinput(input, size);
	if (count != size * 4)
	{
		write(1, "Error - Check the input\n", 24);
		return (0);
	}
	return (1);
}
