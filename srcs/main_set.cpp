/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:59:33 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/22 17:19:11 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <iostream>
#include "../includes/set.hpp"

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

int	main()
{
	std::cout << "\t\t----- SET TEST START -----\n" << std::endl;
	NAMESPACE::set<int> toto;
	std::cout << "is set empty ?" << std::endl;
	toto.empty() ? std::cout << "yes\n" : std::cout << "no\n";

	std::cout << "\t-- insert 10 values in set --\n" << std::endl;
	for (int i = 10; i > 0; --i)
	{
		toto.insert(i);
	}
	std::cout << std::endl;

	std::cout << "is set empty ?" << std::endl;
	toto.empty() ? std::cout << "still yes\n" : std::cout << "not anymore!!!!!!!!!!!\n";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "\t-- test set iterator --\n" << std::endl;
	NAMESPACE::set<int>::iterator it = toto.begin();
	NAMESPACE::set<int>::iterator ite = toto.end();

	std::cout << "begin = " << *it << std::endl;
	ite--;
	std::cout << "end-- = " << *ite << std::endl;
	ite = toto.end();
	std::cout << std::endl;
	std::cout << "size = " << toto.size() << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\t-- test equal_range and lower/upperbound --\n" << std::endl;
	std::cout << "\n";
	std::cout << "toto equal_range (first): " << *toto.equal_range(7).first << "\n";
	std::cout << "toto equal_range (second): " << *toto.equal_range(7).second << "\n";
	std::cout << "toto lowerbound: " << *toto.lower_bound(7) << "\n";
	std::cout << "toto upperbound: " << *toto.upper_bound(7) << "\n";
	std::cout << "\n";
	std::cout << "-- another test --" << std::endl;
	std::cout << "toto equal_range (first): " << *toto.equal_range(4).first << "\n";
	std::cout << "toto equal_range (second): " << *toto.equal_range(4).second << "\n";
	std::cout << "toto lowerbound: " << *toto.lower_bound(4) << "\n";
	std::cout << "toto upperbound: " << *toto.upper_bound(4) << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\t-- insert more values in set --\n" << std::endl;
	toto.insert(26);
	toto.insert(16);
	toto.insert(46);
	toto.insert(36);
	toto.insert(243);
	it = toto.begin();
	ite = toto.end();
	std::cout << "begin = " << *it << std::endl;
	ite--;
	std::cout << "end-- = " << *ite << std::endl;
	ite = toto.end();
	std::cout << std::endl;
	std::cout << "size = " << toto.size() << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\t-- test erase 7 and 36 --\n" << std::endl;
	toto.erase(7);
	toto.erase(36);
	it = toto.begin();
	ite = toto.end();
	std::cout << "begin = " << *it << std::endl;
	ite--;
	std::cout << "end-- = " << *ite << std::endl;
	ite = toto.end();
	std::cout << std::endl;
	std::cout << "size = " << toto.size() << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "\t-- test copy constructor --\n" << std::endl;
	NAMESPACE::set<int> cpy;
	cpy = toto;
	NAMESPACE::set<int>::iterator cit = cpy.begin();
	NAMESPACE::set<int>::iterator cite = cpy.end();

	std::cout << "begin = " << *cit << std::endl;
	cite--;
	std::cout << "end-- = " << *cite << std::endl;
	cite = cpy.end();
	std::cout << std::endl;
	std::cout << "size = " << cpy.size() << std::endl;
	while (cit != cite)
	{
		std::cout << "cpy = " << *cit << std::endl;
		cit++;
	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\t-- test find method --\n" << std::endl;

	NAMESPACE::set<int>::iterator fi;
	fi = cpy.find(16);
	std::cout << "find key 16 result = "<< *fi << std::endl;
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "\t-- test clear method --\n" << std::endl;
	std::cout << "\n";
	std::cout << "is copy container empty ? " << std::endl;
	cpy.empty() ? std::cout << "yes!!!!\n" : std::cout << "noooo\n";
	std::cout << "copy containers size = " << cpy.size() << std::endl;
	std::cout << "\n";
	cpy.clear();
	std::cout << "\n";
	std::cout << "is copy container empty ? " << std::endl;
	cpy.empty() ? std::cout << "yes!!!! clear worked :)\n" : std::cout << "noooo clear failed :(\n";
	std::cout << "copy containers size = " << cpy.size() << std::endl;
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\t\t----- SET TEST END -----\n" << std::endl;
}
