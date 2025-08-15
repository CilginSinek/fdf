/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:59:04 by iduman            #+#    #+#             */
/*   Updated: 2025/08/15 09:17:34 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

/**
 * ep
 * @brief Error exit preparing function to print error message and clean up.
 * @param message: The error message to print.
 * @param fdf: Pointer to the fdf structure containing map data.
 * @param free_list: Array of pointers to free after error handling.
 * 1st element is for t_point *row data, 2nd for line.
 * @param fd: File descriptor to close.
 */
int	ep(char *message, t_fdf *fdf, void **free_list, int fd)
{
	int	i;

	i = 0;
	ft_putstr_fd(message, 2);
	if (fdf != NULL && fdf->map != NULL)
	{
		if (*fdf->map)
		{
			while (i < fdf->height)
			{
				free(fdf->map[i]);
				i++;
			}
			free(fdf->map);
		}
	}
	if (free_list[0] != NULL)
		free(free_list[0]);
	if (free_list[1] != NULL)
		free(free_list[1]);
	close(fd);
	return (-1);
}

int	append_2d_point_array(t_point ***mp_d, t_point *new_row, int height)
{
	t_point	**temp;
	int		i;

	i = 0;
	if (!*mp_d)
	{
		*mp_d = (t_point **)ft_calloc(1, sizeof(t_point *));
		if (!*mp_d)
			return (-1);
		(*mp_d)[0] = new_row;
		return (0);
	}
	temp = (t_point **)ft_calloc((height + 1), sizeof(t_point *));
	if (!temp)
		return (-1);
	while (i < height)
	{
		temp[i] = (*mp_d)[i];
		i++;
	}
	temp[height] = new_row;
	free(*mp_d);
	*mp_d = temp;
	return (0);
}

int	ft_get_line_length(char *line)
{
	char	**tmp;
	int		length;
	int		i;

	tmp = ft_split(line, ' ');
	if (!tmp)
		return (-1);
	length = 0;
	while (tmp[length] && tmp[length][0] != '\n')
		length++;
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (length);
}

int	get_color(char *value)
{
	if (ft_strchr(value, ','))
		return (ft_atoi_base(ft_strchr(value, ',') + 1, "0123456789ABCDEF"));
	return (0xFFFFFF);
}

int	set_map_line(char *line, t_point *point, int y)
{
	char	**values;
	int		i;

	values = ft_split(line, ' ');
	if (!values)
		return (-1);
	i = 0;
	while (values[i])
	{
		point[i].x = i;
		point[i].y = y;
		point[i].z = ft_atoi(values[i]);
		point[i].color = get_color(values[i]);
		i++;
	}
	i = 0;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
	return (i);
}
