/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:47:10 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/06 10:03:11 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <mlx.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>

/* -------- KEY VALUES -------- */
# define RIGHT_KEY 2
# define LEFT_KEY 0
# define DOWN_KEY 1
# define UP_KEY 13
# define ESC_KEY 53
# define WIN_CLOSE 17

/* -------- MAP -------- */
# define BUFF_SIZE 256
# define WALL '1'
# define EMPTY '0'
# define COL 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMY 'X'
# define SQUARE 32

/* -------- ERRORS -------- */
# define MALLOC_ERROR "so_long: Malloc failed to allocate enough memory."
# define DIR_ERROR "Is a directory!." 

/* -------- COLORS -------- */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"

/* ----- ENEMY ANIMATION FRAME ---- */
# define FRAME 7

/*-------------- STRUCTURES --------*/

// vector with x and y

typedef struct s_vec
{
	int	x;
	int	y;
}			t_vec;

// all MAP infos
typedef struct s_map
{
	char	**map;
	int		row;
	int		col;
	int		collectables;
	int		number_of_enemies;
	t_vec	*enemy;
	t_vec	player;
}			t_map;

// datas needed for the whole program
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		img_size;
	t_map	map;
	int		fd;
	int		can_exit;
	size_t	mv_count;
}			t_data;

/* -------- PARSER FUNCTIONS --------*/
void	get_map(char *file_name, t_data *data);
void	check_map(char *file_name, t_data *data);
void	check_dir(char *file_name);
int		check_characters(t_data data);
int		check_player(t_data data);
int		check_exit(t_data data);
int		check_ecp(t_data data);
int		check_extention(const char *haystack, const char *needle);
int		check_rectangular(t_data data);
int		check_walls(t_data *data);
void	get_collectables(t_data *data);
void	get_player_position(t_data *data);
int		map_len(int fd);
int		ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
bool	check_path_collectible(t_data *data);
bool	check_valid_path(t_data *data);

/* -------- ERROR FUNCTIONS --------*/
void	err_extention(char *file_name);
void	err_rectangular(t_data *data, char *file_name);
void	err_characters(t_data *data, char *file_name);
void	err_walls(t_data *data, char *file_name);
void	err_ecp(t_data *data, char *file_name);
void	err_player(t_data *data, char *file_name);
void	err_exit(t_data *data, char *file_name);
void	error_invalid_path(t_data *data, char *file_name);

/* -------- MOVEMENTS FUNCTIONS-------- */
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);

/*---------- get_next_line FUNCTIONS*/
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchrs(const char *s, int c);

/* -------- SO_LONG FUNCTIONS-------- */
int		ft_render_images(void *param);
void	ft_new_window(t_data *data);
int		ft_input(int key, void *program);
void	ft_free(t_data *data, char *msg);
void	free_map(t_data *data);
char	*ft_get_image(char c, int can_exit);
void	reset_struct(t_data *data);
char	*ft_itoa(int n);

/* ---- Test enemy movments ---- */
void	enemy_moves(t_data *data);
void	count_number_of_enemies(t_data *data);
void	get_enemies_positions(t_data *data);
void	ft_swap(char *a, char *b);

/*----------utils functions--------*/
bool	get_player_pozition(char **map, int rows, int *p_row, int *p_col);
void	copy_map(char **dest, char **src, int rows);
void	free_maps(char **map, int rows);

#endif
