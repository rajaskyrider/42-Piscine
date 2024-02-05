/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:35:41 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/21 23:31:22 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int		solve(int size, int **grid, int **cons);
void	print_result(int size, int **arr);
int		checkinput(char *inp);
int		check_args(int argc, char **argv, int size);

void	char_to_int(char *inp, int **req)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = 0;
	col = 0;
	while (inp[i] != 0)
	{
		if (inp[i] >= '0' && inp[i] <= '9')
		{
			req[row][col] = inp[i] - '0';
			col++;
			if (col == 8)
			{
				row++;
				col = 0;
			}
		}
		i++;
	}
}

int	skyscraper(int size, int **cons)
{
	int	*all;
	int	**arr;
	int	i;

	i = 0;
	all = (int *) malloc(size * sizeof(int));
	if (!all)
	{
		write(1, "Memory not allocated.\n", 22);
		return (0);
	}
	arr = (int **) malloc(size * sizeof(int *));
	while (i < size)
	{
		arr[i] = (int *) malloc(size * sizeof(int));
		i++;
	}
	solve (size, arr, cons);
	print_result(size, arr);
	free(arr);
	return (1);
}

int	**allocate2darray(int size)
{
	int	**arr;
	int	i;

	arr = (int **)malloc(sizeof(int *) * size);
	if (!arr)
	{
		write(1, "Memory not allocated.\n", 23);
	}
	i = 0;
	while (i < size)
	{
		arr[i] = (int *)malloc(sizeof(int) * size);
		if (!arr[i])
		{
			write(1, "Memory not allocated.\n", 23);
		}
		i++;
	}
	return (arr);
}

int	main(int argc, char **argv)
{
	char	*input;
	int		size;
	int		count;
	int		**req;

	size = 4;
	if (check_args(argc, argv, size) == 1)
	{
		input = argv[1];
		count = checkinput(input);
		req = allocate2darray(size);
		char_to_int(input, req);
		skyscraper (size, req);
		free(req);
	}
	return (0);
}
