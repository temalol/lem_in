/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:44:25 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/20 22:44:15 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_hash	**hash_table_init()
{
	size_t i;
	t_hash **hash_table;
	
	i = 0;
	hash_table = malloc(sizeof(t_hash*) * TABLE_SIZE);
	
	while(i < TABLE_SIZE)
	{
		*hash_table = NULL;
		i++;
	}
	return(hash_table);
}

t_hash	*assign_to_table(t_hash **table, char *node_name)
{
	t_hash *new;
	unsigned int hash_val; 
	
	hash_val = calc_hash(node_name);
	
	if (table[hash_val] == NULL )
	{
		new = malloc(sizeof(t_hash));
		new->next = NULL;
		new->x = 0;
		new->y = 0;
		new->node_name = node_name;
		table[hash_val] = new;
	}
	else
	{
		t_hash *node;
		
		node = table[hash_val]; 
		while(node)
		{
			if (ft_strequ(node_name, node->node_name))
				err_exit();
			node = node->next;
		}
		node = table[hash_val]; 
		new = malloc(sizeof(t_hash));
		new->next = NULL;
		new->x = 0;
		new->y = 0;
		new->node_name = node_name;
		while (node->next)
			node = node->next;
		node->next = new;	
	}
	return (new);
}

unsigned int	calc_hash(char *node_name)
{
	unsigned long int value;
    unsigned int i;

	value = 0;
		i = 0;
	
	while (node_name[i])
			value = value * 37 + node_name[i++];
	return (value % TABLE_SIZE);
}
