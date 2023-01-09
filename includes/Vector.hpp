/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:28:23 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/09 19:03:19 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace ft
{
	template <typename T>
	class Vector
	{
		public:
			Vector(); //default
			~Vector();
			Vector(unsigned int n, const T &val); //fill
		//	Vector(); //range
			Vector(const Vector &copy); //copy

			Vector &operator=(const Vector &egal);
		private:
			T	*_vec;
	};

	#include "Vector.tpp"
}


#endif
