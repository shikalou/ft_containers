/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:31:39 by ldinaut           #+#    #+#             */
/*   Updated: 2023/02/01 17:08:46 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "vector.hpp"

namespace ft
{
	template <class T>
	class vector_iterator
	{
		public:
			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef ft::random_access_iterator_tag	iterator_category;

				/*CONS/DESTRUCTORS*/
			vector_iterator(pointer t = 0);
			vector_iterator(const vector_iterator<T> &copy);
			~vector_iterator();

				/*OPERATOR OVERLOADS*/
			vector_iterator	operator=(const vector_iterator &egal);
			reference		operator*() const;
			pointer			operator->() const;
			vector_iterator	&operator++(); // pre_decrement
			vector_iterator	operator++(int); // post_decrement
			vector_iterator	&operator--(); // pre_increment
			vector_iterator	operator--(int); // post_increment
			vector_iterator	&operator+=(difference_type n);
			vector_iterator	&operator-=(difference_type n);
			reference		&operator[](difference_type n) const;
			operator		vector_iterator<const value_type>() const;

				/*FRIENDS OVERLOAD*/
			friend bool	operator!=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
			{
				return (lhs._p != rhs._p);
			}
			friend bool	operator==(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
			{
				return (lhs._p == rhs._p);
			}
			friend bool	operator<(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs)
			{
				return (lhs._p < rhs._p);
			}
			friend bool	operator>(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs)
			{
				return (lhs._p > rhs._p);
			}
			friend bool	operator<=(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs)
			{
				return (lhs._p <= rhs._p);
			}
			friend bool	operator>=(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs)
			{
				return (lhs._p >= rhs._p);
			}
			friend vector_iterator<T>	operator+(typename vector_iterator<T>::difference_type n, const vector_iterator<T> &rhs)
			{
				vector_iterator<T> tmp(rhs);
				tmp._p += n;
				return (tmp);
			}
			friend vector_iterator<T>	operator+(const vector_iterator<T> &lhs, typename vector_iterator<T>::difference_type n)
			{
				vector_iterator<T> tmp(lhs);
				tmp._p += n;
				return (tmp);
			}
			friend vector_iterator<T>	operator-(const vector_iterator<T> &lhs, typename vector_iterator<T>::difference_type n)
			{
				vector_iterator<T> tmp(lhs);
				tmp._p -= n;
				return (tmp);
			}
			friend typename vector_iterator<T>::difference_type		operator-(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
			{
				return (lhs._p - rhs._p);
			}

		private:
			pointer	_p;
	};
}

#include "vector_iterator.tpp"

#endif
