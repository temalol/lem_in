/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:08:45 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/21 17:27:33 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	parse_start_node(char *line, t_graph *graph)
{
	t_hash *node;
	
	if (ft_strequ("##start", line))
			{
				printf("%s\n", line);
				free(line);
				if (graph->start)
					err_exit();
				if(get_next_line(0, &line) && (node = parse_node_name(line, graph->h_table)))
				{
						graph->start = node;
						free(line);
						return (1);
				}
				else
				{
					free(line);
					err_exit();
				}	
			}
	return (0);
}

int	parse_end_node(char *line, t_graph *graph)
{
	t_hash *node;
	
	if (ft_strequ("##end", line))
		{
			printf("%s\n", line);
			free(line);
			if (graph->end)
					err_exit();
				if(get_next_line(0, &line) && (node = parse_node_name(line, graph->h_table)))
				{
						graph->end = node;
						free(line);
						return (1);
				}
				else
				{
					free(line);
					err_exit();
				}	
			}
			return (0);
}