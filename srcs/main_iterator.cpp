/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:46:14 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/27 17:05:06 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Vector.hpp"
#include "vector_iterator.hpp"
#include "../includes/vector_iterator.tpp"
#include <cstdlib>

int	main(void)
{

	srand(time(NULL));
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

	std::cout << "---------- START ITERATOR TEST ----------" << std::endl;
	std::cout << std::endl;

	std::vector<int> titi(1, 1);
	ft::Vector<int> lulu(1, 1);
	for (size_t i = 0; i < 10; ++i)
	{
		int nb = (rand() % (1000 + 1));
		titi.push_back(nb);
		lulu.push_back(nb);
	}
	//std::vector<int>::iterator rit = titi.begin();
	ft::Vector<int>::iterator ftit = lulu.begin();
	for (size_t i = 0; i < titi.size(); ++i)
		std::cout << "REAL: " << titi[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lulu.size(); ++i)
		std::cout << "FT: " << lulu[i] << std::endl;
	std::cout << std::endl;
	std::cout << "begin(): " << std::endl;
	std::cout << "REAL: " << *titi.begin() << std::endl;
	std::cout << "FT: " << *lulu.begin() << std::endl;
	std::cout << std::endl;
	std::cout << "end(): " << std::endl;
	std::cout << "REAL: " << *titi.end() << std::endl;
	std::cout << "FT: " << *lulu.end() << std::endl;
	std::cout << std::endl;
	// std::cout << "rbegin(): " << std::endl;
	// std::cout << "REAL: " << *titi.rbegin() << std::endl;
	// std::cout << "FT: " << *lulu.rbegin() << std::endl;
	// std::cout << std::endl;
	// std::cout << "rend(): " << std::endl;
	// std::cout << "REAL: " << *(titi.rend() + 1) << std::endl;
	// std::cout << "FT: " << *(lulu.rend() + 1) << std::endl;
	// std::cout << std::endl;
	std::cout << "insert() 999 at 3 position: " << std::endl;
	titi.insert(titi.begin() + 2, 999);
	lulu.insert(lulu.begin() + 2, 999);
	std::cout << std::endl;
	for (size_t i = 0; i < titi.size(); ++i)
		std::cout << "REAL: " << titi[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lulu.size(); ++i)
		std::cout << "FT: " << lulu[i] << std::endl;
	std::cout << std::endl;
    std::cout << "insert() 999 2 to 8 positions: " << std::endl;
    titi.insert(titi.begin() + 2, 8, 999);
    lulu.insert(lulu.begin() + 2, 8, 999);
    std::cout << std::endl;
    for (size_t i = 0; i < titi.size(); ++i)
        std::cout << "REAL: " << titi[i] << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < lulu.size(); ++i)
        std::cout << "FT: " << lulu[i] << std::endl;
    std::cout << std::endl;
	std::cout << "erase() the second element: " << std::endl;
	titi.erase(titi.begin() + 1);
	lulu.erase(lulu.begin() + 1);
	std::cout << std::endl;
	for (size_t i = 0; i < titi.size(); ++i)
		std::cout << "REAL: " << titi[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lulu.size(); ++i)
		std::cout << "FT: " << lulu[i] << std::endl;
	std::cout << std::endl;
	std::cout << "erase() 2 to 8 elements: " << std::endl;
	titi.erase(titi.begin() + 1, titi.begin() + 8);
	lulu.erase(lulu.begin() + 1, lulu.begin() + 8);
	std::cout << std::endl;
	for (size_t i = 0; i < titi.size(); ++i)
		std::cout << "REAL: " << titi[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lulu.size(); ++i)
		std::cout << "FT: " << lulu[i] << std::endl;
	std::cout << std::endl;
}
