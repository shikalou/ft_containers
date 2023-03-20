/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:53:54 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/20 17:54:49 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TPP
#define STACK_TPP

namespace ft
{
				/*****CONS/DESTRUCTOR*****/
	template <class T, class Container>
	stack<T, Container>::stack(const container_type &ctnr):_c(ctnr)
	{
		////std::cout << "stack default constructor called" << std::endl;
	}

	template <class T, class Container>
	stack<T,Container>::~stack()
	{
		////std::cout << "stack default destructor called" << std::endl;
	}
				/*****OPERATOR OVERLOAD******/
	template <class T, class Container>
	stack<T, Container>&	stack<T, Container>::operator=(const stack &egal)
	{
		_c = egal._c;
		return (*this);
	}

				/*****PUBLIC METHODES*****/
	template <class T, class Container>
	bool	stack<T,Container>::empty() const
	{
		return (_c.empty());
	}

	template <class T, class Container>
	typename Container::reference	stack<T, Container>::top()
	{
		return (_c.back());
	}

	template <class T, class Container>
	typename Container::size_type	stack<T, Container>::size() const
	{
		return(_c.size());
	}

	template <class T, class Container>
	void	stack<T,Container>::push(const value_type &val)
	{
		return (_c.push_back(val));
	}

	template <class T, class Container>
	void	stack<T,Container>::pop()
	{
		return (_c.pop_back());
	}
}

#endif

