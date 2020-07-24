/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 22:20:56 by nmustach          #+#    #+#             */
/*   Updated: 2020/07/25 03:10:40 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void dijkstra_shortest(t_graph *graph)
 {
 	t_hash *node;

 	node = graph->end->prev;
 	printf("%s=>", graph->end->node_name);
 	while (node != graph->start)
 	{
 		printf("%s=>", node->node_name);
 		node->visit = 1;
		node = node->prev;
 	}
 	printf("%s", node->node_name);
 }

t_child		*get_edge(t_child *haystack, t_hash *needle)
{
	while (haystack)
	{
		if(haystack->c_node == needle)
			return (haystack);
		haystack = haystack->next;
	}
	return NULL;
}


void	get_paths(t_graph *graph)
{
	int i = 1;
	t_hash *tmp;
	
	while (dijkstra(graph))
	{
		//printf("\nPath %d:\n", i);
		dijkstra_shortest_reverse(graph);
		i++;
		//printf("End Path\n");
	}
	
	tmp = graph->end;
	graph->start->mark = INT_MAX;
	graph->end = graph->start;
	graph->start = tmp;
	graph->start->visit = 0;
	graph->end->visit = 0;
	while(dijkstra(graph))
	{
		dijkstra_shortest(graph);
		printf("\n");
	}
}