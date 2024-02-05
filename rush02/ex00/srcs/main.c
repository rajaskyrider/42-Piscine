/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprajapa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:09:20 by nprajapa          #+#    #+#             */
/*   Updated: 2024/01/28 21:17:20 by cponce-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	struct s_dict	*s_numdict;
	int				maxline;
	char			*value;

	if (argc == 2)
	{
		s_numdict = readfile("dict/numbers.dict", &maxline);
		value = argv[1];
	}
	else if (argc == 3)
	{
		if (checkdict(argv[1]) == 0)
		{
			write(1, "Dict Error\n", 11);
			return (1);
		}
		s_numdict = readfile(argv[1], &maxline);
		value = argv[2];
	}
	else
		return (1);
	start_values(value, s_numdict, maxline);
	free(s_numdict);
	return (0);
}
