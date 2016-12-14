/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:58:35 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/02 19:59:11 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define H_LINE "####"
# define V_LINE "#....#....#....#"
# define H_S "##..##"
# define V_S "#....##....#"
# define H_Z "##....##"
# define V_Z "#...##...#"
# define SQU "##...##"
# define N_L "#....#....##"
# define V_L "###..#"
# define U_L "##....#....#"
# define I_L "#..###"
# define N_J "#....#...##"
# define V_J "#....###"
# define U_J "##...#....#"
# define I_J "###....#"
# define N_T "###...#"
# define V_T "#...##....#"
# define U_T "#...###"
# define I_T "#....##...#"

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

char		*ft_strctrim(const char *s);
char		**ft_tet_split(const char *s);
int			ft_tit_count(char const *string);
char     	*ft_istwonew(const char *s, size_t num_words);
char		**valid_tetrimino(void);
int			***ft_tet_coor(char **minos, int tetri);
int			isSafe(char **board, int **tetri, int row, int col);
void 		solveTetrimino(int num_of_tetriminos, int N, int ***tetri);
void		printSolution(int N, char **board);
int 		board_size(char **board);

#endif
