/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:35:22 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/25 20:24:45 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
#define VECTOR_TPP

namespace ft
{
					/*****CONS/DESTRUCTOR*****/
	template <class T, class Alloc>
	Vector<T, Alloc>::Vector(const allocator_type& alloc)
	{
		// std::cout << "vector default constructor called" << std::endl;
		_malloc = alloc;
		_vec = _malloc.allocate(0);
		_size = 0;
		_capacity = 0;
	}

	template <class T, class Alloc>
	Vector<T, Alloc>::Vector (size_type n, const value_type& val)
	{
		// std::cout << "vector fill constructor called" << std::endl;
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
	Vector<T, Alloc>::Vector(const Vector &copy)
	{
		// std::cout << "vector copy constructor called" << std::endl;
		_malloc = Alloc();
		_vec = _malloc.allocate(copy._capacity);
		_size = copy._size;
		_capacity = copy._capacity;
		for (unsigned int i = 0; i < _size; ++i)
		{
			_malloc.construct(_vec + i, copy._vec[i]);
		}
	}

	template <class T, class Alloc>
	Vector<T, Alloc>::~Vector()
	{
		// std::cout << "vector destructor called" << std::endl;
		if (_vec)
		{
			for (int i = _size; _size != 0; --i)
			{
				_malloc.destroy(_vec + i);
				_size--;
			}
			_malloc.deallocate(_vec, _capacity);
		}
	}

					/*****OPERATOR OVERLOAD******/
	template <class T, class Alloc>
	Vector<T, Alloc>	&Vector<T, Alloc>::operator=(const Vector &egal)
	{
		if (_vec)
		{
			for (unsigned int i = _size; _size != 0; --i)
			{
				_malloc.destroy(_vec + i);
				_size--;
			}
			_malloc.deallocate(_vec, _capacity);
		}
		_malloc = Alloc();
		_size = egal._size;
		_capacity = egal._capacity;
		_vec = _malloc.allocate(_capacity);
		for (unsigned int i = 0; i < egal._size; ++i)
		{
			_malloc.construct(_vec + i, egal._vec[i]);
		}
		return (*this);
	}

	template <class T, class Alloc>
	T	&Vector<T, Alloc>::operator[](size_type i)
	{
		return (this->_vec[i]);
	}

					/*****METHODES*****/
	template <class T, class Alloc>
	T	&Vector<T, Alloc>::at(size_type i)
	{
		if (i >= _size)
			throw (std::out_of_range("out_of_range"));
		return (_vec[i]);
	}

	template <class T, class Alloc>
	std::size_t	Vector<T, Alloc>::size() const
	{
		return (_size);
	}

	template <class T, class Alloc>
	std::size_t	Vector<T, Alloc>::capacity() const
	{
		return (_capacity);
	}

	template <class T, class Alloc>
	T	&Vector<T, Alloc>::back() const
	{
		return (_vec[_size - 1]);
	}

	template <class T, class Alloc>
	void	Vector<T, Alloc>::clear()
	{
		for (unsigned int i = 0; _size != 0; ++i)
		{
			_malloc.destroy(_vec + i);
			_size--;
		}
	}
	template <class T, class Alloc>
	bool	Vector<T, Alloc>::empty() const
	{
		if (_size != 0)
			return (false);
		return (true);
	}

	template <class T, class Alloc>
	T	&Vector<T, Alloc>::front() const
	{
		return (_vec[0]);
	}

	template <class T, class Alloc>
	std::size_t	Vector<T, Alloc>::max_size() const
	{
		return (_malloc.max_size());
	}

	template <class T, class Alloc>
	void	Vector<T, Alloc>::push_back(const T &val)
	{
		if (_capacity == 0)
			_capacity++;
		updateCapacity(_size + 1, _capacity * 2);
		_malloc.construct(_vec + _size, val);
		_size++;
	}

	template <class T, class Alloc>
	void	Vector<T, Alloc>::pop_back()
	{
		_malloc.destroy(_vec + (_size - 1));
		_size--;
	}

	template <class T, class Alloc>
	void	Vector<T, Alloc>::reserve(size_type n)
	{
		if (n > _malloc.max_size())
			throw (std::length_error("length_error"));
		updateCapacity(n, n);
	}

	template <class T, class Alloc>
	void	Vector<T, Alloc>::resize(size_type n, T val)
	{
		if (n < _size)
		{
			for (; _size > n; --_size)
				_malloc.destroy(_vec + (_size - 1));
		}
		else if (n > _size)
		{
			if (n > _capacity)
				updateCapacity(n, n);
			for (unsigned int i = _size; i < n; ++i)
			{
				_malloc.construct(_vec + i, val);
				_size++;
			}
		}
	}

	template <class T, class Alloc>
	void	Vector<T, Alloc>::swap(Vector<T, Alloc> &x)
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
	Alloc	Vector<T, Alloc>::get_allocator() const
	{
		return (_malloc);
	}

	template<class T, class Alloc>
	vector_iterator<T>	Vector<T, Alloc>::begin()
	{
		return (iterator(_vec));
	}

	template<class T, class Alloc>
	vector_iterator<const T>	Vector<T, Alloc>::begin() const
	{
		return (const_iterator(_vec));
	}

	template<class T, class Alloc>
	vector_iterator<T>	Vector<T, Alloc>::end()
	{
		return (iterator(_vec + _size));
	}

	template<class T, class Alloc>
	vector_iterator<const T>	Vector<T, Alloc>::end() const
	{
		return (const_iterator(_vec + _size));
	}
	
	template<class T, class Alloc>
	vector_iterator<T>	Vector<T, Alloc>::erase(iterator position)
	{
		if (position < end())
		{
			_size--;
			iterator tmp(position);
			_malloc.destroy(position.operator->());
			for(;tmp < end(); ++tmp)
			{ 
				_malloc.construct(tmp.operator->(), *(tmp + 1));
				_malloc.destroy(tmp.operator->() + 1);
			}
		}
		return (position);
	}

	template<class T, class Alloc>
	vector_iterator<T>	Vector<T, Alloc>::erase(iterator first, iterator last)
	{
		while (first != last)
		{
			erase(first);
			last--;
		}
		return (first);
	}

					/*****NON-MEMBER OVERLOAD*****/
	template <class T, class Alloc>
	void swap (Vector<T,Alloc> &x, Vector<T,Alloc> &y)
	{
		x.swap(y);
	}

					/*****MINE*****/
	template <class T, class Alloc>
	void	Vector<T, Alloc>::updateCapacity(unsigned int size, unsigned int capacity)
	{
		if (size > _capacity)
		{
			T	*new_tab = _malloc.allocate(capacity);
			for (unsigned int i = 0; i < _size; ++i)
			{
				_malloc.construct(new_tab + i, _vec[i]);
			}
			for (unsigned int i = _size; i != 0; --i)
			{
				_malloc.destroy(_vec + i);
			}
			_malloc.deallocate(_vec, _capacity);
			_capacity = capacity;
			_vec = new_tab;
		}
	}
}

#endif
