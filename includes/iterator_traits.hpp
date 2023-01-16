/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:13:13 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/16 19:33:30 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

template <class Iterator>
class iterator_traits
{
	
};

template <class T>
class iterator_traits<T*>
{

};

template <class T>
class iterator_traits<const T*>
{

};

#endif
