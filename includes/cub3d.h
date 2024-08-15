/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:24:08 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/15 19:56:06 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "../mlx_linux/mlx.h"
#include <stdlib.h>

#define MAP_PX 30
#define PLAYER_COLOUR 0x00FFC0CB

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int 	height;
	int		width;
	double p_orient[3];
} t_game;

// Exit
int	exit_program(t_game *game);

// Key Press
int	ft_key_press(int key_code, t_game *game);

// Init
t_game	*minilibx_init();

//Mini Map
void	ft_put_player_map(t_game *game);
int	ft_move(t_game *pms);

