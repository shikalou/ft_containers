/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:26:49 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/22 14:04:21 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.hpp"
#include <iostream>
#include <stack>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

int	main()
{
	NAMESPACE::stack<int> mine;
	std::cout << "\t\t----- STACK TEST START -----\n" << std::endl;
	std::cout << "is stack empty ? = " <<  mine.empty() << std::endl;
	std::cout << std::endl;
	std::cout << "\t-- push 10 values in stack --\n" << std::endl;
	for (int i = 10; i > 0; --i)
	{
		mine.push(i);
		std::cout << "stack[" << i << "] = " << mine.top() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "stack is empty ? = " <<  mine.empty() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "stack size ? = " <<  mine.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\t-- pop last element out of stack --\n" << std::endl;
	mine.pop();
	std::cout << "stack size ? = " <<  mine.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\t-- check top element --\n" << std::endl;
	std::cout << "stack top = " << mine.top() << std::endl;
}
