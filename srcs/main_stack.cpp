/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:26:49 by ldinaut           #+#    #+#             */
/*   Updated: 2023/02/08 14:50:14 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.hpp"
#include <iostream>
#include <stack>

int	main()
{
	ft::stack<int> mine;
	std::stack<int> vrai;

	std::cout << "mine is empty ? = " <<  mine.empty() << std::endl;
	std::cout << "vrai is empty ? = " <<  vrai.empty() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 10; i > 0; --i)
	{
		mine.push(i);
		std::cout << "mine stack[" << i << "] = " << mine.top() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 10; i > 0; --i)
	{
		vrai.push(i);
		std::cout << "vrai stack[" << i << "] = " << vrai.top() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "mine is empty ? = " <<  mine.empty() << std::endl;
	std::cout << "vrai is empty ? = " <<  vrai.empty() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "mine size ? = " <<  mine.size() << std::endl;
	std::cout << "vrai size ? = " <<  vrai.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	mine.pop();
	vrai.pop();
	std::cout << "pop once" << std::endl;
	std::cout << "mine size ? = " <<  mine.size() << std::endl;
	std::cout << "vrai size ? = " <<  vrai.size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "mine top = " << mine.top() << std::endl;
	std::cout << "vrai top = " << vrai.top() << std::endl;
}
