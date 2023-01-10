/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:35:22 by ldinaut           #+#    #+#             */
/*   Updated: 2023/01/10 19:28:01 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
#define VECTOR_TPP

namespace ft
{
					/*****CONS/DESTRUCTOR*****/
	template <class T, class Alloc>
	Vector<T, Alloc>::Vector()
	{
		std::cout << "vector default constructor called" << std::endl;
		_malloc = Alloc();
		_vec = _malloc.allocate(0);
		_size = 0;
		_capacity = 0;
	}

	template <class T, class Alloc>
	Vector<T, Alloc>::Vector(unsigned int n, const T &val)
	{
		std::cout << "vector fill constructor called" << std::endl;
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
		std::cout << "vector copy constructor called" << std::endl;
		_malloc = Alloc();
		_size = copy._size;
		_capacity = copy._capacity;
		_vec = _malloc.allocate(copy._capacity);
		for (unsigned int i = 0; i < _size; ++i)
		{
			_malloc.construct(_vec + i, copy._vec[i]);
		}
	}

	template <class T, class Alloc>
	Vector<T, Alloc>::~Vector()
	{
		std::cout << "vector destructor called" << std::endl;
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
	T	&Vector<T, Alloc>::operator[](unsigned int i)
	{
		return (this->_vec[i]);
	}

					/*****METHODES*****/
	template <class T, class Alloc>
	T	&Vector<T, Alloc>::at(unsigned int i)
	{
		if (i >= _size)
			throw (BadIndex());
		return (_vec[i]);
	}

	template <class T, class Alloc>
	unsigned int	Vector<T, Alloc>::size() const
	{
		return (_size);
	}

	template <class T, class Alloc>
	void	Vector<T, Alloc>::checkCapacity()
	{
		std::cout << " dans checkcapacity size = " << _size << "capacity = " << _capacity << std::endl;
		if (_size + 1 >= _capacity)
		{
			if (_capacity == 0)
				_capacity++;
			T	*new_tab = _malloc.allocate(_capacity * 2);
			for (unsigned int i = 0; i < _size; ++i)
			{
				_malloc.construct(new_tab + i, _vec[i]);
			}
			for (int i = _size; i != 0; --i)
			{
				_malloc.destroy(_vec + i);
			}
			_malloc.deallocate(_vec, _capacity);
			_capacity *= 2;
			_vec = new_tab;
		}
	}

	template <class T, class Alloc>
	void	Vector<T, Alloc>::push_back(const T &val)
	{
		checkCapacity();
		_malloc.construct(_vec + _size, val);
		_size++;
		for (unsigned int i = 0; i < _size; ++i)
		{
			std::cout << "vec[i] " << _vec[i] << std::endl;
		}
	}

					/*****EXEPTIONS*****/
	template <class T, class Alloc>
	const char *Vector<T, Alloc>::BadIndex::what() const throw()
	{
		return ("Index is out of range");
	}
}

#endif
