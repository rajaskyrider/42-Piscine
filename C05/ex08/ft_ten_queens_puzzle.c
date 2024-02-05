/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:56:00 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/29 16:00:59 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	issafe(int grid[10][10], int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < col)
	{
		if (grid[row][i] == 1)
			return (0);
		i++;
	}
	j = col;
	i = row;
	while (i >= 0 && j >= 0)
	{
		if (grid[i][j] == 1)
			return (0);
		i--;
		j--;
	}
	j = col;
	i = row;
	while (i < 10 && j >= 0)
		if (grid[i++][j--] == 1)
			return (0);
	return (1);
}

void	printq(int queens[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = queens[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	solve(int grid[10][10], int col, int queens[10], int count)
{
	int	i;

	i = 0;
	if (col == 10)
	{
		printq(queens);
		count = count + 1;
		return (count);
	}
	while (i < 10)
	{
		if (issafe(grid, i, col))
		{
			grid[i][col] = 1;
			queens[col] = i;
			count = solve(grid, col + 1, queens, count);
			grid[i][col] = 0;
		}
		i++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	count;
	int	grid[10][10];
	int	queens[10];
	int	row;
	int	col;

	count = 0;
	row = -1;
	col = -1;
	while (++row < 10)
	{
		col = -1;
		while (++col < 10)
			grid[row][col] = 0;
	}
	row = -1;
	while (++row < 10)
		queens[row] = 0;
	count = solve(grid, 0, queens, count);
	return (count);
}
