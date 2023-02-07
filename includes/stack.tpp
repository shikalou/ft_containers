/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:53:54 by ldinaut           #+#    #+#             */
/*   Updated: 2023/02/07 19:01:20 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TPP
#define STACK_TPP

namespace ft
{
				/*****CONS/DESTRUCTOR*****/
	template <class T, class Container>
	stack<T, Container>::stack(const container_type &ctnr)
	{
		std::cout << "stack default constructor called" << std::endl;
	}
}

#endif
