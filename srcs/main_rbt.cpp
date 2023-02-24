/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rbt.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:34:29 by ldinaut           #+#    #+#             */
/*   Updated: 2023/02/24 15:00:05 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rbt.hpp"
#include "../includes/map.hpp"
#include "../includes/make_pair.hpp"
#include <iomanip>
#include <iostream>
#include <map>

// void	print_tree(ft::node<int> *node, int flag)
// {
// 	if (!node)
// 		return ;
// 	if (flag == 1)
// 		std::cout << "- R -" << std::endl;
// 	else if (flag == 2)
// 		std::cout << "- L -" << std::endl;
// 	if (node->node_color == 0)
// 		std::cout << "BLACK  ";
// 	else
// 		std::cout << "RED  ";
// 	std::cout << node->key << std::endl;
// 	print_tree(node->l_child, 2);
// 	print_tree(node->r_child, 1);
// }

void	real_print(ft::RBT<ft::map<int, int>::key_type, ft::map<int, int>::mapped_type, ft::map<int, int>::value_type, ft::map<int, int>::key_compare, std::allocator<ft::pair<const int, int> > >::node<int> *ptr, int space, ft::RBT<ft::map<int, int>::key_type, ft::map<int, int>::mapped_type, ft::map<int, int>::value_type, ft::map<int, int>::key_compare, std::allocator<ft::pair<const int, int> >  > test)
{
	if (!ptr || ptr == test.getNull())
			return;
	space += 4;
	real_print(ptr->r_child, space, test);
	std::cout
			<< (ptr->node_color == black ? "\033[90m" : "\033[31m") << std::setw(space)
			<< ptr->_pair.second << "\033[0m" << std::endl;
	// getwchar();
	real_print(ptr->l_child, space, test);
}

int	main()
{
	ft::map<int, int, std::less<int>, std::allocator<ft::pair<const int, int> > > map;
	std::map<int, int> vrai;
	
	map._tree.insert(ft::make_pair(50, 50));
	map._tree.insert(ft::make_pair(8, 8));
	map._tree.insert(ft::make_pair(99, 99));
	map._tree.insert(ft::make_pair(1, 1));
	map._tree.insert(ft::make_pair(54, 54));
	map._tree.insert(ft::make_pair(7, 7));
	map._tree.insert(ft::make_pair(16, 16));
	map._tree.insert(ft::make_pair(43, 43));
	map._tree.insert(ft::make_pair(71, 71));
	map._tree.insert(ft::make_pair(83, 83));
	map._tree.insert(ft::make_pair(987, 987));
	map._tree.insert(ft::make_pair(12, 12));
	map._tree.insert(ft::make_pair(52, 52));
	map._tree.insert(ft::make_pair(988, 988));
	map._tree.insert(ft::make_pair(999, 999));
	map._tree.insert(ft::make_pair(53, 53));

	std::cout << "ssdgfgdfg " << map._tree.searchElem(map._tree.getRoot(), 988)<< std::endl;

	real_print(map._tree.getRoot(), 0, map._tree);

	
	vrai.insert(std::pair<int, int>(50, 50));
	vrai.insert(std::pair<int, int>(9, 9));
	vrai.insert(std::pair<int, int>(8, 8));
	vrai.insert(std::pair<int, int>(2, 666));
	vrai.insert(std::pair<int, int>(3, 3));
	vrai.insert(std::pair<int, int>(5, 5));
	std::cout << vrai.empty() << std::endl;
	
	std::map<int,int>::iterator it = vrai.begin();
	std::cout << it->first << std::endl;
}
