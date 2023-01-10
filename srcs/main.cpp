/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:49:08 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/10 19:28:52 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include "../includes/Vector.hpp"

int	main()
{
	ft::Vector<int> empty;

	ft::Vector<int> fill(3, 50);
	for (unsigned int i = 0; i < fill.size(); ++i)
	{
		std::cout << "vec[i] = " << fill[i] << std::endl;
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

	ft::Vector<int> copy(fill);
	for (unsigned int i = 0; i < copy.size(); ++i)
	{
		std::cout << "copy[i] = " << copy[i] << std::endl;
	}
	copy.push_back(8);
	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << copy.size() << std::endl;
	for (unsigned int i = 0; i < copy.size(); ++i)
	{
		std::cout << "copy[i] = " << copy[i] << std::endl;
	}
}
