/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:36:59 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/22 14:35:03 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	size;
	int	curr_x;
	int	curr_y;
}	t_point;

char		**read_and_parse(char *filename, char **key);
char		*read_line(int fd);
int			**ft_generate_int_map(char **map);
char		**solve(char **map, char *key);
void		p_cell(char **map, int **dp, t_point *best, char *key);
void		draw_square(char **map, t_point b, char full);
int			get_map_len(char **map);
void		print_map(char **map);
void		delete_map(char **map);
int			ft_strlen(char *str);

#endif
