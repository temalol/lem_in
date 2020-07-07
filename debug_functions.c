/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:27:05 by nmustach          #+#    #+#             */
/*   Updated: 2020/07/07 16:45:41 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_queue(t_q *queue)
{
	while (queue)
	{
		printf("%s\n", queue->q_node->node_name);
		queue = queue->next;
	}
}


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
	char *f_next = "hash[%zu]= \"%s\" =>";
	char *f_end = "hash[%zu]=\"%s\"";
	char *f_ch_next = " \"%s\" =>";
	char *f_ch_end = " \"%s\" ";
	
	i = 0;
	while(i < TABLE_SIZE)
	{
		if (h_table[i])
		{
			node = h_table[i];
			child = node->child;
			if (child != NULL)
				printf(f_next,i, node->node_name);
			else
				printf(f_end,i, node->node_name);
			
			while (child)
			{
				if (child->next)
					printf(f_ch_next, child->c_node->node_name);
				else
					printf(f_ch_end, child->c_node->node_name);
				child = child->next;
			}
			node = node->next;
			while (node)
			{
				printf("\n======>[%zu]= \"%s\" =>",i, node->node_name);
				child = node->child;
				while (child)
				{
					if (child->next)
						printf(f_ch_next, child->c_node->node_name);
					else
						printf(f_ch_end, child->c_node->node_name);
					child = child->next;
				}
				node = node->next;
			}
			printf("\n");
		}
		i++;
	}
}