/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:49:21 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/20 18:14:43 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Vector.hpp>
#include <vector>
#include <reverse_iterator.hpp>

int	main()
{
	std::vector<int> toto(1, 100);

	toto.push_back(669);
	toto.push_back(668);
	toto.push_back(667);
	toto.push_back(666);
	toto.push_back(665);
	toto.push_back(664);
	toto.push_back(663);
	toto.push_back(662);
	toto.push_back(661);
	toto.push_back(660);


	std::vector<int>::iterator it = toto.begin();

	std::vector<int>::reverse_iterator rit(it);
	ft::reverse_iterator<std::vector<int>::iterator> my_rit(it);

	std::cout << "*rit = " << *rit << std::endl;
	std::cout << "*my_rit = " << *my_rit << std::endl;
	std::cout << std::endl;

	std::cout << "*rit.base() - 1 = " << *rit.base() << std::endl;
	std::cout << "*my_rit.base() - 1 = " << *my_rit.base() << std::endl;
	std::cout << std::endl;

//	rit++;
//	my_rit++;
}
