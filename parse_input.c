/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 22:14:48 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/21 02:49:37 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	err_exit()
{
	write(STDERR_FILENO, "ERROR\n", 6);
	exit(1);
}

void parse_comments(char *line, t_graph *graph)
{
	t_hash *node;
	
	if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strequ("##start", line) && !graph->start)
			{
				printf("%s\n", line);
				free(line);
				if(get_next_line(0, &line) && (node = parse_node_name(line, graph->h_table)))
				{
						graph->start = node;
						free(line);
						return;
				}
				else
				{
					free(line);
					err_exit();
				}	
			}
			
		else if (ft_strequ("##end", line) && !graph->end)
			{
				printf("%s\n", line);
				free(line);
				if(get_next_line(0, &line) && (node = parse_node_name(line, graph->h_table)))
				{
						graph->end = node;
						free(line);
						return;
				}
				else
				{
					free(line);
					err_exit();
				}	
			}
			
			else
			{
				free(line);
				err_exit();
			}
	}
	
	if (line[0] == '#')
		{
			printf("%s\n", line);
			free(line);
		}
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
				printf("%d\n", ants_num);
			else
				err_exit();
		}
	else 
		{
			//if gnl -1? 
			free(line);
			err_exit();
		}
	return (ants_num);	
}

t_hash	*parse_node_name(char *line, t_hash **h_table)
{
	int i;
	t_hash *node;
	
	i = 0;

	if (!line[i] || line[i] == ' ')
			err_exit();			
	while(line[i] != ' ' && line[i])	
			i++;
	if (line[i] == ' ')
	{
		line[i] = 0;
		node = assign_to_table(h_table, ft_strdup(line));
		printf("%s", line);
		printf(" %s\n",&line[i + 1]);
		return(node);
	}
	else
		return (NULL);
}

int	parse_input()
{
	char	*line;
	t_hash *node_ret;
	t_graph *graph = NULL;
	graph = malloc(sizeof(t_graph));
	graph->start = NULL;
	graph->end = NULL;
	if ((graph->ants_num = parse_ants_number()) < 1)
		err_exit();
	
	graph->h_table = hash_table_init();
	
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
		{
			parse_comments(line, graph);
			continue;
		}
		if ((node_ret = parse_node_name(line, graph->h_table)))
			free(line);
		else
			break;
	}
	printf("\n");
	print_hash_table(graph->h_table);
	free_hash_table(graph->h_table);
	free(graph);
	free(line);
	if (graph->start && graph->end)
		return (1);
	else
	{
		free(line);
		err_exit();
	}
	return 0;
}