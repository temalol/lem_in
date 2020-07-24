/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 22:20:56 by nmustach          #+#    #+#             */
/*   Updated: 2020/07/25 00:21:39 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


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
	t_hash *node;
	
	while (dijkstra(graph))
	{
		printf("\nPath %d:\n", i);
		dijkstra_shortest_reverse(graph);
		i++;
		printf("End Path\n");
	}
	
	
}