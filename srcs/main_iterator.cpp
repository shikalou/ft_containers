/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:46:14 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/24 16:30:51 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Vector.hpp"
#include "vector_iterator.hpp"

int	main(void)
{
	std::vector<int> toto(1, 1);
	toto.push_back(5);
	toto.push_back(6);
	toto.push_back(7);
	ft::Vector<int> lala(1, 1);
	lala.push_back(5);
	lala.push_back(6);
	lala.push_back(7);
	std::vector<int>::iterator it2 = toto.begin();
	ft::Vector<int>::iterator it4 = lala.begin();
	std::vector<int>::iterator rev(it2);
	ft::Vector<int>::iterator it(it4);

	std::cout << "----- START * | [] | base test -----" << std::endl;
	std::cout << std::endl;
	std::cout << "*: " << std::endl;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	// std::cout << "base: " << std::endl;
	// std::cout << "REAL: " << *rev.base() << std::endl;
	// std::cout << "FT: " << *it.base() << std::endl;
	// std::cout << std::endl;
	std::cout << "[]: " << std::endl;
	std::cout << "REAL: " << rev[1] << std::endl;
	std::cout << "FT: " << it[1] << std::endl;
	std::cout << std::endl;
	std::cout << "----- END * | [] | base test -----" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "----- START arithmetics operator test -----" << std::endl;
	std::cout << std::endl;
	std::cout << "--x: " << std::endl;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << "DECREMENTATION" << std::endl;
	--rev;
	--it;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "x--: " << std::endl;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << "DECREMENTATION" << std::endl;
	rev--;
	it--;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "++x: " << std::endl;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << "INCREMENTATION" << std::endl;
	++rev;
	++it;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "x++: " << std::endl;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << "INCREMENTATION" << std::endl;
	rev++;
	it++;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "-=: " << std::endl;
	rev -= 1;
	it -= 1;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	int i = 0;
	while (lala[i])
	{
		std::cout << lala[i] << std::endl;
		i++;
	}
	std::cout << std::endl;
	i = 0;
	while (toto[i])
	{
		std::cout << toto[i] << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << "+=: " << std::endl;
	rev += 1;
	it += 1;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "-: " << std::endl;
	rev - 1;
	it - 1;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "+: " << std::endl;
	rev + 2;
	it + 2;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << std::endl;
	std::cout << "----- END arithmetics operators -----" << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "----- START comparaison operators -----" << std::endl;	
	std::cout << std::endl;
	ft::Vector<int>::iterator it3(it);
	std::vector<int>::iterator rev2(rev);

	std::cout << "lhs == rhs (lhs = rhs): " << std::endl;
	bool recup = rev == rev2;
	bool recup2 = it == it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;
	it++;
	rev++;
	std::cout << "lhs == rhs (lhs != rhs): " << std::endl;
	recup = rev == rev2;
	recup2 = it == it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;

	std::cout << std::endl;
	std::cout << "lhs != rhs (lhs = rhs): " << std::endl;
	recup = rev != rev2;
	recup2 = it != it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;
	it--;
	rev--;
	std::cout << "lhs != rhs (lhs != rhs): " << std::endl;
	recup = rev != rev2;
	recup2 = it != it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;

	std::cout << std::endl;
	std::cout << "lhs <= rhs (lhs <= rhs): " << std::endl;
	recup = rev <= rev2;
	recup2 = it <= it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;
	std::cout << "lhs >= rhs (lhs >= rhs): " << std::endl;
	recup = rev >= rev2;
	recup2 = it >= it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;

	std::cout << std::endl;
	std::cout << "lhs < rhs (lhs < rhs): " << std::endl;
	recup = rev < rev2;
	recup2 = it < it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;
	std::cout << "lhs > rhs (lhs > rhs): " << std::endl;
	recup = rev > rev2;
	recup2 = it > it3;
	std::cout << "REAL: " << recup << std::endl;
	std::cout << "FT: " << recup2 << std::endl;

	std::cout << std::endl;
	std::cout << "----- END comparaison operators -----" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "----- START template -/+ -----" << std::endl;
	std::cout << std::endl;
	*it++;
	*rev++;
	std::cout << "n - rhs: " << std::endl;
	rev = rev - 5;
	it = it - 5;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;
	std::cout << "n + rhs: " << std::endl;
	rev = 2 + rev;
	it = 2 + it;
	std::cout << "REAL: " << *rev << std::endl;
	std::cout << "FT: " << *it << std::endl;

	std::cout << std::endl;
	std::cout << "----- END template -/+ -----" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}
