/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 22:14:48 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/20 16:11:49 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	err_exit()
{
	write(STDERR_FILENO, "ERROR\n", 6);
	exit(1);
}

int	parse_ants_number()
{
	char	*line;
	int		ants_num = 0;
	
	if (get_next_line(0, &line) > 0)
		{
			ants_num = ft_atoi_validate_pos(line);
			free(line);
			if (ants_num > 0)
				printf("Ant's number is %d\n", ants_num);
			else
				err_exit();
		}
	else
		err_exit();
	return (ants_num);	
}



int	parse_node_name(char *line, t_hash **h_table)
{
	int i;
	
	i = 0;

	if (!line[i])
			err_exit();
	while(line[i] != ' ' && line[i])	
			i++;
	if (line[i] == ' ')
	{
		line[i] = 0;
		i = 0;
		assign_to_table(h_table, ft_strdup(line));
		while (line[i])
		{
			printf("%c", line[i]);
			i++;
		}
		printf("\n");
		return(1);
	}
	else
		return(0);
	
}

int	parse_input()
{
	char	*line;
	int 	ants_num;
	t_hash **h_table;
	//int 	x;
	//int 	y;
	//int 	flag = 0;
	
	if ((ants_num = parse_ants_number()) < 1)
		err_exit();
	h_table = hash_table_init();
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#' && line[1] == '#')
		{
			printf("%s\n", line);
			free(line);
			//flag = 1;
			continue;	
		}	
		if (parse_node_name(line, h_table))
			free(line);
		//else
			//err_exit();
	}
	printf("\n");
	print_hash_table(h_table);
	return (1);
}