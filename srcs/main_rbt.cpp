/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rbt.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:34:29 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/09 20:32:31 by ldinaut          ###   ########.fr       */
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
			<< ptr->_pair.first << "\033[0m" << std::endl;
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

	vrai.insert(std::make_pair(50, 50));
	vrai.insert(std::make_pair(8, 8));
	vrai.insert(std::make_pair(99, 99));
	vrai.insert(std::make_pair(1, 1));
	vrai.insert(std::make_pair(54, 54));
	vrai.insert(std::make_pair(7, 7));
	vrai.insert(std::make_pair(16, 16));
	vrai.insert(std::make_pair(43, 43));
	vrai.insert(std::make_pair(71, 71));
	vrai.insert(std::make_pair(83, 83));
	vrai.insert(std::make_pair(0, 0));
	vrai.insert(std::make_pair(987, 987));
	vrai.insert(std::make_pair(12, 12));
	vrai.insert(std::make_pair(52, 52));
	vrai.insert(std::make_pair(988, 988));
	vrai.insert(std::make_pair(999, 999));
	vrai.insert(std::make_pair(53, 53));
	
	std::map<int,int>::iterator it = vrai.begin();
	std::cout << "vrai begin = " << it->first << std::endl;
	std::cout << "vrai begin + 1 = " << (++it)->first << std::endl;
	std::map<int,int>::iterator ite = vrai.end();
	std::cout << "vrai end - 1 = " << (--ite)->first << std::endl;
	//std::cout << "vrai end - 2 = " << (--ite)->first << std::endl;
	
	//std::cout << (it++)->first << 
	std::map<int, int>::iterator vit = vrai.begin();
	std::map<int, int>::iterator vend = vrai.end();
	while (vit != vend)
	{
		std::cout << "vrai[" << vit->first << "] = " << vit->second << std::endl;
		vit++;
	}


	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";

	ft::map<int, int>::iterator mit = map.begin();
	ft::map<int, int>::iterator mend = map.end();
	std::cout << "mine begin " << mit->first << std::endl;
	// --mend;
	// std::cout << "moinsmoinsend = " << mend->first << std::endl;
	while (mit != mend)
	{
		std::cout << "map[" << mit->first << "] = " << mit->second << std::endl;
		mit++;
	}

	std::cout << "vrai lowerbound  =  " << vrai.lower_bound(43)->first << std::endl;
	std::cout << "vrai upperbound  =  " << vrai.upper_bound(43)->first << std::endl;
	std::cout << "mine lowerbound  =  " << map.lower_bound(43)->first << std::endl;
	std::cout << "mine upperbound  =  " << map.upper_bound(43)->first << std::endl;
	std::cout << "\n\n\n\n\n";
	std::cout << "vrai equalrange  = first " << vrai.equal_range(71).first->first << std::endl;
	std::cout << "vrai equalrange = second " << vrai.equal_range(71).second->first << std::endl;
	std::cout << "mine equalrange  = first " << map.equal_range(71).first->first << std::endl;
	std::cout << "mine equalrange = second " << map.equal_range(71).second->first << std::endl;
	// map[18] = 118;
	// mit = map.begin();
	// mend = map.end();
	// while (mit != mend)
	// {
	// 	std::cout << "map[" << mit->first << "] = " << mit->second << std::endl;
	// 	mit++;
	// }

	//map.erase(54);
	//real_print(map._tree.getRoot(), 0, map._tree);

	ft::map<int, int, std::less<int>, std::allocator<ft::pair<const int, int> > > toto;

	toto.insert(ft::make_pair(5, 1));
	toto.insert(ft::make_pair(1, 54));
	toto.insert(ft::make_pair(7, 7));
	toto.insert(ft::make_pair(3, 16));
	toto.insert(ft::make_pair(4, 43));
	toto.insert(ft::make_pair(54, 71));
	toto.insert(ft::make_pair(6, 83));
	toto.insert(ft::make_pair(7, 0));
	toto.insert(ft::make_pair(8, 987));
	toto.insert(ft::make_pair(9, 12));
	real_print(toto._tree.getRoot(), 0, toto._tree);
	toto.insert(ft::make_pair(16, 52));
	toto.insert(ft::make_pair(26, 988));
	toto.insert(ft::make_pair(36, 999));
	toto.insert(ft::make_pair(46, 53));
	toto.insert(ft::make_pair(243, 53));
	//toto[243] = 24;
	toto.erase(26);
	real_print(toto._tree.getRoot(), 0, toto._tree);

}
