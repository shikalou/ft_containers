/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:47:49 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/30 19:16:01 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft
{
	template <class T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;
		operator T()
		{
			return v;
		}
	};

	typedef integral_constant<bool,true> true_type;
	typedef integral_constant<bool,false> false_type;

	template <class T>
	struct is_integral : public false_type
	{

	};

	template <class T>
	struct is_integral<const T> : public is_integral<T>
	{

	};

	template <class T>
	struct is_integral<volatile T> : public is_integral<T>
	{

	};

	template<> struct is_integral<bool> : public true_type {};
	template<> struct is_integral<char> : public true_type {};
	template<> struct is_integral<signed char> : public true_type {};
	template<> struct is_integral<short int> : public true_type {};
	template<> struct is_integral<int> : public true_type {};
	template<> struct is_integral<long int> : public true_type {};
	template<> struct is_integral<unsigned char> : public true_type {};
	template<> struct is_integral<unsigned short int> : public true_type {};
	template<> struct is_integral<unsigned int> : public true_type {};
	template<> struct is_integral<unsigned long int> : public true_type {};

	template<> struct is_integral<const bool> : public true_type {};
	template<> struct is_integral<const char> : public true_type {};
	template<> struct is_integral<const signed char> : public true_type {};
	template<> struct is_integral<const short int> : public true_type {};
	template<> struct is_integral<const int> : public true_type {};
	template<> struct is_integral<const long int> : public true_type {};
	template<> struct is_integral<const unsigned char> : public true_type {};
	template<> struct is_integral<const unsigned short int> : public true_type {};
	template<> struct is_integral<const unsigned int> : public true_type {};
	template<> struct is_integral<const unsigned long int> : public true_type {};

	template<> struct is_integral<volatile bool> : public true_type {};
	template<> struct is_integral<volatile char> : public true_type {};
	template<> struct is_integral<volatile signed char> : public true_type {};
	template<> struct is_integral<volatile short int> : public true_type {};
	template<> struct is_integral<volatile int> : public true_type {};
	template<> struct is_integral<volatile long int> : public true_type {};
	template<> struct is_integral<volatile unsigned char> : public true_type {};
	template<> struct is_integral<volatile unsigned short int> : public true_type {};
	template<> struct is_integral<volatile unsigned int> : public true_type {};
	template<> struct is_integral<volatile unsigned long int> : public true_type {};
}

#endif
