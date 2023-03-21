/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:24:02 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/21 20:25:05 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ITERATOR_HPP
#define SET_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template <class T, class U>
	class set_iterator
	{
		public:
			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef T*								pointer;
			typedef U*								nodeptr;
			typedef T&								reference;
			typedef U&								noderef;
			typedef ft::bidirectional_iterator_tag	iterator_category;

				/*CONS/DESTRUCTORS*/
			set_iterator(nodeptr t = 0):_p(t){}
			set_iterator(const set_iterator<T, U> &copy){_p = copy._p;}
			~set_iterator(){}

				/*OPERATOR OVERLOADS*/
			set_iterator	operator=(const set_iterator &egal){_p = egal._p;return (*this);}
			reference		operator*() const {return (*this->_p->_pair);}
			pointer			operator->() const {return (this->_p->_pair);}
			set_iterator	&operator++()
			{
				if (_p == NULL || (_p->mother == NULL && _p->l_child == NULL && _p->r_child == NULL))
					return (*this);
				if (_p->r_child != NULL)
				{
					_p = _p->r_child;
					while (_p && _p->l_child)
					{
						_p = _p->l_child;
					}
					// this->_p = tmp;
					return (*this);
				}
				else if (_p == _p->mother->l_child)
				{
					_p = _p->mother;
				}
				else if (_p->mother != NULL)// && _p == _p->mother->l_child)
				{
					while (_p && _p->mother && _p == _p->mother->r_child)
					{
						_p = _p->mother;
					}
					_p = _p->mother;
					return (*this);
				}
				return (*this);
			}
			set_iterator	operator++(int)
			{
				set_iterator tmp(*this);
				++*this;
				return (tmp);
			}
			set_iterator	&operator--()
			{
				if (_p->l_child != NULL)
				{
					_p = _p->l_child;
					while (_p && _p->r_child)
					{
						_p = _p->r_child;
					}
					// this->_p = tmp;
					return (*this);
				}
				else if (_p == _p->mother->r_child)
				{
					_p = _p->mother;
				}
				else if (_p->mother != NULL)
				{
					while (_p && _p == _p->mother->l_child)
					{
						_p = _p->mother;
					}
					_p = _p->mother;
					return (*this);
				}
				return (*this);
			}
			set_iterator	operator--(int)
			{
				set_iterator tmp(*this);
				--*this;
				return (tmp);
			}
			operator		set_iterator<const T, U>() const {return (set_iterator<const T, U>(_p));}

				/*FRIENDS OVERLOAD*/
			friend bool	operator!=(const set_iterator<T,U> &lhs, const set_iterator<T,U> &rhs)
			{
				return (lhs._p != rhs._p);
			}
			friend bool	operator==(const set_iterator<T,U> &lhs, const set_iterator<T,U> &rhs)
			{
				return (lhs._p == rhs._p);
			}
			friend bool	operator<(const set_iterator<T,U>& lhs, const set_iterator<T,U>& rhs)
			{
				return (lhs._p < rhs._p);
			}
			friend bool	operator>(const set_iterator<T,U>& lhs, const set_iterator<T,U>& rhs)
			{
				return (lhs._p > rhs._p);
			}
			friend bool	operator<=(const set_iterator<T,U>& lhs, const set_iterator<T,U>& rhs)
			{
				return (lhs._p <= rhs._p);
			}
			friend bool	operator>=(const set_iterator<T,U>& lhs, const set_iterator<T,U>& rhs)
			{
				return (lhs._p >= rhs._p);
			}

		private:
			nodeptr	_p;
	};
}

#endif
