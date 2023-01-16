/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:49:21 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/16 19:17:05 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Vector.hpp>
#include <vector>
#include <reverse_iterator.hpp>

int	main()
{
	std::vector<int> lol(5);

	lol.push_back(5);
	lol.push_back(6);
	lol.push_back(7);
	lol.push_back(8);

	std::vector<int>::iterator it = lol.end();

	
	std::vector<int>::reverse_iterator rit(it);
	ft::reverse_iterator<std::vector<int>::iterator> my_rit(it);

	rit++;
	my_rit++;
}
