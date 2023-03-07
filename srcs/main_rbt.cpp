/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rbt.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:34:29 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/07 19:16:00 by ldinaut          ###   ########.fr       */
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
	

	// map._tree.insert(ft::make_pair(1, 8));
	// map._tree.insert(ft::make_pair(2, 9));
	// map._tree.insert(ft::make_pair(3, 10));

	//real_print(map._tree.getRoot(), 0, map._tree);
	std::cout << "----------------------------\n";
	map.insert(ft::make_pair(50, 50));
	//real_print(map._tree.getRoot(), 0, map._tree);
	std::cout << "----------------------------\n";
	map.insert(ft::make_pair(8, 8));
	//real_print(map._tree.getRoot(), 0, map._tree);
	std::cout << "----------------------------\n";
	map.insert(ft::make_pair(99, 99));
	//real_print(map._tree.getRoot(), 0, map._tree);
	std::cout << "----------------------------\n";
	map.insert(ft::make_pair(1, 1));
	map.insert(ft::make_pair(54, 54));
	map.insert(ft::make_pair(7, 7));
	map.insert(ft::make_pair(16, 16));
	map.insert(ft::make_pair(43, 43));
	map.insert(ft::make_pair(71, 71));
	map.insert(ft::make_pair(83, 83));
	map.insert(ft::make_pair(0, 0));
	map.insert(ft::make_pair(987, 987));
	map.insert(ft::make_pair(12, 12));
	map.insert(ft::make_pair(52, 52));
	map.insert(ft::make_pair(988, 988));
	map.insert(ft::make_pair(999, 999));
	map.insert(ft::make_pair(53, 53));

	// real_print(map._tree.getRoot(), 0, map._tree);
	// map._tree.rb_delete(71);
	real_print(map._tree.getRoot(), 0, map._tree);
	// std::cout << "ssdgfgdfg " << map.count(53) << std::endl;

	vrai.insert(std::pair<int, int>(50, 50));
	vrai.insert(std::pair<int, int>(8, 8));
	//vrai.insert(std::pair<int, int>(99, 99));
	//vrai.insert(std::pair<int, int>(1, 1));
	//vrai.insert(std::pair<int, int>(54, 54));
	//vrai.insert(std::pair<int, int>(7, 7));
	//std::cout << vrai.empty() << std::endl;
	
	std::map<int,int>::iterator it = vrai.begin();
	std::cout << "vrai begin = " << it->first << std::endl;
	std::cout << "vrai begin + 1 = " << (++it)->first << std::endl;
	std::map<int,int>::iterator ite = vrai.end();
	std::cout << "vrai end - 1 = " << (--ite)->first << std::endl;
	//std::cout << "vrai end - 2 = " << (--ite)->first << std::endl;
	
	//std::cout << (it++)->first << 

	ft::map<int, int>::iterator mit = map.begin();
	ft::map<int, int>::iterator mend = map.end();
	std::cout << "mine begin " << mit->first << std::endl;
	// --mend;
	// std::cout << "moinsmoinsend = " << mend->first << std::endl;
	while (mit != mend)
	{
		std::cout << "map = " << mit->first << std::endl;
		mit++;
	}
	//map.erase(54);
	//real_print(map._tree.getRoot(), 0, map._tree);

	

}
