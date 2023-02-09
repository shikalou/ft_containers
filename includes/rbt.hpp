/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:30:13 by ldinaut           #+#    #+#             */
/*   Updated: 2023/02/09 19:36:01 by ldinaut          ###   ########.fr       */
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
			std::cout << "rbt construct" << std::endl;
			node_null->mother = NULL;
			node_null->l_child = NULL;
			node_null->r_child = NULL;
			node_null->node_color = node_null->black;
			root = node_null;
		}
		~RBT()
		{
			//std::cout << "rbt destruct" << std::endl;
		}
	private:
		node	*node_null;
		node	*root;
};

#endif
