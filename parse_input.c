/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 22:14:48 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/19 02:26:54 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	parse_ants_number()
{
	char	*line;
	int		ants_num;
	
	if (get_next_line(0, &line) > 0)
		{
			ants_num = ft_atoi_validate_pos(line);
			free(line);
			if (ants_num > 0)
				printf("Ant's number is %d\n", ants_num);
			else
				{
					printf("Ant's number is invalid\n");
					return (0);
				}
		}
	else
		{
			printf("File is Empty\n");
			return (0);
		}
	//printf("End of ants num parsing\n");
	return (ants_num);	
}



int	parse_node_name(char *line)
{
	int i;
	
	i = 0;

	if (!line[i])
	{
		printf("Nodes parsing error\n");
		exit(0);

	}	
	while(line[i] != ' ' && line[i] != '\0')	
	{
		{
			printf("%c", line[i]);
			i++;
		}	
		
	}
	printf("\n");
	return(1);
}

int	parse_input()
{
	char	*line;
	int 	ants_num;
	//int 	x;
	//int 	y;
	//int 	flag = 0;
	
	if ((ants_num = parse_ants_number()) < 1)
		exit (0);
	
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#' && line[1] == '#')
		{
			free(line);
			//flag = 1;
			continue;	
		}	
		parse_node_name(line);
		free(line);
	}	
		
	return (1);
}