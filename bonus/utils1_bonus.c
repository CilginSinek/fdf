/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:47:22 by iduman            #+#    #+#             */
/*   Updated: 2025/08/20 18:47:22 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	get_color(char *value)
{
	int	color;
	int	r;
	int	g;
	int	b;
	int	t;

	r = 255;
	g = 255;
	b = 255;
	t = 0xFF;
	if (ft_strchr(value, ','))
	{
		value = ft_strchr(value, ',') + 1;
		if (value[0] == '0' && (value[1] == 'x' || value[1] == 'X'))
			value += 2;
		color = ft_atoi_base(value, "0123456789ABCDEF");
		r = (color >> 16) & 0xFF;
		g = (color >> 8) & 0xFF;
		b = color & 0xFF;
	}
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_video_color(char *value)
{
	int	color;
	int	r;
	int	g;
	int	b;
	int	t;

	r = 255;
	g = 255;
	b = 255;
	t = 0xFF;
	if (value[0] == '0' && (value[1] == 'x' || value[1] == 'X'))
		value += 2;
	color = ft_atoi_base(value, "0123456789ABCDEF");
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	return (t << 24 | r << 16 | g << 8 | b);
}
