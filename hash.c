/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:44:25 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/22 01:20:07 by nmustach         ###   ########.fr       */
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
		new->child = NULL;
		new->x = 0;
		new->y = 0;
		new->node_name = node_name;
		table[hash_val] = new;
	}
	else
	{
		t_hash *node;
		
		//node = table[hash_val]; 
		/*while(node)
		{
			if (ft_strequ(node_name, node->node_name))
				err_exit();
			node = node->next;
		}*/
		node = table[hash_val]; 
		new = malloc(sizeof(t_hash));
		new->next = NULL;
		new->child = NULL;
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
			value = value * HASH_MULT + node_name[i++];
	return (value % TABLE_SIZE);
}

void	free_hash_table(t_hash **h_table)
{
	size_t i;
	t_hash *node;
	t_hash *next;
	
	i = 0;
	while(i < TABLE_SIZE)
	{
		if (h_table[i])
		{		
			node = h_table[i];
			while (node)
			{
				next = node->next;
				free(node->node_name);
				free(node);
				node = next;
			}
		}
		i++;
	}
	free(h_table);
}


t_hash	*hash_query(t_hash **h_table, char *node_name)
{
	t_hash *node;
	unsigned int hash_val;

	hash_val = calc_hash(node_name);
	
	if(h_table[hash_val] == NULL)
		return (NULL);
	
	node = h_table[hash_val];	
	while (node)
	{
		if (ft_strequ(node_name, node->node_name))
			return (node);
		node = node->next;
	}
	return (NULL);
}