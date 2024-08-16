/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:24:08 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/16 16:50:00 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include "../libft/libft.h"

#define MAP_PX 30
#define PLAYER_COLOUR 0x00FFC0CB
#define MINIMAP_COLOUR 0x00FFFFFF

#define PLAYER_X 0
#define PLAYER_Y 0
#define PLAYER_SIZE 20

#define HEIGHT 300
#define WIDTH 300

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_pics
{
	t_data	*p_minimap;
	t_data	*mini_map_bckg;
}				t_pics;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int 	height;
	int		width;
	int		p_position[2];
	double	p_orient[3];
	t_pics	*img_list;
	char	**map;
} t_game;

// Exit
int	exit_program(t_game *game);

// Key Press
int	ft_key_press(int key_code, t_game *game);

// Init
t_game	*minilibx_init();

// Mini Map
void	ft_put_player_map(t_game *game);
int	ft_move(t_game *pms);
void	ft_minimap_bckg(t_game *game);

// Mlx Extra
void	mlx_px(t_data *img, int x, int y, int color);

