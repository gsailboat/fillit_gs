/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:58:35 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/19 17:52:18 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_b
{
	char	**bd;
	int		b_size;
}					t_name;

char				**valid_tetrimino(void);
int					***ft_tet_coor(char **minos, int tetri);
int					issafe(char **board, int **tetri, int row, int col);
int					solver(int num_tets, int ***tetriminos, int n);
int					board_size(char **board);
void				free_map(t_name board);
void				p_solution(t_name grid);
void				p_period(int row, int col, int **tetrim, t_name grid);
char				*ft_strctrim(const char *s);
char				*ft_istwonew(const char *s, size_t num_words);
int					ft_tit_count(char const *string);
char				**ft_tet_split(const char *s);
int					validate_tetrino(char **string_shape);
char				**trim_tetriminos(char **string_shape, int tit_count);
int					is_valid(char *file, size_t file_buffer);
t_name				createsgrid(int n, t_name board);
t_name				createboard(int num_tets, int n);
int					isvalid(int row, int col, int **tetrimino, t_name grid);
int					p_tetrimino(int ***tet, t_name grid, int i, int num_tets);
int					solver(int num_tets, int ***tetriminos, int n);

#endif
