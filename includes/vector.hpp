/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:28:23 by ldinaut           #+#    #+#             */
/*   Updated: 2023/02/22 19:04:16 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iterator>
#include <stdexcept>
#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T													value_type;
			typedef Alloc												allocator_type;
			typedef vector_iterator<value_type>							iterator;
			typedef vector_iterator<const value_type>					const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef T&													reference;
			typedef const T&											const_reference;
			typedef typename iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t												size_type;

				/*CONS/DESTRUCTOR*/
			explicit vector(const allocator_type& alloc = allocator_type());
			~vector();
			explicit vector (size_type n, const value_type& val = value_type());
			template <class InputIterator> 
			vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type());
			vector(const vector &copy);

				/*OPERATOR OVERLOAD*/
			vector		&operator=(const vector &egal);
			T			&operator[](size_type i);

				/*METHODES*/
			template <class InputIterator>
			void				assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last);
			void				assign(size_type n, const value_type &val);
			value_type			&at(size_type i);
			const_reference		at(size_type n) const;
			T					&back() const;
			iterator			begin();
			const_iterator		begin() const;
			size_type			capacity() const;
			void				clear();
			iterator 			end();
			const_iterator		end() const;
			bool				empty() const;
			iterator			erase(iterator position);
			iterator			erase(iterator first, iterator last);
			reference			front() const;
			allocator_type		get_allocator() const;
			iterator			insert(iterator position, const value_type &val);
			void				insert(iterator position, size_type n, const value_type &val);
			template <class InputIterator>
			void				insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last);
			size_type			max_size() const;
			void				pop_back();
			void				push_back(const T &val);
			reverse_iterator	rbegin(){return (reverse_iterator(_vec + _size));}
			reverse_iterator	rend(){return (reverse_iterator(_vec));}
			const_reverse_iterator	rbegin() const{ return (const_reverse_iterator(_vec + _size));}
			const_reverse_iterator	rend() const{ return (const_reverse_iterator(_vec));} 
			void				reserve(size_type n);
			void				resize(size_type n, T val = T());
			size_type			size() const;
			void				swap(vector<T, Alloc> &x);

		private:
			T				*_vec;
			unsigned int	_size;
			unsigned int	_capacity;
			allocator_type	_malloc;

				/*MINE*/
			void	updateCapacity(unsigned int size, unsigned int capacity);
	};

	template <class T, class Alloc>
	void swap (vector<T,Alloc> &x, vector<T,Alloc> &y);

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);
}

#include "vector.tpp"

#endif
