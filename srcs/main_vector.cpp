/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:49:08 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/23 18:05:42 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include "../includes/Vector.hpp"

int	main()
{

	ft::Vector<int> fill(3, 50);
	std::vector<int> vfill(3, 50);

	for (unsigned int i = 0; i < fill.size(); ++i)
	{
		std::cout << "mine vec[i] = " << fill[i] << std::endl;
	}
	try
	{
		std::cout << fill.at(2) << std::endl;
		std::cout << fill.at(3) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	for (unsigned int i = 0; i < vfill.size(); ++i)
	{
		std::cout << "vrai vec[i] = " << vfill[i] << std::endl;
	}
	try
	{
		std::cout << vfill.at(2) << std::endl;
		std::cout << vfill.at(3) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	ft::Vector<int> copy(fill);
	std::vector<int> vcopy(vfill);
	for (unsigned int i = 0; i < copy.size(); ++i)
	{
		std::cout << "copy[i] = " << copy[i] << std::endl;
	}
	std::cout << std::endl << std::endl;
	copy.push_back(8);
	copy.push_back(8);
	copy.push_back(8);
	copy.push_back(8);
	std::cout << "copy size = " << copy.size() << " capacity = " << copy.capacity() << std::endl;
	// copy.clear();
	// std::cout << "after size = " << copy.size() << " capacity = " << copy.capacity() << std::endl;

	std::cout << std::endl << std::endl;

	vcopy.push_back(8);
	vcopy.push_back(8);
	vcopy.push_back(8);
	vcopy.push_back(8);
	std::cout << "vcopy size = " << vcopy.size() << " capacity = " << vcopy.capacity() << std::endl;
	// vcopy.clear();
	// std::cout << "after size = " << vcopy.size() << " capacity = " << vcopy.capacity() << std::endl;

	ft::Vector<int> empty;
	std::vector<int> vempty;

	std::cout << "mon empty ? " << empty.empty() << std::endl;
	std::cout << "vrai empty ? " << vempty.empty() << std::endl;

	std::cout << empty.max_size() << std::endl;
	std::cout << vempty.max_size() << std::endl;

	copy.pop_back();
	vcopy.pop_back();
	std::cout << "copy size = " << copy.size() << " capacity = " << copy.capacity() << std::endl;
	std::cout << "vcopy size = " << vcopy.size() << " capacity = " << vcopy.capacity() << std::endl;
	std::cout << std::endl << std::endl;

	copy.reserve(55);
	vcopy.reserve(55);
	std::cout << "copy size = " << copy.size() << " capacity = " << copy.capacity() << std::endl;
	std::cout << "vcopy size = " << vcopy.size() << " capacity = " << vcopy.capacity() << std::endl;
	std::cout << std::endl << std::endl;

	copy.resize(5);
	vcopy.resize(5);
	std::cout << "after resize" << std::endl;
	std::cout << "copy size = " << copy.size() << " capacity = " << copy.capacity() << std::endl;
	std::cout << "vcopy size = " << vcopy.size() << " capacity = " << vcopy.capacity() << std::endl;
	std::cout << std::endl << std::endl;

	copy.resize(7, 666);
	vcopy.resize(7, 666);
	std::cout << "after resize" << std::endl;
	std::cout << "copy size = " << copy.size() << " capacity = " << copy.capacity() << std::endl;
	std::cout << "vcopy size = " << vcopy.size() << " capacity = " << vcopy.capacity() << std::endl;
	std::cout << std::endl << std::endl;

	copy.resize(57);
	vcopy.resize(57);
	std::cout << "after resize" << std::endl;
	std::cout << "copy size = " << copy.size() << " capacity = " << copy.capacity() << std::endl;
	std::cout << "vcopy size = " << vcopy.size() << " capacity = " << vcopy.capacity() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "tests de swap" << std::endl;

	ft::Vector<int> foo(3,100);   // three ints with a value of 100
	ft::Vector<int> bar(5,200);   // five ints with a value of 200
	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
	std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
	std::cout << ' ' << bar[i];
	std::cout << '\n';
	std::cout << std::endl << std::endl;

	std::vector<int>::iterator lol;
	std::cout << &(*lol) << std::endl;

	ft::Vector<int>::iterator lol2;
	std::cout << &(*lol2) << std::endl;

	ft::Vector<int>::iterator lol3;
	
}
