/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:30:13 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/15 22:45:54 by ldinaut          ###   ########.fr       */
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
	template <class T, class V, typename pair, class comp, class Alloc_pair >
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
				node	&operator=(const node &egal)
				{
					this->key = egal->key;
					this->_pair = egal._pair;
					this->mother = egal.mother;
					this->l_child = egal.l_child;
					this->r_child = egal.r_child;
					this->node_color = egal.node_color;
					return (*this);
				}
			};
			typedef typename Alloc_pair::template rebind<node<T> >::other allocator_type;

		private:
			node<T>			*node_null;
			node<T>			*root;
			Alloc_pair	_malloc_pair;
			allocator_type	_malloc_node;
			comp			_comp;
			size_t			size;

		public:
			RBT()
			{
				std::cout << "rbt construct" << std::endl;
				_malloc_pair = Alloc_pair();
				_malloc_node = allocator_type();
				node_null = make_node();
				// node_null = new node<T>;
				node_null->mother = NULL;
				node_null->l_child = NULL;
				node_null->r_child = NULL;
				node_null->node_color = black;
				root = NULL;
				size = 0;
			}
			~RBT()
			{
				_malloc_node.destroy(node_null);
				_malloc_node.deallocate(node_null, 1);
				//std::cout << "rbt destruct" << std::endl;
			}

			node<T>	*getNull() const
			{
				return (node_null);
			}

			node<T>	*getRoot() const
			{
				return (root);
			}

			comp	getComp() const
			{
				return (_comp);
			}

			allocator_type	getAlloc() const
			{
				return (_malloc_node);
			}

			void	supp_end(node<T> *end)
			{
				_malloc_node.destroy(end);
				_malloc_node.deallocate(end, 1);
			}

			node<T>	*searchKey(node<T> *node, T val) const
			{
				std::cout << "node = " << node << " node-null = " << node_null << "\n";
				if (node == NULL || node->key == val) // || node == node_null)
					return (node);
				else if (_comp(val, node->key))
					return (searchKey(node->l_child, val));
				else
					return (searchKey(node->r_child, val));
			}

			node<T>	*minimum(node<T> *x) const
			{
				if (x && x != node_null && x != NULL)
				{
					while (x->l_child != NULL && x->l_child != node_null)
						x = x->l_child;
				}
				return (x);
			}

			node<T>	*maximum(node<T> *x, node<T> *end) const
			{
				// if ()
				if (size == 0)
					return (NULL);
				while (x && x != node_null && x != NULL && x->r_child != NULL && x->r_child != node_null && x->r_child != end)
					x = x->r_child;
				//}
				if (x == node_null)
					return (NULL);
				return (x);
				// while (x && x->r_child != NULL && x->r_child != node_null && x != node_null)
				// 	x = x->r_child;
				// return (x);
			}

			void	rb_transplant(node<T> *n, node<T> *m) // m --> n->r_child;
			{
				if (m == NULL)
					m = node_null;
				if (n->mother == NULL)
					root = m;
				else if (n == n->mother->l_child)
					n->mother->l_child = m;
				else
					n->mother->r_child = m;
				m->mother = n->mother;
			}

			void	delete_fix(node<T> *x)
			{
				node<T> *w;
				while (x && x != root && x->node_color == black)
				{
					if (x == x->mother->l_child)
					{
						w = x->mother->r_child;
						if (!w)
							w = node_null;
						if (w && w->node_color == red)
						{
							w->node_color = black;
							x->mother->node_color = red;
							left_rotate(x->mother);
							w = x->mother->r_child;
						}
						if (w && w->l_child && w->l_child->node_color == black && w->r_child && w->r_child->node_color == black)
						{
							w->node_color = red;
							x = x->mother;
						}
						else if (w && w->l_child && w->r_child->node_color == black)
						{
							w->l_child->node_color = black;
							w->node_color = red;
							right_rotate(w);
							w = x->mother->r_child;
						}
						w->node_color = x->mother->node_color;
						x->mother->node_color = black;
						if (w->r_child == NULL)
							w->r_child = node_null;
						w->r_child->node_color = black;
						left_rotate(x->mother);
						x = root;
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
						if (w->r_child && w->r_child->node_color == black && w->l_child->node_color == black)
						{
							w->node_color = red;
							x = x->mother;
						}
						else
						{
							if (w->l_child && w->l_child->node_color == black)
							{
								w->r_child->node_color = black;
								w->node_color = red;
								left_rotate(w);
								w = x->mother->l_child;
							}
							w->node_color = x->mother->node_color;
							x->mother->node_color = black;
							if (w->l_child == NULL)
								w->l_child = node_null;
							w->l_child->node_color = black;
							right_rotate(x->mother);
							x = root;
						}
					}
				}
				if (x)
					x->node_color = black;
			}

			void print_rec(node<T> *tmp, int co = 0) {
				if (tmp && tmp != node_null)
				{

					std::cout << std::string(co * 2, ' ') << "n = " << tmp << " v = " << tmp->key << std::endl;
					print_rec(tmp->l_child, co + 1);
					print_rec(tmp->r_child, co + 1);
				}
			}

			int	rb_delete(T key)
			{
				node<T>	*y;
				node<T>	*x;
				node<T>	*n = node_null;

				node<T>	*tmp = root;
				while (tmp != NULL)
				{
					if (tmp && key < tmp->key)
					{
						tmp = tmp->l_child;
					}
					else if (tmp && key > tmp->key)
					{
						tmp = tmp->r_child;
					}
					if (tmp && key == tmp->key)
					{
						n = tmp;
						break ;
					}
				}
				if (n->key == key)
				{
					size--;
					
					//y = make_node(n->_pair);
					std::cout << "n = " << n << " v = " << n->key << " root = "<< getRoot() << std::endl;
					if (size == 2)
						print_rec(root);
					std::cout << "Y COLOR: " << n->node_color << "\n";
					color og_color_y = n->node_color;
					if (size == 0)
					{
						root = NULL;
					}
					else if (n->l_child == NULL || n->l_child == node_null)
					{
						n->l_child = node_null;
						std::cout << "11111111111111111111111111111\n";
						x = n->r_child;
						rb_transplant(n, n->r_child);
					}
					else if (n->r_child == NULL || n->r_child == node_null)
					{
						std::cout << "r child null delete\n";
						x = n->l_child;
						rb_transplant(n, n->l_child);
					}
					else
					{
						y = minimum(n->r_child);
						std::cout << "2222222222222222222222222222\n";
						std::cout << "dans rb_delete y->node_color = " << y->node_color << std::endl;
						og_color_y = y->node_color;
						if (y->r_child == NULL)
							y->r_child = node_null;
						x = y->r_child;
						//x = y;
						if (y->mother == n)
							x->mother = y;
						else
						{
							std::cout << "333333333333333333333333333333\n";
							rb_transplant(y, y->r_child);
							y->r_child = n->r_child;
							y->r_child->mother = y;
						}
						rb_transplant(n, y);
						y->l_child = n->l_child;
						y->l_child->mother = y;
						y->node_color = n->node_color;
					}
					_malloc_node.destroy(n);
					_malloc_node.deallocate(n, 1);
					if (og_color_y == black && size != 0)
					{
						delete_fix(x);
					}
					return (1);
				}
				return (0);
			}

			void	right_rotate(node<T> *n)
			{
				node<T> *y;

				y = n->l_child;
				n->l_child = y->r_child;
				std::cout << "dans right_rotate\ny = " << y->key << "\nn = " << n->key << std::endl;
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
				
				if (!n->r_child)
					n->r_child = node_null;
				y = n->r_child;
				n->r_child = y->l_child;
				std::cout << "dans left_rotate\ny = " << y->key << "\nn = " << n->key << std::endl;
				if (y->l_child != NULL)
					y->l_child->mother = n;
				y->mother = n->mother;
				std::cout << "genre n->mother il est pas null ?????? " << n->key << std::endl;
				if (n->mother == NULL)
				{
					std::cout << "je rentre pas a ?????????????????\n";
					root = y;
				}
				else if (n == n->mother->l_child)
					n->mother->l_child = y;
				else
					n->mother->r_child = y;
				y->l_child = n;
				n->mother = y;
				std::cout << "rooooooot key est egal = " << root->key << std::endl;
			}

			void	insert_fix(node<T> *new_node)
			{
				node<T> *y = NULL;
				std::cout << "\n\ndans insert_fix" << std::endl;

				while (new_node->mother->node_color == red)
				{
					std::cout << "new_node = " << new_node->key << std::endl;
					if (new_node->mother == new_node->mother->mother->l_child) // LEFT
					{
						y = new_node->mother->mother->r_child;
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
					else
					{
						y = new_node->mother->mother->l_child;
						// std::cout << "Y color dans else right: " << y->node_color << "\n";
						if (y && y->node_color == red)
						{
							std::cout << "si mother mother ROUGE" << std::endl;
							new_node->mother->node_color = black;
							y->node_color = black;
							new_node->mother->mother->node_color = red;
							new_node = new_node->mother->mother;
						}
						else
						{
							std::cout << "si mother mother NOIR" << std::endl;
							if (new_node == new_node->mother->l_child)
							{
								std::cout << "si new_node est a gauche\n";
								new_node = new_node->mother;
								right_rotate(new_node);
							}
							new_node->mother->node_color = black;
							new_node->mother->mother->node_color = red;
							left_rotate(new_node->mother->mother);
						}
					}
					if (new_node == root)
					{
						std::cout << "sdgdddddddddddddddddddddddddddddddddddddd" << std::endl;
						break ;
					}
				}
				root->node_color = black;
				std::cout << "root->key = " << root->key << "\n";
			}

			node<T>	*make_node(const pair &p = pair())
			{
				node<T> *new_node = _malloc_node.allocate(1);
				_malloc_node.construct(new_node, node<T>(p));
				return (new_node);
			}

			void	insert(const pair &p)
			{
				node<T> *new_node = make_node(p);
				
				if (root)
					root->mother = NULL;
				//new_node = node_null;
				new_node->l_child = NULL;
				new_node->r_child = NULL;
				new_node->mother = NULL;
				// new_node->key = newkey;
				new_node->node_color = red;

				node<T>	*tmp = root;
				node<T>	*x = NULL;

				while (tmp != NULL && tmp != node_null)
				{
					x = tmp;
					//if (new_node->_pair.first < tmp->_pair.first)
					std::cout << "\t\t new_node = " << new_node->_pair.first << "  tmp = " << tmp->_pair.first << std::endl;
					if (_comp(new_node->_pair.first, tmp->_pair.first))
					{
						std::cout << "new node plus petit que tmp" << std::endl;
						tmp = tmp->l_child;
					}
					else if (new_node->_pair.first > tmp->_pair.first)
					{
						std::cout << "new node plus grand que tmp" << std::endl;
						tmp = tmp->r_child;
					}
				}
				new_node->mother = x;
				std::cout << "INSERT X = " << x << std::endl;
				if (x == NULL || size == 0)
				{
					root = new_node;
					
					root->node_color = black;
				}
				else if (x && new_node->_pair.first < x->_pair.first)
				{
					std::cout << new_node->key << " EST INFERIEUR A " << x->key << std::endl;
					x->l_child = new_node;
				}
				else if (x && new_node->_pair.first > x->_pair.first)
				{
					std::cout << new_node->key << " EST SUPERIEUR A " << x->key << std::endl;
					x->r_child = new_node;
				}
				else
				{
					std::cout << "x = " << x->key << " new_node = " << new_node->key << std::endl;
					x->r_child = new_node;
					new_node->l_child = node_null;
					new_node->r_child = node_null;
					new_node->node_color = red;
				}
				size++;
				if (!new_node->mother || !new_node->mother->mother)
					return ;
				insert_fix(new_node);
			}
	};
}

#endif
