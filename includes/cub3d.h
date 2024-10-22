/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:24:08 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/28 20:21:35 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

//Color codes for ft_printf
# define DEFAULT "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

//keys
# define XK_LEFT 0xff51  /* Move left, left arrow */
# define XK_UP 0xff52  /* Move up, up arrow */
# define XK_RIGHT 0xff53  /* Move right, right arrow */
# define XK_DOWN 0xff54  /* Move down, down arrow */
# define XK_SPACE 0x0020  /* U+0020 SPACE */
# define XK_W 0x0077  /* U+0077 LATIN SMALL LETTER W */
# define XK_A 0x0061  /* U+0061 LATIN SMALL LETTER A */
# define XK_S 0x0073  /* U+0073 LATIN SMALL LETTER S */
# define XK_D 0x0064  /* U+0064 LATIN SMALL LETTER D */
# define XK_0 0x0030  /* U+0030 DIGIT ZERO */
# define XK_1 0x0031  /* U+0031 DIGIT ONE */
# define XK_2 0x0032  /* U+0032 DIGIT TWO */
# define XK_3 0x0033  /* U+0033 DIGIT THREE */
# define XK_4 0x0034  /* U+0034 DIGIT FOUR */
# define XK_5 0x0035  /* U+0035 DIGIT FIVE */
# define XK_6 0x0036  /* U+0036 DIGIT SIX */
# define XK_7 0x0037  /* U+0037 DIGIT SEVEN */
# define XK_8 0x0038  /* U+0038 DIGIT EIGHT */
# define XK_9 0x0039  /* U+0039 DIGIT NINE */
# define XK_ESCAPE 0xff1b

# define VALID_CHARS "01NSWE \n"
# define HORIZONTAL 0
# define VERTICAL 1
# define PLAYER_CLR 0x00FFC0CB
# define WALL_CLR 0x00FFFFFF
# define MINI_FLOOR_CLR 0x00333333
# define PLAYER_X 2
# define PLAYER_Y 2
# define GRID_SIZE 50
# define PLAYER_RAY 10
# define PLAYER_SIZE 30
# define FOV M_PI
# define HEIGHT 300
# define WIDTH 300
# define WIN_HEIGHT 600
# define WIN_WIDTH 800
# define MOVE_SPEED 10
# define SENSITVITY 50.0
# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT 200
# define HEAD_BOB_AMPLITUDE 5.0
# define HEAD_BOB_FREQUENCY 0.2

enum e_exit_codes
{
	INVALID_ARG_CNT = 1,
	INVALID_EXTENTION,
	CAN_NOT_OPEN,
	CAN_NOT_OPEN_TEXTURE,
	CAN_NOT_MALLOC_TEXTURE,
	MLX_XPM_TO_IMG_FAIL,
	MISSING_ELEMENTS,
	DUPLICATED_ELEMENTS,
	MAP_TOO_SMALL,
	INVALID_CHARS,
	INVALID_P_CNT,
	INVALID_BORDERS,
	NEWLINES_IN_MAP,
};

enum e_wall_types
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3
};

enum e_game_states
{
	STATE_MENU,
	STATE_PLAYING
};

typedef struct s_data
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
	t_data	*wall[4];
	t_data	*screen;
	t_data	*start_screen;
	t_data	*cropped_minimap;
}				t_pics;

typedef struct s_game	t_game;

typedef struct s_map
{
	t_game	*game;
	int		map_start; //the starting index of the map in the .cub file
	char	**map_array;
	char	*no_texture; //./path_to_the_north_texture
	char	*so_texture; //./path_to_the_south_texture
	char	*we_texture; //./path_to_the_west_texture
	char	*ea_texture; //./path_to_the_east_texture
	char	*f_color; //∗ Floor color: F 220,100,0
	char	*c_color; //* Ceiling color: C 225,30,0
	int		f_color_val;
	int		c_color_val;
	int		flag_duplicate_elements;
}	t_map;

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
	double	tex_pos;
}	t_ray;

// fov = Field of Vision IN RADIANS
typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		width;
	double	p_orient[3];
	t_pics	*img_list;
	int		key_press;
	double	origin[2];
	t_data	*current_screen;
	t_map	map;
	double	fov;
	double	move_rate;
	void	*game_window;
	int		prev_wall_type;
	int		state;
	double	head_bob_offset;
	double	head_bob_phase;
	double	v1[2];
	double	v2[2];
	double	v3[2];
	int		p_center[2];
	t_ray	ray;
}	t_game;

// args.c
int		is_valid_extension(char *map_file_name);
int		cub_file_cnt_lines(char **argv);
char	**get_cub_file_arr(char **argv);

