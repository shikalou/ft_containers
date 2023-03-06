/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:11:34 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/02 15:15:32 by ldinaut          ###   ########.fr       */
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
			reference		operator*() const {return (*_p);}
			nodeptr			operator->() const {return (_p);}
			map_iterator	&operator++()
			{
				nodeptr tmp;

				if (_p->r_child != NULL)
				{
					tmp = _p->r_child;
					while (tmp && tmp->l_child)
					{
						tmp = tmp->l_child;
					}
					return (tmp);
				}
				else if (_p->mother != NULL)
				{
					tmp = _p->mother;
					while (tmp && tmp->key < _p->key)
					{
						tmp = tmp->mother;
					}
					return (tmp);
				}
				return (_p->r_child);
			}
			map_iterator	operator++(int);
			map_iterator	&operator--();
			map_iterator	operator--(int);
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
			friend map_iterator<T,U>	operator+(typename map_iterator<T,U>::difference_type n, const map_iterator<T,U> &rhs)
			{
				map_iterator<T,U> tmp(rhs);
				tmp._p += n;
				return (tmp);
			}
			friend map_iterator<T,U>	operator+(const map_iterator<T,U> &lhs, typename map_iterator<T,U>::difference_type n)
			{
				map_iterator<T,U> tmp(lhs);
				tmp._p += n;
				return (tmp);
			}
			friend map_iterator<T,U>	operator-(const map_iterator<T,U> &lhs, typename map_iterator<T,U>::difference_type n)
			{
				map_iterator<T,U> tmp(lhs);
				tmp._p -= n;
				return (tmp);
			}
			friend typename map_iterator<T,U>::difference_type		operator-(const map_iterator<T,U> &lhs, const map_iterator<T,U> &rhs)
			{
				return (lhs._p - rhs._p);
			}

		private:
			nodeptr	_p;
	};
}

#endif
