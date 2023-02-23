/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:28:00 by ldinaut           #+#    #+#             */
/*   Updated: 2023/02/23 14:02:16 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template<class T1, class T2>
	struct pair
	{
		public:
			typedef T1	first_type;
			typedef T2	second_type;

			first_type	first; //key
			second_type	second; //value

			pair() :first(first_type())
			{
				second = second_type();
			}
			pair(const T1 &x, const T2 &y) :first(x)
			{
				second = y;
			}
			template<class U1, class U2>
			pair(const pair<U1, U2> &p) : first(p.first)
			{
				second = p.second;
			}
			pair& operator= (const pair& pr)
			{
				first = pr.first;
				second = pr.second;
				return (*this);
			}
			
		private:
	};
	
	template <class T1, class T2>
	bool operator==(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T1, class T2>
	bool operator<(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		return (!(rhs<lhs));
	}

	template <class T1, class T2>
	bool operator>(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		return (rhs<lhs);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		return (!(lhs<rhs));
	}
}
#endif
