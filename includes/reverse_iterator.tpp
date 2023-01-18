/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:09:55 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/18 18:10:27 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_TPP
#define REVERSE_ITERATOR_TPP

namespace ft
{
			/*****CONSTRUCTORS*****/
	template <class Iterator>
	reverse_iterator<Iterator>::reverse_iterator()
	{
		_it = iterator_type();
	}

	template <class Iterator>
	reverse_iterator<Iterator>::reverse_iterator(iterator_type it)
	{
		_it = it;
	}

	// template <class Iter>
	// reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<Iter> &rev_it)
	// {}
			/*****OPERATOR OVERLOAD*****/
	template <class Iterator>
	Iterator	reverse_iterator<Iterator>::base() const
	{
		return (_it);
	}
	
	template <class Iterator>
	typename reverse_iterator<Iterator>::reference	reverse_iterator<Iterator>::operator*() const
	{
		iterator_type tmp = _it;
		return (*--tmp);
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::pointer	reverse_iterator<Iterator>::operator->() const
	{
		iterator_type tmp = _it;
		return (&(*--tmp));
	}

	// template<class Iterator>
	// reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator--()
	// {
	// 	return ()
	// }
}

#endif
