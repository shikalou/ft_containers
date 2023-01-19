/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:28:23 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/19 18:48:58 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include <reverse_iterator.hpp>
#include <vector_iterator.hpp>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class Vector
	{
		public:
			typedef T								value_type;
			typedef Alloc							allocator_type;
			typedef vector_iterator<value_type>		iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef size_t							size_type;

				/*CONS/DESTRUCTOR*/
			explicit Vector(const allocator_type& alloc = allocator_type());
			~Vector();
			explicit Vector (size_type n, const value_type& val = value_type());
		//	Vector(); //range
			Vector(const Vector &copy);

				/*OPERATOR OVERLOAD*/
			Vector	&operator=(const Vector &egal);
			T		&operator[](size_type i);

				/*METHODES*/
			value_type	&at(size_type i);
			T			&back() const;
			void		clear();
			size_type	size() const;
			size_type	capacity() const;
			bool		empty() const;
			T			&front() const;
			size_type	max_size() const;
			void		push_back(const T &val);
			void		pop_back();
			void		reserve(size_type n);
			void		resize(size_type n, T val = T());
			void		swap(Vector<T, Alloc> &x);

		private:
			T				*_vec;
			unsigned int	_size;
			unsigned int	_capacity;
			allocator_type	_malloc;

				/*MINE*/
			void	updateCapacity(unsigned int size, unsigned int capacity);
	};

	template <class T, class Alloc>
	void swap (Vector<T,Alloc> &x, Vector<T,Alloc> &y);
}

#include "Vector.tpp"

#endif
