/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:11:34 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/07 19:30:57 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template <class T, class U>
	class map_iterator
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
			map_iterator(nodeptr t = 0):_p(t){}
			map_iterator(const map_iterator<T, U> &copy){_p = copy._p;}
			~map_iterator(){}

				/*OPERATOR OVERLOADS*/
			map_iterator	operator=(const map_iterator &egal){_p = egal._p;return (*this);}
			reference		operator*() const {return (this->_p->_pair);}
			pointer			operator->() const {return (&this->_p->_pair);}
			map_iterator	&operator++()
			{
				nodeptr	tmp = NULL;

				if (_p->r_child != NULL)
				{
					tmp = _p->r_child;
					while (tmp && tmp->l_child)
					{
						tmp = tmp->l_child;
					}
					this->_p = tmp;
					return (*this);
				}
				else if (_p->mother != NULL)
				{
					tmp = _p->mother;
					while (tmp && tmp->key < _p->key)
					{
						tmp = tmp->mother;
					}
					this->_p = tmp;
					return (*this);
				}
				return (*this);
			}
			map_iterator	operator++(int)
			{
				map_iterator tmp(*this);
				++*this;
				return (tmp);
			}
			map_iterator	&operator--()
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
			map_iterator	operator--(int)
			{
				map_iterator tmp(*this);
				--*this;
				return (tmp);
			}
			// map_iterator	&operator+=(difference_type n){_p = _p + n; return (*this);}
			// map_iterator	&operator-=(difference_type n){_p = _p - n; return (*this);}
			reference		&operator[](difference_type n) const{ return (_p[n]);}
			//operator		map_iterator<const value_type>() const {return (map_iterator<const value_type>(_p));}

				/*FRIENDS OVERLOAD*/
			friend bool	operator!=(const map_iterator<T,U> &lhs, const map_iterator<T,U> &rhs)
			{
				return (lhs._p != rhs._p);
			}
			friend bool	operator==(const map_iterator<T,U> &lhs, const map_iterator<T,U> &rhs)
			{
				return (lhs._p == rhs._p);
			}
			friend bool	operator<(const map_iterator<T,U>& lhs, const map_iterator<T,U>& rhs)
			{
				return (lhs._p < rhs._p);
			}
			friend bool	operator>(const map_iterator<T,U>& lhs, const map_iterator<T,U>& rhs)
			{
				return (lhs._p > rhs._p);
			}
			friend bool	operator<=(const map_iterator<T,U>& lhs, const map_iterator<T,U>& rhs)
			{
				return (lhs._p <= rhs._p);
			}
			friend bool	operator>=(const map_iterator<T,U>& lhs, const map_iterator<T,U>& rhs)
			{
				return (lhs._p >= rhs._p);
			}

		private:
			nodeptr	_p;
	};
}

#endif
