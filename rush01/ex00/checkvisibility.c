/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvisibility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:04:22 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/21 21:29:57 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isvisibleleft(int size, int row, int **grid, int **cons)
{
	int	i;
	int	check;
	int	vis;

	i = 0;
	vis = 1;
	check = grid[row][i];
	while (i < size)
	{
		if (grid[row][i] == 0)
			return (1);
		if (grid[row][i] > check)
		{
			vis = vis + 1;
			check = grid[row][i];
		}
		i++;
	}
	if (vis != cons[1][row])
		return (0);
	return (1);
}

int	isvisibleright(int size, int row, int **grid, int **cons)
{
	int	j;
	int	check;
	int	vis;

	vis = 1;
	j = size - 1;
	check = grid[row][j];
	while (j >= 0)
	{
		if (grid[row][j] == 0)
			return (1);
		if (grid[row][j] > check)
		{
			vis = vis + 1;
			check = grid[row][j];
		}
		j--;
	}
	if (vis != cons[1][row + 4])
		return (0);
	return (1);
}

int	isvisibletop(int size, int col, int **grid, int **cons)
{
	int	i;
	int	check;
	int	vis;

	i = 0;
	vis = 1;
	check = grid[i][col];
	while (i < size)
	{
		if (grid[i][col] == 0)
			return (1);
		if (grid[i][col] > check)
		{
			vis = vis + 1;
			check = grid[i][col];
		}
		i++;
	}
	if (vis != cons[0][col])
		return (0);
	return (1);
}

int	isvisiblebottom(int size, int col, int **grid, int **cons)
{
	int	check;
	int	vis;
	int	j;

	vis = 1;
	j = size - 1;
	check = grid[j][col];
	while (j >= 0)
	{
		if (grid[j][col] == 0)
			return (1);
		if (grid[j][col] > check)
		{
			vis = vis + 1;
			check = grid[j][col];
		}
		j--;
	}
	if (vis != cons[0][col + 4])
		return (0);
	return (1);
}

int	checkvis(int size, int tt[2], int **grid, int **cons)
{
	int	row;
	int	col;

	row = tt[0];
	col = tt[1];
	if (isvisibleleft(size, row, grid, cons) == 0)
		return (0);
	if (isvisibleright(size, row, grid, cons) == 0)
		return (0);
	if (isvisibletop(size, col, grid, cons) == 0)
		return (0);
	if (isvisiblebottom(size, col, grid, cons) == 0)
		return (0);
	return (1);
}
