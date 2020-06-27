/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 22:10:51 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/28 02:54:39 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


unsigned long ml = 0;
unsigned long fr = 0;

#include "lem_in.h"

int	main()
{
	t_graph *graph;
	 graph = parse_input();
	 write(1, graph->map_buf, ft_strlen(graph->map_buf));
	 printf("\n\n");
	// print_hash_table_child(graph->h_table);
	 printf("\nStart node:%s\nEnd node:%s\n\n", graph->start->node_name, graph->end->node_name);
	 free_hash_table(graph->h_table);
	 FCNT(free(graph->map_buf));
	 FCNT(free(graph));
	 printf("\n\nMalloc:%lu Free:%lu\n",ml, fr);
}