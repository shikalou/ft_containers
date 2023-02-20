/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rbt.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:34:29 by ldinaut           #+#    #+#             */
/*   Updated: 2023/02/20 17:59:23 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rbt.hpp"
#include <iomanip>

void	print_tree(ft::node<int> *node, int flag)
{
	if (!node)
		return ;
	if (flag == 1)
		std::cout << "- R -" << std::endl;
	else if (flag == 2)
		std::cout << "- L -" << std::endl;
	if (node->node_color == 0)
		std::cout << "BLACK  ";
	else
		std::cout << "RED  ";
	std::cout << node->key << std::endl;
	print_tree(node->l_child, 2);
	print_tree(node->r_child, 1);
}

void	real_print(ft::node<int> *ptr, int space, ft::RBT<int> test)
{
	if (!ptr || ptr == test.getNull())
			return;
	space += 4;
	real_print(ptr->r_child, space, test);
	std::cout
			<< (ptr->node_color == black ? "\033[90m" : "\033[31m") << std::setw(space)
			<< ptr->key << "\033[0m" << std::endl;
	// getwchar();
	real_print(ptr->l_child, space, test);
}

int	main()
{
	ft::RBT<int> toto;

	toto.insert(50);
	toto.insert(8);
	toto.insert(99);
	toto.insert(1);
	toto.insert(54);
	toto.insert(7);
	toto.insert(16);
	toto.insert(43);
	toto.insert(71);
	toto.insert(83);
	toto.insert(987);
	toto.insert(12);
	toto.insert(52);

	real_print(toto.getRoot(), 0, toto);
}
