/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:16:58 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/21 23:17:53 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	checkvis(int size, int tt[2], int **grid, int **cons);
int	solve(int size, int **grid, int **cons);

int	issafe(int size, int tt[2], int val, int **grid)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = tt[0];
	col = tt[1];
	while (i < size)
	{
		if (grid[row][i] == val)
			return (0);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (grid[i][col] == val)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int size, int **grid, int **cons);

int	checker(int size, int tt[2], int **grid, int **cons)
{
	int	num;
	int	row;
	int	col;

	num = 1;
	row = tt[0];
	col = tt[1];
	while (num <= size)
	{
		if (issafe(size, tt, num, grid) == 1)
		{
			grid[row][col] = num;
			if (checkvis(size, tt, grid, cons) == 1)
			{
				if (solve(size, grid, cons) == 1)
					return (1);
			}
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	solve(int size, int **grid, int **cons)
{
	int	row;
	int	col;
	int	tt[2];

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (grid[row][col] == 0)
			{
				tt[0] = row;
				tt[1] = col;
				if (checker(size, tt, grid, cons) == 0)
					return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

int	checkres(int size, int **arr)
{
	int		row;
	int		col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (arr[row][col] == 0)
			{
				write(1, "No Solution found", 17);
				return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

int	print_result(int size, int **arr)
{
	char	digit;
	int		row;
	int		col;

	row = 0;
	if (checkres(size, arr) == 0)
		return (0);
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			digit = arr[row][col] + '0';
			write(1, &digit, 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
	return (1);
}
