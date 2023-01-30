/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:41:52 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/30 17:25:02 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

#include "is_integral.hpp"

namespace ft
{
	template<bool B, class T = void>
	struct enable_if
	{
		
	};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}

#endif
