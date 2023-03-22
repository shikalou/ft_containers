/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_empty.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:36:58 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/17 22:17:47 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers_test/srcs/base.hpp"
#include <list>
#include "../includes/map.hpp"

void	real_print(ft::RBT<ft::map<int, std::string>::key_type, ft::map<int, std::string>::mapped_type, ft::map<int, std::string>::value_type, ft::map<int, std::string>::key_compare, std::allocator<ft::pair<const int, std::string> > >::node<int> *ptr, int space, ft::RBT<ft::map<int, std::string>::key_type, ft::map<int, std::string>::mapped_type, ft::map<int, std::string>::value_type, ft::map<int, std::string>::key_compare, std::allocator<ft::pair<const int, std::string> >  > test)
{
	if (!ptr || ptr == test.getNull())
			return;
	space += 4;
	real_print(ptr->r_child, space, test);
	std::cout
			<< (ptr->node_color == black ? "\033[90m" : "\033[31m") << std::setw(space)
			<< ptr->_pair->first << "\033[0m" << std::endl;
	// getwchar();
	real_print(ptr->l_child, space, test);
}
#define _pair TESTED_NAMESPACE::pair


template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

#define T1 int
#define T2 std::string

struct ft_more {
	bool	operator()(const T1 &first, const T1 &second) const {
		return (first > second);
	}
};

typedef TESTED_NAMESPACE::map<T1, T2, ft_more> ft_mp;
typedef TESTED_NAMESPACE::map<T1, T2, ft_more>::iterator ft_mp_it;

int		main(void)
{
	ft_mp mp;

	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	printSize(mp);

	return (0);
}
