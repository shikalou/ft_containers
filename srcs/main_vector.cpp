/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:49:08 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/30 15:16:01 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <string>
#include <deque>
#include <vector>
#include "../includes/Vector.hpp"

// int	main()
// {

// 	ft::Vector<int> fill(3, 50);
// 	std::vector<int> vfill(3, 50);

// 	for (unsigned int i = 0; i < fill.size(); ++i)
// 	{
// 		std::cout << "mine vec[i] = " << fill[i] << std::endl;
// 	}
// 	try
// 	{
// 		std::cout << fill.at(2) << std::endl;
// 		std::cout << fill.at(3) << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	for (unsigned int i = 0; i < vfill.size(); ++i)
// 	{
// 		std::cout << "vrai vec[i] = " << vfill[i] << std::endl;
// 	}
// 	try
// 	{
// 		std::cout << vfill.at(2) << std::endl;
// 		std::cout << vfill.at(3) << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	std::cout << std::endl << std::endl;

// 	ft::Vector<int> copy(fill);
// 	std::vector<int> vcopy(vfill);
// 	for (unsigned int i = 0; i < copy.size(); ++i)
// 	{
// 		std::cout << "copy[i] = " << copy[i] << std::endl;
// 	}
// 	std::cout << std::endl << std::endl;
// 	copy.push_back(8);
// 	copy.push_back(8);
// 	copy.push_back(8);
// 	copy.push_back(8);
// 	std::cout << "copy size = " << copy.size() << " capacity = " << copy.capacity() << std::endl;
// 	// copy.clear();
// 	// std::cout << "after size = " << copy.size() << " capacity = " << copy.capacity() << std::endl;

// 	std::cout << std::endl << std::endl;

// 	vcopy.push_back(8);
// 	vcopy.push_back(8);
// 	vcopy.push_back(8);
// 	vcopy.push_back(8);
// 	std::cout << "vcopy size = " << vcopy.size() << " capacity = " << vcopy.capacity() << std::endl;
// 	// vcopy.clear();
// 	// std::cout << "after size = " << vcopy.size() << " capacity = " << vcopy.capacity() << std::endl;

// 	ft::Vector<int> empty;
// 	std::vector<int> vempty;

// 	std::cout << "mon empty ? " << empty.empty() << std::endl;
// 	std::cout << "vrai empty ? " << vempty.empty() << std::endl;

// 	std::cout << empty.max_size() << std::endl;
// 	std::cout << vempty.max_size() << std::endl;

// 	copy.pop_back();
// 	vcopy.pop_back();
// 	std::cout << "copy size = " << copy.size() << " capacity = " << copy.capacity() << std::endl;
// 	std::cout << "vcopy size = " << vcopy.size() << " capacity = " << vcopy.capacity() << std::endl;
// 	std::cout << std::endl << std::endl;

// 	copy.reserve(55);
// 	vcopy.reserve(55);
// 	std::cout << "copy size = " << copy.size() << " capacity = " << copy.capacity() << std::endl;
// 	std::cout << "vcopy size = " << vcopy.size() << " capacity = " << vcopy.capacity() << std::endl;
// 	std::cout << std::endl << std::endl;

// 	copy.resize(5);
// 	vcopy.resize(5);
// 	std::cout << "after resize" << std::endl;
// 	std::cout << "copy size = " << copy.size() << " capacity = " << copy.capacity() << std::endl;
// 	std::cout << "vcopy size = " << vcopy.size() << " capacity = " << vcopy.capacity() << std::endl;
// 	std::cout << std::endl << std::endl;

// 	copy.resize(7, 666);
// 	vcopy.resize(7, 666);
// 	std::cout << "after resize" << std::endl;
// 	std::cout << "copy size = " << copy.size() << " capacity = " << copy.capacity() << std::endl;
// 	std::cout << "vcopy size = " << vcopy.size() << " capacity = " << vcopy.capacity() << std::endl;
// 	std::cout << std::endl << std::endl;

