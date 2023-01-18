/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:49:21 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/18 18:21:28 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Vector.hpp>
#include <vector>
#include <reverse_iterator.hpp>

int	main()
{
	std::vector<int> toto(5);

	toto.push_back(5);
	toto.push_back(6);
	toto.push_back(7);
	toto.push_back(8);
	toto.push_back(9);

	std::vector<int>::iterator it = toto.end();

	std::vector<int>::reverse_iterator rit(it);
	ft::reverse_iterator<std::vector<int>::iterator> my_rit(it);

	std::cout << "*rit = " << *rit << std::endl;
	std::cout << "*my_rit = " << *my_rit <<std::endl;
	std::cout << std::endl;

	std::cout << "*rit.base() = " << *rit.base() << std::endl;
	std::cout << "*my_rit.base() = " << *my_rit.base() << std::endl;
	std::cout << std::endl;

//	rit++;
//	my_rit++;
}
