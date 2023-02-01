/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:09:55 by ldinaut           #+#    #+#             */
/*   Updated: 2023/02/01 17:51:00 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_TPP
#define REVERSE_ITERATOR_TPP

namespace ft
{
			/*****CONSTRUCTORS*****/
	template <class Iterator>
	reverse_iterator<Iterator>::reverse_iterator()
	{
		_it = iterator_type();
	}

	template <class Iterator>
	reverse_iterator<Iterator>::reverse_iterator(iterator_type it)
	{
		_it = it;
	}

	template <class Iterator>
	template <class Iter>
	reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter> &copy)
	{
		_it = copy.base();
	}

	template <class Iterator>
	Iterator	reverse_iterator<Iterator>::base() const
	{
		return (_it);
	}
			/*****OPERATOR OVERLOAD*****/
	
	template <class Iterator>
	typename reverse_iterator<Iterator>::reference	reverse_iterator<Iterator>::operator*() const
	{
		iterator_type tmp = _it;
		return (*--tmp);
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::pointer	reverse_iterator<Iterator>::operator->() const
	{
		iterator_type tmp = _it;
		return (&(*--tmp));
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::reference	&reverse_iterator<Iterator>::operator[](difference_type n) const
	{
		return base()[-n - 1];
	}

	template<class Iterator>
	reverse_iterator<Iterator>	&reverse_iterator<Iterator>::operator--()
	{
		++this->_it;
		return (*this);
	}

	template<class Iterator>
	reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator--(int)
	{
		reverse_iterator tmp = *this;
		--(*this);
		return (tmp);
	}

	template<class Iterator>
	reverse_iterator<Iterator>	&reverse_iterator<Iterator>::operator++()
	{
		--this->_it;
		return (*this);
	}

	template<class Iterator>
	reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator++(int)
	{
		reverse_iterator tmp = *this;
		++(*this);
		return (tmp);
	}

	template<class Iterator>
	reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator+(difference_type n) const
	{
		return (reverse_iterator(base() - n));
	}

	template<class Iterator>
	reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator-(difference_type n) const
	{
		return (reverse_iterator(base() + n));
	}

	template<class Iterator>
	reverse_iterator<Iterator>	&reverse_iterator<Iterator>::operator+=(difference_type n)
	{
		this->_it = this->_it - n;
		return (*this);
	}

	template<class Iterator>
	reverse_iterator<Iterator>	&reverse_iterator<Iterator>::operator-=(difference_type n)
	{
		this->_it = this->_it + n;
		return (*this);
	}

	template<class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
	{
		return (rev_it.base() - n);
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
	{
		return (rev_it.base() + n);
	}

	template< class Iterator1, class Iterator2 >
	typename reverse_iterator<Iterator1>::difference_type operator-( const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return (rhs.base() - lhs.base());
	}
}

#endif
