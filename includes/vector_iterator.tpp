/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:37:47 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/24 16:38:37 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_TPP
#define VECTOR_ITERATOR_TPP

namespace ft
{
		/*****CONS/DESTRUCTOR*****/
	template<class T>
	vector_iterator<T>::vector_iterator(pointer t) :_p(t)
	{
	}

	template<class T>
	vector_iterator<T>::vector_iterator(const vector_iterator<T> &copy)
	{
		_p = copy._p;
	}

	template<class T>
	vector_iterator<T>::~vector_iterator()
	{
		
	}

		/*****OVERLOADS OPERATOR*****/

	template<class T>
	T	&vector_iterator<T>::operator[](difference_type n) const
	{
		return (_p[n]);
	}

	template<class T>
	vector_iterator<T> vector_iterator<T>::operator=(const vector_iterator &egal)
	{
		_p = egal._p;
		return (*this);
	}

	template<class T>
	T	&vector_iterator<T>::operator*() const
	{
		return (*_p);
	}

	template<class T>
	vector_iterator<T>	&vector_iterator<T>::operator--()
	{
		++this->_p;
		return (*this);
	}

	template<class T>
	vector_iterator<T>	vector_iterator<T>::operator--(int)
	{
		vector_iterator tmp = *this;
		--(*this);
		return (tmp);
	}

	template<class T>
	vector_iterator<T>	&vector_iterator<T>::operator++()
	{
		--this->_p;
		return (*this);
	}

	template<class T>
	vector_iterator<T>	vector_iterator<T>::operator++(int)
	{
		vector_iterator tmp = *this;
		++(*this);
		return (tmp);
	}

	template<class T>
	vector_iterator<T>	&vector_iterator<T>::operator+=(difference_type n)
	{
		_p = _p + n;
		return (*this);
	}

	template<class T>
	vector_iterator<T>	&vector_iterator<T>::operator-=(difference_type n)
	{
		_p = _p - n;
		return (*this);
	}

		/*****FRIENDS OVERLOAD*****/
	template<class T>
	bool	operator!=(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs)
	{
		return (lhs._p != rhs._p);
	}

	template<class T>
	bool	operator==(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs)
	{
		return (lhs._p == rhs._p);
	}

	template<class T>
	vector_iterator<T>	operator+(vector_iterator<T> &lhs, typename vector_iterator<T>::difference_type n) // a + n
	{
		lhs._p = lhs._p + n;
		return (lhs);
	}

	template<class T>
	vector_iterator<T>	operator+(typename vector_iterator<T>::difference_type n, vector_iterator<T> &rhs) // n + a
	{
		rhs._p = rhs._p + n;
		return (rhs);
	}

	template<class T>
	vector_iterator<T>	operator-(vector_iterator<T> &lhs, typename vector_iterator<T>::difference_type n) // a - n
	{
		lhs._p = lhs._p - n;
		return (lhs);
	}

	template<class T> // a - b
	vector_iterator<T>	operator-(vector_iterator<T> &lhs, vector_iterator<T> &rhs)
	{
		return (lhs._p - rhs._p);
	}

	template<class T>
	bool	operator<(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs)
	{
		return (lhs._p < rhs._p);
	}

	template<class T>
	bool	operator>(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs)
	{
		return (lhs._p > rhs._p);
	}

	template<class T>
	bool	operator<=(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs)
	{
		return (lhs._p <= rhs._p);
	}

	template<class T>
	bool	operator>=(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs)
	{
		return (lhs._p >= rhs._p);
	}

}

#endif
