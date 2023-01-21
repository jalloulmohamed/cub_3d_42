/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:00:39 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 18:51:26 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mlx.h"
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include"libft/libft.h"
# include "get_next_line/get_next_line.h"
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define SIZE  50
# define W_WIDTH 1200
# define W_HEIGHT 550
# define STEP 8
# define VIEW 1.0471975512 

typedef struct s_theme
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	unsigned int	floor;
	unsigned int	ciel;
}t_theme;

typedef struct s_data
{
	void			*img;
	unsigned int	*adr1;
	unsigned int	*adr2;
	unsigned int	*adr3;
	unsigned int	*adr4;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}t_data;

typedef struct s_cub3d
{
	t_theme	theme;
	t_data	data;
	void	*mlx;
	void	*mlx_win;
	int		z;
	int		e;
	float	p_x;
	float	p_y;
	float	alpha;
	int		key_to_move_x;
	int		key_to_move_y;
	int		key_to_rot;
	char	ray_type;
	char	**map_2d;
	int		map_w;
	int		map_h;
	double	x_wall;
	double	y_wall;
}t_cub3d;

void	map(int fd);
int		nbr_v(char *s);
int		path_valid(char *s, char **tex);
int		check_color(char *s, unsigned int *var);
int		ft_ln2d(char **map2d);
void	window(t_cub3d cub);
// utils
int		derection(t_cub3d *var);
void	pos_player(t_cub3d *var, char **map_2d);
int		key_event(int key, t_cub3d *var);
int		ref(int key, t_cub3d *var);
int		exit_game(int key);
int		ft_down(double angle);
int		ft_up(double angle);
int		ft_right(double angle);
int		ft_left(double angle);
double	cor_angle(double angle);
void	flor_y(t_cub3d *var, double *y, double ray_angle);
void	flor_x(t_cub3d *var, double *x, double ray_angle);
void	rays(t_cub3d *var);
void	ft_ln2d_w_h(t_cub3d *var);
void	rindring_image(t_cub3d *var);
void	my_mlx_pixel_put(t_cub3d *var, int x, int y, int color);
double	des(t_cub3d *var, double x, double y);
void	rindring3d(t_cub3d *var, int ray_3d, double angle);
void	inters(t_cub3d *var, double angle, double *x_wall, double *y_wall);
void	up_right(t_cub3d *var, double florx, double flory, double ray_angle);
void	up_left(t_cub3d *var, double florx, double flory, double ray_angle);
void	down_right(t_cub3d *var, double florx, double flory, double ray_angle);
void	down_left(t_cub3d *var, double florx, double flory, double ray_angle);
int		ft_ln2d(char **map2d);
int		check_map1(char **map2d, int i, int j);

#endif