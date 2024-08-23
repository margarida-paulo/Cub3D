/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:24:08 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/23 11:36:40 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include "../libft/libft.h"
#include "keysymdef.h"

#define MAP_PX 30
#define PLAYER_COLOUR 0x00FFC0CB
#define MINI_WALL_COLOUR 0x00FFFFFF
#define MINI_FLOOR_COLOUR 0x00333333


#define PLAYER_X 2
#define PLAYER_Y 2
// GRID_SIZE / 3 is the size of the player.
#define GRID_SIZE 50
#define PLAYER_RAY 10
#define PLAYER_SIZE 30

#define HEIGHT 300
#define WIDTH 300

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct s_pics
{
	t_data	*minimap;
	t_data	*player;
}				t_pics;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int 	height;
	int		width;
	double	p_orient[3];
	t_pics	*img_list;
	char	**map;
	int		key_press;
	double		origin[2];
	t_data	*current_screen;
} t_game;

// Exit
int	exit_program(t_game *game);

// Key Press
void	ft_render_screen(t_game *game);
int	ft_key_press(int key_code, t_game *game);
int	ft_key_release(int key_code, t_game *game);
int	ft_rotate(t_game *game);

// Init
t_game	*minilibx_init();

// Mini Map
void	ft_build_player(t_game *game);
int		ft_move(t_game *pms);
void	ft_build_minimap(t_game *game);
t_data	*ft_merge_images(t_game *game, t_data *bottom, t_data *top, double *pos);

// Mlx Extra
void	mlx_px(t_data *img, int x, int y, int color);

