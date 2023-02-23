/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:01:23 by ldinaut           #+#    #+#             */
/*   Updated: 2023/02/23 13:50:09 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
#define MAKE_PAIR_HPP

#include "pair.hpp"

namespace ft
{
	template<class T1, class T2>
	ft::pair<T1, T2>	make_pair(T1 t, T2 u)
	{
		return (pair<T1, T2>(t, u));
	}
}
#endif
