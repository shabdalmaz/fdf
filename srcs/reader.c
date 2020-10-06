/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:40:39 by ashabdan          #+#    #+#             */
/*   Updated: 2020/10/05 22:39:42 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		getsize(char *filename, t_mx *matrix)
{
	int		fd;
	char	*line;

	matrix->width = 0;
	matrix->height = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		print_error(1);
	while (get_next_line(fd, &line) > 0)
	{
		if (matrix->height == 0)
			matrix->width = wordcounter(line, ' ');
		matrix->height += 1;
		if (*line != '\0')
			free(line);
	}
	close(fd);
}

static void		mxalloc(t_mx *matrix)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(matrix->board = (int **)malloc(sizeof(int *) * matrix->height)))
		print_error(2);
	while (i < matrix->height)
	{
		if (!(matrix->board[i] = (int *)malloc(sizeof(int) * matrix->width)))
			print_error(2);
		while (j < matrix->width)
		{
			matrix->board[i][j] = 0;
			j += 1;
		}
		i += 1;
	}
}

void			mxfill(int *row, char *line, int width)
{
	char	**substr;
	int		i;

	i = 0;
	substr = ft_split(line, ' ');
	while (i < width)
	{
		row[i] = ft_atoi(substr[i]);
		i += 1;
	}
	i = 0;
	while (i < width)
	{
		free(substr[i]);
		i += 1;
	}
	free(substr);
}

void			getmatrix(char *filename, t_mx *matrix)
{
	int		fd;
	char	*line;
	int		y;

	y = 0;
	getsize(filename, matrix);
	if ((fd = open(filename, O_RDONLY)) == -1)
		print_error(1);
	mxalloc(matrix);
	while (get_next_line(fd, &line) > 0)
	{
		mxfill(matrix->board[y], line, matrix->width);
		if (*line != '\0')
			free(line);
		y += 1;
	}
	close(fd);
}