// error.c
int		print_error_0(int error, char *str);
int		print_error_1(int error, t_map *map);
int		print_error_2(int error, t_map *map);
int		print_error_3(int error, t_map *map);
int		print_error_4(int error, t_map *map);

// exit.c
int		exit_program(t_game *game);

// free.c
void	free_map_struct(t_map *map);
void	free_2d_array(char **src);
void	free_visited(int **visited, t_map *map);
void	free_img(t_game *game, t_data *img);
void	free_wall_textures(t_game *game);

// gameplay.c
int		ft_gameplay(t_game *game);

// init.c
t_data	*init_img(t_game *game, int width, int height);
int		**init_visited_arr(t_map *map);
void	minilibx_init_helper(t_game *game);
void	minilibx_init(t_game *game);
void	ft_init_cropped_minimap(t_game *game);

// key_press.c
int		ft_rotate(t_game *game);
int		ft_key_release(int key_code, t_game *game);
int		ft_key_press(int key_code, t_game *game);

// map_checks_0.c
int		check_map_invalid_chars(t_map *map);
int		check_map_player_cnt(t_map *map);
int		check_cells(t_map *map, int **visited, int i);
int		check_map_borders(t_map *map);

// map_checks_1.c
int		is_in_bounds(int x, int y, t_map *map);
int		flood_fill(t_map *map, int **visited, int x, int y);

// map_setter.c
void	set_element_util(char *trimmed_line, char *tmp, size_t len, t_map *map);
void	set_elements(t_map *map, char *line);
void	set_p_orient_angle(t_map *map, char c);
int		set_p_orient_arr(t_map *map);
void	set_width_and_height(t_map *map);

// map.c
void	parse_map(t_map *map, char **argv);
int		parse_color_str(char *color_str);
void	parse_color(t_map *map);
void	check_map_requirements(t_map *map);
int		check_map_nl(t_map *map);

// mini_map_0.c
void	ft_clear_img(t_data *img, int width, int height);
void	ft_bckg_square(t_game *game, int curr_x, int curr_y);
void	crop_minimap_around_player(t_game *game);
void	ft_build_minimap(t_game *game);
void	ft_set_player_info(t_game *game);

// mini_map_1.c
void	copy_non_zero_pixels(t_data *src, t_data *dst, \
int x_offset, int y_offset);
t_data	*ft_merge_images(t_game *game, t_data *bottom, \
t_data *top, double *pos);
void	ft_build_player(t_game *game);
void	ft_draw_ray(t_game *game, double ray_size, double angle);

// mlx_extra.c
void	mlx_px(t_data *img, int x, int y, int color);

// movement.c
int		is_near_wall(t_game *game, double x, double y);
void	ft_move(t_game *game);
void	update_head_bob(t_game *game);

// raycasting_utils.c
int		get_px_color(t_data *img, int x, int y);
char	is_inside_map_ver(t_game *game, t_ray *ray, int x_n, int y_n);
char	is_inside_map_hor(t_game *game, t_ray *ray, int x_n, int y_n);
double	*find_vertical_inter(t_game *game, t_ray *ray);
double	*find_horizontal_inter(t_game *game, t_ray *ray);

// raycasting.c
void	ft_set_ray_angle_info(t_ray *ray, double angle);
void	ft_ray_init(t_ray *ray, double angle, t_game *game);
void	cast_rays(t_game *game);
void	calculate_wall_height(t_game *game, t_ray *ray, \
		int *draw_start, int *draw_end);
void	set_texture_coordinates(t_game *game, t_ray *ray, int draw_start);

// rendering.c
void	ft_render_screen(t_game *game);
void	render_menu(t_game *game);
void	render(t_game *game, t_ray *ray, int x);
void	draw_wall_slice(t_game *game, int x, int draw_start, int draw_end);
void	render_floor_ceiling(t_game *game);

// test.c
void	test_print_2d_map_array(char **arr);
void	test_print_map_struct_data(t_map *map);

// textures.c
void	load_all_textures(t_game *game);
t_data	*load_texture(t_game *game, char *path);
void	ft_set_wall_type(t_ray *ray);

//utils_0.c
size_t	get_max_len_in_array(char **arr);
char	*pad_string(char *str, size_t max_len);
char	**normalize_array(char **arr);
char	**copy_array_from_index(char **src_arr, int i);
char	*trim_leading_spaces(char *str);

//utils_1.c
double	area_triangle(double xy1[2], double xy2[2], double xy3[2]);
int		is_inside_triangle(double xy1[2], \
double xy2[2], double xy3[2], double p[2]);
double	ft_distance(int x1, int y1, int x2, int y2);
int		ft_cntchr(char *str, char c);
int		is_numeric(char *str);

#endif
