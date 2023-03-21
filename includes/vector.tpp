/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:35:22 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/21 23:58:08 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
#define VECTOR_TPP

namespace ft
{
					/*****CONS/DESTRUCTOR*****/
	template <class T, class Alloc>
	vector<T, Alloc>::vector(const allocator_type &alloc)
	{
		// //std::cout << "vector default constructor called" << std::endl;
		_malloc = alloc;
		_vec = _malloc.allocate(0);
		_size = 0;
		_capacity = 0;
	}

	template <class T, class Alloc>
	vector<T, Alloc>::vector (size_type n, const value_type& val)
	{
		// //std::cout << "vector fill constructor called" << std::endl;
		_malloc = Alloc();
		_vec = _malloc.allocate(n);
		_size = n;
		_capacity = n;
		for (unsigned int i = 0; i < _size; ++i)
		{
			_malloc.construct(_vec + i, val);
		}
	}

	template <class T, class Alloc>
	template <class InputIterator>
	vector<T, Alloc>::vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const Alloc &alloc)
	{
		// //std::cout << "vector range constructor called" << std::endl;
		_malloc = alloc;
		_vec = _malloc.allocate(0);
		_size = 0;
		_capacity = 0;
		while (first != last)
		{
			push_back(*first);
			first++;
		}
	}

	template <class T, class Alloc>
	vector<T, Alloc>::vector(const vector &copy)
	{
		// //std::cout << "vector copy constructor called" << std::endl;
		_vec = NULL;
		 _capacity = 0;
		 _size = 0;
		_size = copy._size;
		_capacity = copy._capacity;
		_vec = _malloc.allocate(_capacity);
		for (size_type i = 0; i < _size; ++i)
		{
			_malloc.construct(_vec + i, copy._vec[i]);
		}
	}

	template <class T, class Alloc>
	vector<T, Alloc>::~vector()
	{
		////std::cout << "vector destructor called" << std::endl;
		if (_vec)
		{
				for (size_type i = 0; i < _size; ++i)
				{
					_malloc.destroy(_vec + i);
				}
				_malloc.deallocate(_vec, _capacity);
		}
	}

					/*****OPERATOR OVERLOAD******/
	template <class T, class Alloc>
	vector<T, Alloc>	&vector<T, Alloc>::operator=(const vector &egal)
	{
		if (egal._vec)
		{
			if (_vec)
			{

				for (size_type i = 0; i < _size; ++i)
				{
					_malloc.destroy(_vec + i);
				}
				_malloc.deallocate(_vec, _capacity);
			}
			_malloc = Alloc();
			_size = egal._size;
			_capacity = egal._capacity;
			_vec = _malloc.allocate(_capacity);
			for (size_type i = 0; i < egal._size; ++i)
			{
				_malloc.construct(_vec + i, egal._vec[i]);
			}
		}
		return (*this);
	}

	template <class T, class Alloc>
	T	&vector<T, Alloc>::operator[](size_type i)
	{
		return (this->_vec[i]);
	}

					/*****METHODES*****/
	template <class T, class Alloc>
	T	&vector<T, Alloc>::at(size_type i)
	{
		if (i >= _size)
			throw (std::out_of_range("out_of_range"));
		return (_vec[i]);
	}

	template <class T, class Alloc>
	const T	&vector<T, Alloc>::at(size_type i) const
	{
		if (i >= _size)
			throw (std::out_of_range("out_of_range"));
		return (_vec[i]);
	}

	template <class T, class Alloc>
	std::size_t	vector<T, Alloc>::size() const
	{
		return (_size);
	}

	template <class T, class Alloc>
	std::size_t	vector<T, Alloc>::capacity() const
	{
		return (_capacity);
	}

	template <class T, class Alloc>
	T	&vector<T, Alloc>::back() const
	{
		return (_vec[_size - 1]);
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::clear()
	{
		for (; _size > 0;)
		{
			_size--;
			_malloc.destroy(_vec + _size);
		}
	}
	template <class T, class Alloc>
	bool	vector<T, Alloc>::empty() const
	{
		if (_size != 0)
			return (false);
		return (true);
	}

	template <class T, class Alloc>
	T	&vector<T, Alloc>::front() const
	{
		return (_vec[0]);
	}

	template <class T, class Alloc>
	std::size_t	vector<T, Alloc>::max_size() const
	{
		return (_malloc.max_size());
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::push_back(const T &val)
	{

		if (_capacity == 0)
			reserve(1);
		if (_size + 1 > _capacity)
			reserve(_capacity * 2); 
		else if (_size + 1 > _capacity && _capacity + 1 == _size)
			reserve(_size + 1);
		_malloc.construct(_vec + _size, val);
		_size++;
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::pop_back()
	{
		_malloc.destroy(_vec + (_size - 1));
		_size--;
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::reserve(size_type n)
	{
		if (n > _malloc.max_size())
			throw (std::length_error("length_error"));
		if (n > _capacity)
		{
			T	*new_tab = _vec;
			_vec = _malloc.allocate(n);
			for (size_type i = 0; i < _size ; ++i)
				_malloc.construct(_vec + i, new_tab[i]);
			for (size_type i = 0; i < _size; ++i)
				_malloc.destroy(&new_tab[i]);
			_malloc.deallocate(new_tab, _capacity);
			_capacity = n;
		}
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::resize(size_type n, T val)
	{
		if (n > _capacity)
			reserve(n);
		if (n < _size)
		{
			for (; _size > n; --_size)
				_malloc.destroy(_vec + (_size - 1));
		}
		else if (n > _size)
		{
			for (size_type i = _size; i < n; ++i)
			{
				_malloc.construct(_vec + i, val);
				_size++;
			}
		}
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::swap(vector<T, Alloc> &x)
	{
		T				*vec_tmp = x._vec;
		unsigned int	size_tmp = x._size;
		unsigned int	capa_tmp = x._capacity;
		Alloc			malloc_tmp = x._malloc;

		x._vec = _vec;
		x._size = _size;
		x._capacity = _capacity;
		x._malloc = _malloc;

		_vec = vec_tmp;
		_size = size_tmp;
		_capacity = capa_tmp;
		_malloc = malloc_tmp;
	}

	template<class T, class Alloc>
	Alloc	vector<T, Alloc>::get_allocator() const
	{
		return (_malloc);
	}

	template<class T, class Alloc>
	vector_iterator<T>	vector<T, Alloc>::begin()
	{
		return (iterator(&_vec[0]));
	}

	template<class T, class Alloc>
	vector_iterator<const T>	vector<T, Alloc>::begin() const
	{
		return (const_iterator(&_vec[0]));
	}

	template<class T, class Alloc>
	vector_iterator<T>	vector<T, Alloc>::end()
	{
		return (iterator(_vec + _size));
	}

	template<class T, class Alloc>
	vector_iterator<const T>	vector<T, Alloc>::end() const
	{
		return (const_iterator(_vec + _size));
	}
	
	template<class T, class Alloc>
	vector_iterator<T>	vector<T, Alloc>::erase(iterator position)
	{
		if (position < end())
		{
			_size--;
			iterator tmp(position);
			_malloc.destroy(position.operator->());
			for (;tmp < end();)
			{ 
				_malloc.construct(tmp.operator->(), *(tmp + 1));
				tmp++;
				_malloc.destroy(tmp.operator->());
			}
		}
		return (position);
	}

	template<class T, class Alloc>
	vector_iterator<T>	vector<T, Alloc>::erase(iterator first, iterator last)
	{
		while (first != last)
		{
			erase(first);
			last--;
		}
		return (first);
	}
	
	template<class T, class Alloc>
	void	vector<T, Alloc>::assign(size_type n, const value_type &val)
	{
		clear();
		while(n)
		{
			push_back(val);
			n--;
		}
	}

	template<class T, class Alloc>
	template <class InputIterator>
	void	vector<T, Alloc>::assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
	{
		clear();
		while (first != last)
		{
			push_back(*first);
			first++;
		}
	}

	template<class T, class Alloc>
	vector_iterator<T>	vector<T, Alloc>::insert(iterator position, const value_type &val)
	{
		if (position == end())
		{
			push_back(val);
			return (iterator(end() - 1));
		}
		size_type j = position - begin();
		if (_capacity < _size + 1)
			reserve(_size + 1);
		_size++;
		size_type i = size() - 1;
		while (i > j)
		{		
			_malloc.construct(&_vec[i], _vec[i - 1]);
			i--;
			_malloc.destroy(_vec + i);
		}
		_malloc.construct(_vec + i, val);
		return (iterator(_vec + i));
	}


	template <class T, class Alloc>
	void	vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val)
	{
		size_type tmp = position - begin();
		while (n)
		{
			insert(_vec + tmp, val);
			tmp++;
			n--;
		}
	}

	template<class T, class Alloc>
	template <class InputIterator>
	void	vector<T, Alloc>::insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
	{
		size_type tmp = position - begin();
		while (first != last)
		{
			insert(_vec + tmp, *first);
			tmp++;
			first++;
		}
	}

					/*****NON-MEMBER OVERLOAD*****/
	template <class T, class Alloc>
	void swap (vector<T,Alloc> &x, vector<T,Alloc> &y)
	{
		x.swap(y);
	}
						/*RELATIONAL OPERATORS*/
	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

					/*****MINE*****/
	template <class T, class Alloc>
	void	vector<T, Alloc>::updateCapacity(unsigned int size, unsigned int capacity)
	{
		if (size >= _capacity)
		{
			T	*new_tab = _vec;//_malloc.allocate(capacity);
			_vec = _malloc.allocate(capacity);
			for (size_type i = 0; i < _size ; ++i)
				_malloc.construct(_vec + i, new_tab[i]);
			for (size_type i = 0; i < _size; ++i)
				_malloc.destroy(&new_tab[i]);
			_malloc.deallocate(new_tab, _capacity);
			_capacity = capacity;
		}
	}
}

#endif