// 	copy.resize(57);
// 	vcopy.resize(57);
// 	std::cout << "after resize" << std::endl;
// 	std::cout << "copy size = " << copy.size() << " capacity = " << copy.capacity() << std::endl;
// 	std::cout << "vcopy size = " << vcopy.size() << " capacity = " << vcopy.capacity() << std::endl;
// 	std::cout << std::endl << std::endl;

// 	std::cout << "tests de swap" << std::endl;

// 	ft::Vector<int> foo(3,100);   // three ints with a value of 100
// 	ft::Vector<int> bar(5,200);   // five ints with a value of 200
// 	foo.swap(bar);

// 	std::cout << "foo contains:";
// 	for (unsigned i=0; i<foo.size(); i++)
// 	std::cout << ' ' << foo[i];
// 	std::cout << '\n';

// 	std::cout << "bar contains:";
// 	for (unsigned i=0; i<bar.size(); i++)
// 	std::cout << ' ' << bar[i];
// 	std::cout << '\n';
// 	std::cout << std::endl << std::endl;
// 	std::cout << std::endl << std::endl;

// 	std::vector<int> test;

// 	std::cout << "test size = " << test.size() << " capacity = " << test.capacity() << std::endl;
// 	test.push_back(3);
// 	test.push_back(3);
// 	test.push_back(3);
// 	test.push_back(3);
// 	test.push_back(3);
// 	test.push_back(3);
// 	test.push_back(3);
// 	test.push_back(3);
// 	test.push_back(3);
// 	test.push_back(3);
// 	std::cout << "test size = " << test.size() << " capacity = " << test.capacity() << std::endl;
// 	for (unsigned int i = 0; i < test.size(); ++i)
// 	{
// 		std::cout << "test[i] = " << test[i] << std::endl;
// 	}
// 	ft::Vector<int> test2;

