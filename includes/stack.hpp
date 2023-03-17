/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:44:58 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/17 20:11:08 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

				/*CONS/DESTRUCTOR*/
			explicit stack(const container_type &ctnr = container_type());
			~stack();

				/*OPERATOR OVERLOAD*/
			stack&	operator=(const stack &egal);

				/*PUBLIC METHODES*/
			bool		empty() const;
			reference	top();
			size_type	size() const;
			void		push(const value_type &val);
			void		pop();

			friend bool	operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
			{
				return (lhs._c != rhs._c);
			}
			friend bool	operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
			{
				return (lhs._c == rhs._c);
			}
			friend bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
			{
				return (lhs._c < rhs._c);
			}
			friend bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
			{
				return (lhs._c > rhs._c);
			}
			friend bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
			{
				return (lhs._c <= rhs._c);
			}
			friend bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
			{
				return (lhs._c >= rhs._c);
			}
		protected:
			container_type	_c;
	};

}

#include "stack.tpp"

#endif
