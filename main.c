/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 22:10:51 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/27 21:20:00 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

int	main(int argc, char **argv)
{
	t_graph *graph;
	(void)(argc);
	(void)(argv);
	 graph = parse_input();
	 printf("\n\n%s", graph->map_buf);
	// //  printf("\nStart node:%s\nEnd node:%s\n\n", graph->start->node_name, graph->end->node_name);
	//  print_hash_table_child(graph->h_table);
	//  free_hash_table(graph->h_table);
	//  free(graph);
}