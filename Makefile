# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:26:50 by ldinaut           #+#    #+#              #
#    Updated: 2023/10/25 00:27:36 by ldinaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_containers

STDNAME	=	std_containers

SRCS_FILES	=	main_stack.cpp
#SRCS_FILES	=	main_vector.cpp
#SRCS_FILES	=	main_map.cpp
#SRCS_FILES	=	main_set.cpp

INC_FILES	=	vector.hpp vector.tpp \
				iterator_traits.hpp \
				vector_iterator.hpp vector_iterator.tpp \
				reverse_iterator.hpp reverse_iterator.tpp \
				is_integral.hpp enable_if.hpp \
				equal.hpp lexicographical_compare.hpp \
				stack.hpp stack.tpp \
				rbt.hpp map.hpp map.tpp map_iterator.hpp \
				rbt_set.hpp set.hpp set.tpp set_iterator.hpp 

SRCS	=	$(addprefix srcs/, $(SRCS_FILES))

INCS	=	$(addprefix includes/, $(INC_FILES))

CXX	=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic -I./includes

OBJS_FILES	=	$(SRCS_FILES:%.cpp=%.o)

OBJS	=	$(addprefix objs/, $(OBJS_FILES))

DEP		=	$(OBJS:%.o=%.d)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJS)
	$(CXX) $(CPPFLAGS) -D STD=1 -o $(STDNAME) $(OBJS)


clean	:
	rm -rf $(OBJS) $(DEP)
	rm -rf objs/

fclean	:	clean
	rm -rf $(NAME) $(STDNAME)

re	:	fclean all

objs/%.o	: srcs/%.cpp $(INCS)
	mkdir -p objs
	$(CXX) $(CPPFLAGS) -MMD -o $@ -c $<

.PHONY: all clean fclean re
