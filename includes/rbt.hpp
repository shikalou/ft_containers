/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:30:13 by ldinaut           #+#    #+#             */
/*   Updated: 2023/02/09 23:11:53 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP

#include <iostream>

struct node
{
	enum color
	{
		black = 0,
		red = 1
	};

	int		key;
	color	node_color;
	node	*mother;
	node	*l_child;
	node	*r_child;
};

class RBT
{
	public:
		RBT()
		{
			// std::cout << "rbt construct" << std::endl;
			node_null = new node;
			node_null->mother = NULL;
			node_null->l_child = NULL;
			node_null->r_child = NULL;
			node_null->node_color = black;
			root = node_null;
		}
		~RBT()
		{
			//std::cout << "rbt destruct" << std::endl;
		}

		void	insert(int newkey)
		{
			if (root == node_null)
			{
				root->key = newkey;
				root->node_color = black;
			}
		}
	private:
		node	*node_null;
		node	*root;
};

#endif
