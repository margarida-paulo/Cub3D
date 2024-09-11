/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:24:08 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/11 09:47:47 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"
#include "keysymdef.h"

//Color codes for ft_printf
# define DEFAULT "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

# define VALID_CHARS "01NSWE \n"

enum exit_codes {
	INVALID_ARG_CNT = 1,
	INVALID_EXTENTION,
	CAN_NOT_OPEN,
	MISSING_ELEMENTS,
	MAP_TOO_SMALL,
	INVALID_CHARS,
	INVALID_P_CNT,
	INVALID_BORDERS,
	NEWLINES_IN_MAP,
    // Add other exit codes here
};

#define HORIZONTAL 0
#define VERTICAL 1

enum wall_types {
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3
};

#define MAP_PX 30
#define PLAYER_CLR 0x00FFC0CB
#define WALL_CLR 0x00FFFFFF
#define MINI_FLOOR_CLR 0x00333333


#define PLAYER_X 2
#define PLAYER_Y 2
#define GRID_SIZE 50
#define PLAYER_RAY 10
#define PLAYER_SIZE 30
#define FOV M_PI / 3
#define HEIGHT 300
#define WIDTH 300
#define WIN_HEIGHT 600
#define WIN_WIDTH 800

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
	t_data	wall[4];
	t_data	*screen;
}				t_pics;

typedef struct s_game t_game;

typedef struct	s_map
{
	t_game	*game;
	int		map_start; //the starting index of the map in the .cub file
	char**	map_array;
	char*	no_texture; //./path_to_the_north_texture
	char*	so_texture; //./path_to_the_south_texture
	char*	we_texture; //./path_to_the_west_texture
	char*	ea_texture; //./path_to_the_east_texture
	char*	f_color; //∗ Floor color: F 220,100,0
	char*	c_color; //* Ceiling color: C 225,30,0
}	t_map;

// fov = Field of Vision IN RADIANS
typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int 	height;
	int		width;
	double	p_orient[3];
	t_pics	*img_list;
	int		key_press;
	double		origin[2];
	t_data	*current_screen;
	t_map	map;
	double		fov;
	double		move_rate;
} t_game;

typedef struct s_ray
{
	double	angle;
	int		multiplier_x;
	int		multiplier_y;
	double	sin;
	double	cos;
	double	distance;
	double	x_n;
	double	y_n;
	int		inter_type;
	int		wall_type;
	int		line_height;
	int		tex_x;
} t_ray;

// Exit
int	exit_program(t_game *game);

// Key Press
void	ft_render_screen(t_game *game);
int	ft_key_press(int key_code, t_game *game);
int	ft_key_release(int key_code, t_game *game);
int	ft_rotate(t_game *game);

// Init
t_data	*init_img(t_game *game, int width, int height);
void	minilibx_init(t_game *game);
int		**init_visited_arr(t_map *map);

// Mini Map
void	ft_build_player(t_game *game);
void		ft_move(t_game *pms);
void	ft_build_minimap(t_game *game);
t_data	*ft_merge_images(t_game *game, t_data *bottom, t_data *top, double *pos);
double	ft_distance(int x1, int y1, int x2, int y2);

// Mlx Extra
void	mlx_px(t_data *img, int x, int y, int color);

//args.c
int		is_valid_extension(char *map_file_name);
int		cub_file_cnt_lines(char **argv);
char	**get_cub_file_arr(char **argv);

//error.c
int		print_error_0(int exit_code, char *str);
int		print_error_1(int exit_code, t_map *map);
int		print_error_2(int error, t_map* map);

//free.c
void	free_map_struct(t_map *map);
void	free_2d_array(char **src);
void	free_visited(int **visited, t_map *map);

//map_setter.c
void	set_elements(t_map *map, char *line);
void	set_p_orient_angle(t_map *map, char c);
int		set_p_orient_arr(t_map *map);
void	set_width_and_height(t_map *map);

//map_checks.c
int		check_map_invalid_chars(t_map *map);
int		check_map_player_cnt(t_map *map);
int		is_within_bounds(int x, int y, t_map *map);
int		flood_fill(t_map *map, int **visited, int x, int y);
int		check_map_borders(t_map *map);
int		check_map_nl(t_map *map);

//map.c
void	parse_map(t_map *map, char **argv);
void	check_map_requirements(t_map *map);

//utils.c
char	*trim_leading_spaces(char *str);
char	**copy_array_from_index(char **src_arr, int i);

//test.c
void	test_print_2D_map_array(char** arr);
void	test_print_map_struct_data(t_map *map);

//raycasting_utils.c
int	get_px_color(t_data *img, int x, int y);
char	is_inside_map(t_game *game, t_ray *ray, int x_n, int y_n);

//raycasting.c
double	*find_vertical_inter(t_game *game, t_ray *ray);
double	*find_horizontal_inter(t_game *game, t_ray *ray);
void	ft_draw_ray(t_game *game, double ray_size, double angle);
void	ft_ray_init(t_ray *ray, double angle, t_game *game);
void	cast_rays(t_game *game);

void	load_wall_textures(t_game* game);
t_data	*load_texture(void *mlx, char *path);
void	render(t_game *game, t_ray *ray, int x);
void	draw_wall_slice(t_game* game, t_ray *ray, int x, int draw_start, int draw_end);
void	set_texture_coordinates(t_game* game, t_ray* ray);
void	calculate_wall_height(t_game* game, t_ray* ray, int* draw_start, int* draw_end);


#endif