// 	std::cout << "test2 size = " << test2.size() << " capacity = " << test2.capacity() << std::endl;
// 	test2.push_back(3);
// 	test2.push_back(3);
// 	test2.push_back(3);
// 	test2.push_back(3);
// 	test2.push_back(3);
// 	test2.push_back(3);
// 	test2.push_back(3);
// 	test2.push_back(3);
// 	test2.push_back(3);
// 	test2.push_back(3);
// 	std::cout << "test2 size = " << test2.size() << " capacity = " << test2.capacity() << std::endl;
// 	for (unsigned int i = 0; i < test2.size(); ++i)
// 	{
// 		std::cout << "test2[i] = " << test2[i] << std::endl;
// 	}
// }
int	main(void)
{
	srand(time(NULL));
	ft::Vector<int>	ft(3, 1);
	ft::Vector<int>	ft2(3);
	// ft::Vector<int>::iterator p = ft.begin();
	// ft::Vector<int>::iterator o = ft.end();
	// ft::Vector<int> ft3(p, o);
	std::vector<int> real(3, 1);

	std::cout << "---------- START push_back test ----------" << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "actual capacity for real: " << real.capacity() << std::endl;
	std::cout << "actual size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "actual capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "actual size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ADD number 2: " << std::endl;
	real.push_back(2);
	ft.push_back(2);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "new capacity for real: " << real.capacity() << std::endl;
	std::cout << "new size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << "---------- END push_back test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START pop_back test ----------" << std::endl;
	
	std::cout << "remove two last elements: " << std::endl;
	real.pop_back();
	ft.pop_back();
	real.pop_back();
	ft.pop_back();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "new capacity for real: " << real.capacity() << std::endl;
	std::cout << "new size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << "---------- END pop_back test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START clear test ----------" << std::endl;

	std::cout << "cleaning all elements: " << std::endl;
	real.clear();
	ft.clear();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "new capacity for real: " << real.capacity() << std::endl;
	std::cout << "new size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << "---------- END clear test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START push_back test 2 ----------" << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "actual capacity for real: " << real.capacity() << std::endl;
	std::cout << "actual size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "actual capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "actual size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ADD multiple numbers: " << std::endl;
	for (size_t i = 0; i < 10; ++i)
	{
		int nb = (rand() % (1000 + 1));
		real.push_back(nb);
		ft.push_back(nb);
	}
	real.push_back(999);
	ft.push_back(999);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "new capacity for real: " << real.capacity() << std::endl;
	std::cout << "new size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << "---------- END push_back test 2 ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START resize test ----------" << std::endl;
	std::cout << std::endl;
	real.resize(3);
	ft.resize(3);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "new capacity for real: " << real.capacity() << std::endl;
	std::cout << "new size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << "---------- END resize test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START resize test 2 ----------" << std::endl;
	std::cout << std::endl;
	real.resize(20);
	ft.resize(20);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "REAL stats: " << std::endl;
	std::cout << "new capacity for real: " << real.capacity() << std::endl;
	std::cout << "new size for real: " << real.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FT stats: " << std::endl;
	std::cout << "new capacity for ft: " << ft.capacity() << std::endl;
	std::cout << "new size for ft: " << ft.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << "---------- END resize test 2 ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START max_size test ----------" << std::endl;
	std::cout << std::endl;
	std::cout << "REAL max_size: " << real.max_size() << std::endl;
	std::cout << "FT max_size: " << ft.max_size() << std::endl;
	std::cout << std::endl;
	std::cout << "---------- END max_size test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START swap && at test ----------" << std::endl;
	std::cout << std::endl;
	
	real.clear();
	ft.clear();
	ft::Vector<int> tmp;
	for (size_t i = 0; i < 5; ++i)
	{
		tmp.push_back(1);
		ft.push_back(2);
	}
	for (size_t i = 0; i < tmp.size(); ++i)
		std::cout << "REAL: " << tmp.at(i) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft.at(i) << std::endl;
	std::cout << std::endl;
	std::cout << "SWAPPING !!!" << std::endl;
	ft.swap(tmp);
	std::cout << std::endl;
	for (size_t i = 0; i < tmp.size(); ++i)
		std::cout << "REAL: " << tmp.at(i) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft.at(i) << std::endl;
	std::cout << std::endl;
	try
	{
		std::cout << "Try to access index 999: " << ft.at(999) << std::endl;
	}
	catch(std::out_of_range e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------- END swap && at test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "---------- START front && back test ----------" << std::endl;
	std::cout << std::endl;

	ft.clear();
	for (size_t i = 0; i < 5; ++i)
	{
		int nb = (rand() % (1000 + 1));
		real.push_back(nb);
		ft.push_back(nb);
	}
	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << std::endl;
	std::cout << "REAL FRONT: " << real.front() << std::endl;
	std::cout << std::endl;
	std::cout << "FT FRONT: " << real.front() << std::endl;
	std::cout << std::endl;
	std::cout << "REAL BACK: " << real.back() << std::endl;
	std::cout << std::endl;
	std::cout << "FT BACK: " << real.back() << std::endl;

	std::cout << std::endl;
	std::cout << "---------- END front && back test ----------" << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "---------- START empty test ----------" << std::endl;
	std::cout << std::endl;

	for (size_t i = 0; i < real.size(); ++i)
		std::cout << "REAL: " << real[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < ft.size(); ++i)
		std::cout << "FT: " << ft[i] << std::endl;
	std::cout << std::endl;
	std::cout << "REAL empty: " << real.empty() << std::endl;
	std::cout << std::endl;
	std::cout << "FT empty: " << real.empty() << std::endl;
	std::cout << std::endl;
	std::cout << "CLEANING: " << std::endl;
	real.clear();
	ft.clear();
	std::cout << std::endl;
	std::cout << "REAL empty: " << real.empty() << std::endl;
	std::cout << std::endl;
	std::cout << "FT empty: " << real.empty() << std::endl;
	
	std::cout << std::endl;
	std::cout << "---------- END empty test ----------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------- START ITERATOR TEST ----------" << std::endl;
	std::cout << std::endl;

	std::vector<int> toto(1, 1);
	ft::Vector<int> lala(1, 1);
	for (size_t i = 0; i < 10; ++i)
	{
		int nb = (rand() % (1000 + 1));
		toto.push_back(nb);
		lala.push_back(nb);
	}
	//std::vector<int>::iterator rit = toto.begin();
	//ft::Vector<int>::iterator ftit = lala.begin();
	for (size_t i = 0; i < toto.size(); ++i)
		std::cout << "REAL: " << toto[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "begin(): " << std::endl;
	std::cout << "REAL: " << *toto.begin() << std::endl;
	std::cout << "FT: " << *lala.begin() << std::endl;
	std::cout << std::endl;
	std::cout << "end(): " << std::endl;
	std::cout << "REAL: " << *toto.end() << std::endl;
	std::cout << "FT: " << *lala.end() << std::endl;
	std::cout << std::endl;
	// std::cout << "rbegin(): " << std::endl;
	// std::cout << "REAL: " << *toto.rbegin() << std::endl;
	// std::cout << "FT: " << *lala.rbegin() << std::endl;
	// std::cout << std::endl;
	// std::cout << "rend(): " << std::endl;
	// std::cout << "REAL: " << *(toto.rend() + 1) << std::endl;
	// std::cout << "FT: " << *(lala.rend() + 1) << std::endl;
	// std::cout << std::endl;
	std::cout << "insert() 999 at 3 position: " << std::endl;
	toto.insert(toto.begin() + 2, 999);
	lala.insert(lala.begin() + 2, 999);
	std::cout << std::endl;
	for (size_t i = 0; i < toto.size(); ++i)
		std::cout << "REAL: " << toto[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "erase() the second element: " << std::endl;
	toto.erase(toto.begin() + 1);
	lala.erase(lala.begin() + 1);
	std::cout << std::endl;
	for (size_t i = 0; i < toto.size(); ++i)
		std::cout << "REAL: " << toto[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "erase() 2 to 8 elements: " << std::endl;
	toto.erase(toto.begin() + 1, toto.begin() + 8);
	lala.erase(lala.begin() + 1, lala.begin() + 8);
	std::cout << std::endl;
	for (size_t i = 0; i < toto.size(); ++i)
		std::cout << "REAL: " << toto[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "insert() 999 2 to 8 positions: " << std::endl;
	toto.insert(toto.begin() + 2, 8, 999);
	lala.insert(lala.begin() + 2, 8, 999);
	std::cout << std::endl;
	for (size_t i = 0; i < toto.size(); ++i)
		std::cout << "REAL: " << toto[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	std::cout << "assign() 1111 for 5 elements: " << std::endl;
	toto.assign(5, 1111);
	lala.assign(5, 1111);
	std::cout << std::endl;
	for (size_t i = 0; i < toto.size(); ++i)
		std::cout << "REAL: " << toto[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < lala.size(); ++i)
		std::cout << "FT: " << lala[i] << std::endl;
	std::cout << std::endl;
	// std::vector<int>::iterator b = toto.begin();
	// std::vector<int>::iterator e = toto.end();
	// std::vector<int> test(b, e);
	// ft::Vector<int>::iterator b1 = lala.begin();
	// ft::Vector<int>::iterator e1 = lala.end();
	// ft::Vector<int> test1(b1, e1);
	// std::cout << std::endl;
	// for (size_t i = 0; i < test.size(); ++i)
	// 	std::cout << "REAL: " << test[i] << std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;
	// for (size_t i = 0; i < test1.size(); ++i)
	// 	std::cout << "FT: " << test1[i] << std::endl;
	// std::cout << std::endl;

	// *b = *b - 1;
	// test.assign(b, e);
	// *b1 = *b1 - 1;
	// test1.assign(b1, e1);
	// std::cout << std::endl;
	// for (size_t i = 0; i < test.size(); ++i)
	// 	std::cout << "REAL: " << test[i] << std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;
	// for (size_t i = 0; i < test1.size(); ++i)
	// 	std::cout << "FT: " << test1[i] << std::endl;
	// std::cout << std::endl;
	// test.insert(test.begin(), b, e);
	// test1.insert(test1.begin(), b1, e1);
	// std::cout << std::endl;
	// for (size_t i = 0; i < test.size(); ++i)
	// 	std::cout << "REAL: " << test[i] << std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;
	// for (size_t i = 0; i < test1.size(); ++i)
	// 	std::cout << "FT: " << test1[i] << std::endl;
	// std::cout << std::endl;
}
