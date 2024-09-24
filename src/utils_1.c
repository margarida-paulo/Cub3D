/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:02:06 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/23 00:02:44 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Calculates the area of a triangle given its vertices.
 *
 * @param xy1 The first vertex of the triangle.
 * @param xy2 The second vertex of the triangle.
 * @param xy3 The third vertex of the triangle.
 *
 * @return The area of the triangle.
 */
double	area_triangle(double xy1[2], double xy2[2], double xy3[2])
{
	return (fabs((xy1[0] * (xy2[1] - xy3[1]) + xy2[0] * (xy3[1] - xy1[1]) + \
	xy3[0] * (xy1[1] - xy2[1])) / 2.0));
}

/**
 * @brief Checks if a given point is inside a triangle.
 *
 * @param xy1 The first vertex of the triangle.
 * @param xy2 The second vertex of the triangle.
 * @param xy3 The third vertex of the triangle.
 * @param xy The point to check.
 *
 * @return 1 if the point is inside the triangle, 0 otherwise.
 */
int	is_inside_triangle(double xy1[2], double xy2[2], double xy3[2], double p[2])
{
	float	a;
	float	a1;
	float	a2;
	float	a3;

	a = area_triangle(xy1, xy2, xy3);
	a1 = area_triangle(p, xy2, xy3);
	a2 = area_triangle(xy1, p, xy3);
	a3 = area_triangle(xy1, xy2, p);
	return (round(a) == round(a1 + a2 + a3));
}

/**
 * @brief Calculates the Euclidean distance between two points.
 *
 * @param x1 The x coordinate of the first point.
 * @param y1 The y coordinate of the first point.
 * @param x2 The x coordinate of the second point.
 * @param y2 The y coordinate of the second point.
 * @return The Euclidean distance between the two points.
 */
double	ft_distance(int x1, int y1, int x2, int y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}
