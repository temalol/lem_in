/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:27:05 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/22 01:13:34 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_hash_table(t_hash **h_table)
{
	size_t i;
	t_hash *node;
	
	i = 0;
	while(i < TABLE_SIZE)
	{
		if (h_table[i])
		{
			node = h_table[i];
			printf("h[%zu]=%s",i, node->node_name);
			node = node->next;
			while (node)
			{
				printf(" => [%zu]=%s",i, node->node_name);
				node = node->next;
			}
			printf("\n");
		}
		i++;
	}
}

void	print_hash_table_child(t_hash **h_table)
{
	size_t i;
	t_hash *node;
	t_child *child;
	
	i = 0;
	while(i < TABLE_SIZE)
	{
		if (h_table[i])
		{
			node = h_table[i];
			child = node->child;
			printf("h[%zu]=%s => ",i, node->node_name);
			while (child)
			{
				printf("%s =>", child->c_node->node_name);
				child = child->next;
			}
			node = node->next;
			while (node)
			{
				printf("\n===>[%zu]=%s =>",i, node->node_name);
				child = node->child;
				while (child)
				{
					printf("%s =>", child->c_node->node_name);
					child = child->next;
				}
				node = node->next;
			}
			printf("\n");
		}
		i++;
	}
}