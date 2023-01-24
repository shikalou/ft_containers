/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:44:58 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/24 16:35:45 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iterator_traits.hpp>

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

					/*CONSTRUCTORS*/
			reverse_iterator(); //default cons
			reverse_iterator(iterator_type it); //initialize cons
			// template <class Iter>
			// reverse_iterator(const reverse_iterator<Iter> &rev_it); //copy cons

			iterator_type		base() const;

					/*OPERATOR OVERLOAD*/
			reference			operator*() const;
			pointer				operator->() const;
			reverse_iterator	&operator++(); // pre_decrement
			reverse_iterator	operator++(int); // post_decrement
			reverse_iterator	&operator--(); // pre_increment
			reverse_iterator	operator--(int); // post_increment
			reverse_iterator	operator+(difference_type n) const;
			reverse_iterator	operator-(difference_type n) const;
			reverse_iterator	&operator+=(difference_type n);
			reverse_iterator	&operator-=(difference_type n);
			reference			&operator[](difference_type n) const;

		private :
			iterator_type _it; //base
	};

	template <class Iterator>
	bool	operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool	operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool	operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool	operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool	operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool	operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& rev_it);

	template <class Iterator>
	reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& rev_it);

}

#include <reverse_iterator.tpp>

#endif
