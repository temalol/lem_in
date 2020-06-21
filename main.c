/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 22:10:51 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/22 01:58:16 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

int	main(int argc, char **argv)
{
	t_graph *graph;
	(void)(argc);
	(void)(argv);
	 graph = parse_input();
	 printf("\n");
	 print_hash_table_child(graph->h_table);
	 free_hash_table(graph->h_table);
	 free(graph);
}