/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:49:39 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/22 14:44:46 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

char	*file_read(char *file_to_read);
char	*read_line(int file);
char	**copy_map(char **map);
char	**read_and_parse(char *filename, char **key);
char	**solve(char **map, char *key);
void	print_map(char **map);
void	delete_map(char **map);

int	take_input(int argc, char **argv, char ***files_to_read)
{
	if (argc == 1)
	{
		*files_to_read = malloc(2 * sizeof(char **));
		if (*files_to_read != NULL)
		{
			(*files_to_read)[1] = NULL;
			(*files_to_read)[0] = read_line(1);
			if ((*files_to_read)[0] != NULL)
				return (0);
		}
	}
	else
	{
		*files_to_read = copy_map(argv);
		if (*files_to_read != NULL)
			return (0);
	}
	return (-1);
}

void	p_files(char **files, char *key, int i)
{
	char	**map;

	while (files[i] != NULL)
	{
		map = read_and_parse(files[i], &key);
		if (map != NULL)
		{
			map = solve(map, key);
			print_map(map);
			delete_map(map);
		}
		else
			write(1, "map error\n", 10);
		i++;
	}
}

// key[0] = the "empty" char
// key[1] = the "obstacle" char
// key[2] = the "full" char
int	main(int argc, char **argv)
{
	char	**files;
	char	*key;

	key = malloc(4 * sizeof(char));
	if (!key || take_input(argc, argv, &files) == -1)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	if (argc > 1)
		p_files(files, key, 1);
	else
		p_files(files, key, 0);
	delete_map(files);
	free(key);
	return (0);
}
/*int	main(int argc, char **argv)
{
	char	**files_to_read;
	char	**current_map;
	char	*key;
	int		i;

	key = malloc(4 * sizeof(char));
	if (key == NULL || take_input(argc, argv, &files_to_read) == -1)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	i = 0;
	if (argc > 1)
		i = 1; 
	while (files_to_read[i] != NULL)
	{
		current_map = read_and_parse(files_to_read[i], &key);
		if (current_map != NULL)
		{
			current_map = solve(current_map, key);
			print_map(current_map);
			delete_map(current_map);
		}
		else
			write(2, "map error\n", 10);
		i++;
	}
	return (0);
}*/
