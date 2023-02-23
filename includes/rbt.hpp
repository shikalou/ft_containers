/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:30:13 by ldinaut           #+#    #+#             */
/*   Updated: 2023/02/23 19:29:47 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP

#include <iostream>

enum color
{
	black = 0,
	red = 1
};

namespace ft
{
	template <class T, class V, typename pair, class comp, class Alloc = std::allocator<T> >
	class RBT
	{
		public:

			template <class U>
			struct node
			{
				U		key; // key 
				pair	_pair;
				color	node_color;
				node	*mother;
				node	*l_child;
				node	*r_child;

				node(const pair &p = pair()) :_pair(p)
				{
					key = p.first;
					// _pair = p;
					node_color = red;
					mother = NULL;
					l_child = NULL;
					r_child = NULL;
				}
			};
			typedef typename Alloc::template rebind<node<T> >::other allocator_type;

		private:
			node<T>			*node_null;
			node<T>			*root;
			allocator_type	_malloc;
			comp			_comp;
			
		public:
			RBT()
			{
				std::cout << "rbt construct" << std::endl;
				_malloc = Alloc();
				node_null = make_node();
				// node_null = new node<T>;
				// node_null->mother = NULL;
				node_null->l_child = NULL;
				node_null->r_child = NULL;
				node_null->node_color = black;
				root = make_node();
				root->node_color = black;
				root->l_child = node_null;
				root->r_child = node_null;
			}
			~RBT()
			{
				//std::cout << "rbt destruct" << std::endl;
			}

			node<T>	*minimum(node<T> *x)
			{
				while (x->l_child != node_null)
					x = x->l_child;
				return (x);
			}

			void	rb_transplant(node<T> *n, node<T> *m)
			{
				if (n->mother == NULL)
				{
					root = m;
				}
				else if (n == n->mother->l_child)
					n->mother->l_child = m;
				else
					n->mother->r_child = m;
				m->mother = n->mother;
			}

			void	delete_fix(node<T> *x)
			{
				node<T> *w;
				while (x != root && x->node_color == black)
				{
					if (x == x->mother->l_child)
					{
						w = x->mother->r_child;
						if (w->node_color == red)
						{
							w->node_color = black;
							x->mother->node_color = red;
							left_rotate(x->mother);
							w = x->mother->r_child;
						}
						if (w->l_child->node_color == black && w->r_child->node_color == black)
						{
							w->node_color = red;
							x = x->mother;
						}
						else
						{
							if (w->r_child->node_color == black)
							{
								w->l_child->node_color = black;
								w->node_color = red;
								right_rotate(w);
								w = x->mother->r_child;
							}
							w->node_color = x->mother->node_color;
							x->mother->node_color = black;
							w->r_child->node_color = black;
							left_rotate(x->mother);
							x = root;
						}
					}
					else
					{
						w = x->mother->l_child;
						if (w->node_color == red)
						{
							w->node_color = black;
							x->mother->node_color = red;
							right_rotate(x->mother);
							w = x->mother->l_child;
						}
						if (w->r_child->node_color == black && w->l_child->node_color == black)
						{
							w->node_color = red;
							x = x->mother;
						}
						else
						{
							if (w->l_child->node_color == black)
							{
								w->r_child->node_color = black;
								w->node_color = red;
								left_rotate(w);
								w = x->mother->l_child;
							}
							w->node_color = x->mother->node_color;
							x->mother->node_color = black;
							w->l_child->node_color = black;
							right_rotate(x->mother);
							x = root;
						}
					}
				}
				x->node_color = black;
			}

			void	rb_delete(T key)
			{
				node<T>	*y;
				node<T>	*x;
				node<T>	*n;

				node<T>	*tmp = root;
				while (tmp != node_null)
				{
					n = tmp;
					if (key < tmp->key)
					{
						tmp = tmp->l_child;
					}
					else if (key > tmp->key)
					{
						tmp = tmp->r_child;
					}
					if (key == tmp->key)
					{
						n = tmp;
						break ;
					}
				}
				y = n;
				std::cout << "n = " << n->key << " y = "<< y->key << std::endl;
				color og_color_y = y->node_color;
				if (n->l_child == node_null)
				{
					std::cout << "11111111111111111111111111111\n";
					x = n->r_child;
					rb_transplant(n, n->r_child);
				}
				else if (n->r_child == node_null)
				{
					x = n->l_child;
					rb_transplant(n, n->l_child);
				}
				else
				{
					std::cout << "2222222222222222222222222222\n";
					y = minimum(n->r_child);
					og_color_y = y->node_color;
					x = y->r_child;
					if (y->mother == n)
						x->mother = y;
					else
					{
						rb_transplant(y, y->r_child);
						y->r_child = n->r_child;
						y->r_child->mother = y;
					}
					rb_transplant(n, y);
					y->l_child = n->l_child;
					y->l_child->mother = y;
					y->node_color = n->node_color;
				}
				if (og_color_y == black)
				{
					delete_fix(x);
				}
			}

			void	right_rotate(node<T> *n)
			{
				node<T> *y;

				y = n->l_child;
				n->l_child = y->r_child;
				if (y->r_child != NULL)
					y->r_child->mother = n;
				y->mother = n->mother;
				if (n->mother == NULL)
					root = y;
				else if (n == n->mother->r_child)
					n->mother->r_child = y;
				else
				{
					n->mother->l_child = y;
				}
					y->r_child = n;
					n->mother = y;
			}

			void	left_rotate(node<T> *n)
			{
				node<T> *y;

				y = n->r_child;
				n->r_child = y->l_child;
				if (y->l_child != NULL)
					y->l_child->mother = n;
				y->mother = n->mother;
				if (n->mother == NULL)
					root = y;
				else if (n == n->mother->l_child)
					n->mother->l_child = y;
				else
					n->mother->r_child = y;
				y->l_child = n;
				n->mother = y;
			}
			
			void	insert_fix(node<T> *new_node)
			{
				node<T> *y = NULL;

				while (new_node->mother->node_color == red)
				{
					if (new_node->mother == new_node->mother->mother->l_child) // LEFT
					{
						// std::cout << "blabla color: " << new_node->mother->mother->r_child->node_color << "\n";
						// std::cout << "blabla value: " << new_node->mother->mother->r_child->_pair.second << std::endl;
						y = new_node->mother->mother->r_child;
						// std::cout << "Y color: " << y->node_color << "\n";
						// std::cout << "new_node value: " << new_node->_pair.second << std::endl;
						if (y && y->node_color == red)
						{
							new_node->mother->node_color = black;
							y->node_color = black;
							new_node->mother->mother->node_color = red;
							new_node = new_node->mother->mother;
						}
						else
						{
							if (new_node == new_node->mother->r_child)
							{
								new_node = new_node->mother;
								left_rotate(new_node);
							}
							new_node->mother->node_color = black;
							new_node->mother->mother->node_color = red;
							right_rotate(new_node->mother->mother);
						}
					}
					else// if(new_node->mother == new_node->mother->mother->r_child)
					{
						y = new_node->mother->mother->l_child;
						// std::cout << "Y color dans else right: " << y->node_color << "\n";
						if (y && y->node_color == red)
						{
							new_node->mother->node_color = black;
							y->node_color = black;
							new_node->mother->mother->node_color = red;
							new_node = new_node->mother->mother;
						}
						else
						{
							if (new_node == new_node->mother->l_child)
							{
								new_node = new_node->mother;
								right_rotate(new_node);
							}
							new_node->mother->node_color = black;
							new_node->mother->mother->node_color = red;
							left_rotate(new_node->mother->mother);
						}
					}
					if (new_node == root)
						break ;
				}
				root->node_color = black;
			}

			node<T>	*make_node(const pair &p = pair())
			{
				node<T> *new_node = _malloc.allocate(1);
				_malloc.construct(new_node, node<T>(p));
				return (new_node);
			}

			void	insert(const pair &p)
			{
				node<T> *new_node = make_node(p);
				
				//new_node = node_null;
				new_node->l_child = NULL;
				new_node->r_child = NULL;
				// new_node->mother = NULL;
				// new_node->key = newkey;
				new_node->node_color = red;

				node<T>	*tmp = root;
				node<T>	*x = NULL;
				while (tmp != NULL)
				{
					x = tmp;
					if (new_node->_pair.first < tmp->_pair.first)
					{
						tmp = tmp->l_child;
					}
					else if (new_node->_pair.first > tmp->_pair.first)
					{
						tmp = tmp->r_child;
					}
				}
				new_node->mother = x;
				if (x == node_null)
				{
					root = new_node;
					root->node_color = black;
				}
				else if (new_node->_pair.first < x->_pair.first)
				{
					x->l_child = new_node;
					std::cout << "lol\n";
				}
				else if (new_node->_pair.first > x->_pair.first)
				{
					x->r_child = new_node;
				}
				else
				{
					x->r_child = new_node;
					new_node->l_child = NULL;
					new_node->r_child = NULL;
					new_node->node_color = red;
				}
				if (!new_node->mother || !new_node->mother->mother)
					return ;
				insert_fix(new_node);
			}

			node<T>	*getNull()
			{
				return (node_null);
			}

			node<T>	*getRoot()
			{
				return (root);
			}

	};
}

#endif
