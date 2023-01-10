/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:28:23 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/10 17:52:09 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class Vector
	{
		public:
				/*CONS/DESTRUCTOR*/
			Vector();
			~Vector();
			Vector(unsigned int n, const T &val);
		//	Vector(); //range
			Vector(const Vector &copy);

				/*OPERATOR OVERLOAD*/
			Vector	&operator=(const Vector &egal);
			T		&operator[](unsigned int i);

				/*METHODES*/
			T		&at(unsigned int i);
			unsigned int size() const;
			void	push_back(const T &val);

				/*EXEPTIONS*/
			class BadIndex : public std::exception
			{
				const char *what() const throw();
			};

		private:
			T				*_vec;
			unsigned int	_size;
			unsigned int	_capacity;
			Alloc			_malloc;

			void	checkCapacity();
	};
}

#include "Vector.tpp"

#endif
