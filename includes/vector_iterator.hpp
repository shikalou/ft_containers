/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:31:39 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/24 16:38:49 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

namespace ft
{
	template <class T>
	class vector_iterator
	{
		public:
			typedef T				value_type;
			typedef std::ptrdiff_t	difference_type;
			typedef T*				pointer;
			typedef T&				reference;
			typedef ft::random_access_iterator_tag	iterator_category;

				/*CONS/DESTRUCTORS*/
			vector_iterator(pointer t = 0);
			vector_iterator(const vector_iterator<T> &copy);
			~vector_iterator();

				/*OVERLOADS OPERATOR*/
			vector_iterator	operator=(const vector_iterator &egal);
			reference		operator*() const;
			vector_iterator	&operator++(); // pre_decrement
			vector_iterator	operator++(int); // post_decrement
			vector_iterator	&operator--(); // pre_increment
			vector_iterator	operator--(int); // post_increment
			vector_iterator	&operator+=(difference_type n);
			vector_iterator	&operator-=(difference_type n);
			reference		&operator[](difference_type n) const;

			friend bool					operator!=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs);
			friend bool					operator==(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs);
			friend bool					operator<(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs);
			friend bool					operator>(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs);
			friend bool					operator<=(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs);
			friend bool					operator>=(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs);
			friend vector_iterator<T>	operator+(typename vector_iterator<T>::difference_type n, vector_iterator<T> &rhs);
			friend vector_iterator<T>	operator+(vector_iterator<T> &lhs, typename vector_iterator<T>::difference_type n);
			friend vector_iterator<T>	operator-(vector_iterator<T> &lhs, typename vector_iterator<T>::difference_type n);
			friend vector_iterator<T>	operator-(vector_iterator<T> &lhs, vector_iterator<T> &rhs);

		private:
			pointer	_p;
	};
	
	template <class T>
	bool		operator!=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs);
	
	template <class T>
	bool		operator==(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs);
	
	template<class T> // n + a
	vector_iterator<T>	operator+(typename vector_iterator<T>::difference_type n, vector_iterator<T> &rhs);

	template<class T> // a + n
	vector_iterator<T>	operator+(vector_iterator<T> &lhs, typename vector_iterator<T>::difference_type n);
	
	template<class T> // a - n
	vector_iterator<T>	operator-(vector_iterator<T> &lhs, typename vector_iterator<T>::difference_type n);

	template<class T> // a - b
	vector_iterator<T>	operator-(vector_iterator<T> &lhs, vector_iterator<T> &rhs);
}

#include "vector_iterator.tpp"

#endif
