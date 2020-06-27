/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 22:10:51 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/27 23:40:17 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


unsigned long ml = 0;
unsigned long fr = 0;

#include "lem_in.h"

int	main(int argc, char **argv)
{
	t_graph *graph;
	(void)(argc);
	(void)(argv);
	 graph = parse_input();
	// printf("\nStart node:%s\nEnd node:%s\n\n", graph->start->node_name, graph->end->node_name);
	//print_hash_table_child(graph->h_table);
	 write(1, graph->map_buf, ft_strlen(graph->map_buf));
	 free_hash_table(graph->h_table);
	 free(graph->map_buf);
	 fr++;
	 free(graph);
	 fr++;
	 printf("\nMalloc:%lu Free:%lu",ml, fr);
}