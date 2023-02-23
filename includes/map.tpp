/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:06:45 by ldinaut           #+#    #+#             */
/*   Updated: 2023/02/23 17:39:59 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TPP
#define MAP_TPP

namespace ft
{
	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map()
	{
		// std::cout << "map construct" << std::endl;
		//_tree = RBT<>();
		_size = 0;
	}

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::~map()
	{
		// std::cout << "map destruct" << std::endl;
	}
}

#endif
