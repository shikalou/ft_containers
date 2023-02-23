/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rbt.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:34:29 by ldinaut           #+#    #+#             */
/*   Updated: 2023/02/23 19:33:45 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rbt.hpp"
#include "../includes/map.hpp"
#include "../includes/make_pair.hpp"
#include <iomanip>

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

	// ft::RBT<int, int> toto;

	// toto.insert(50);
	// toto.insert(8);
	// toto.insert(99);
	// toto.insert(1);
	// toto.insert(54);
	// toto.insert(7);
	// toto.insert(16);
	// toto.insert(43);
	// toto.insert(71);
	// toto.insert(83);
	// toto.insert(987);
	// toto.insert(12);
	// toto.insert(52);

	real_print(map._tree.getRoot(), 0, map._tree);

	// toto.rb_delete(12);
	// real_print(toto.getRoot(), 0, toto);
	
	// toto.rb_delete(99);
	// real_print(toto.getRoot(), 0, toto);

	// toto.rb_delete(7);
	// real_print(toto.getRoot(), 0, toto);
}
