/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:35:22 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/09 19:14:31 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
#define VECTOR_TPP

namespace ft
{
	template <typename T>
	Vector<T>::Vector()
	{
		std::cout << "vector default constructor called" << std::endl;
		_vec = new T[0];
	}

	template <typename T>
	Vector<T>::Vector(unsigned int n, const T &val)
	{
		std::cout << "vector fill constructor called" << std::endl;
		_vec = new T[n](val);
	}

	template <typename T>
	Vector<T>::Vector(const Vector &copy)
	{
		std::cout << "vector copy constructor called" << std::endl;
		*this = copy;
	}

	template <typename T>
	Vector<T> &Vector<T>::operator=(const Vector &egal)
	{
		// _vec = new T[SIZE_DE_VEC] -> FAIRE LE SIZE DIRECT OU PAS...
		// for (i < size) this._vec[i] = egal._vec[i]
		// return (*this);
	}

	template <typename T>
	Vector<T>::~Vector()
	{
		std::cout << "vector destructor called" << std::endl;
	}
}

#endif
