/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:51:50 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/10 17:59:20 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "rbt.hpp"
#include "pair.hpp"
#include "make_pair.hpp"
#include "lexicographical_compare.hpp"
#include "equal.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef typename ft::RBT<key_type, mapped_type, value_type, key_compare, Alloc>::template node<key_type> node;
			typedef Alloc										allocator_type;
			typedef map_iterator<value_type, node>				iterator;
			typedef map_iterator<const value_type, node>		const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef size_t										size_type;

		class value_compare
		{
			protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {}
			public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};
				/*CONS/DESTRUCTOR*/
			map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			map(const map &copy);
			~map();
				/*OPERATOR OVERLOAD*/
			map&			operator=(const map &egal);
			mapped_type&	operator[](const key_type &k);

				/*METHODES*/
			//void					clear(); // A FAIRE
			size_type				count(const key_type &k) const;
			bool					empty() const;
			size_type				erase(const key_type &k);
			void					erase(iterator position);
			void					erase(iterator first, iterator last);
			allocator_type			get_allocator() const;
			key_compare				key_comp() const;
			size_type				max_size() const;
			size_type				size() const;
			iterator				begin(){return(iterator(_tree.minimum(_tree.getRoot())));}
			const_iterator			begin() const{return (const_iterator(_tree.minimum(_tree.getRoot())));}
			iterator				end(){return (iterator(_end));}
			const_iterator			end() const{ return (const_iterator(_end));}
			reverse_iterator		rbegin(){ return (reverse_iterator(_end)); }
			const_reverse_iterator	rbegin() const{ return (const_reverse_iterator(_end)); }
			reverse_iterator		rend(){ return (reverse_iterator(_tree.minimum(_tree.getRoot()))); }
			const_reverse_iterator	rend() const{ return (const_reverse_iterator(_tree.minimum(_tree.getRoot()))); }
			void					swap(map &x); // A FAIRE
			pair<iterator, bool>	insert(const value_type &val)
			{
				node *toto = _tree.maximum(_tree.getRoot(), _end);
				toto->r_child = NULL;
				if (!_tree.searchKey(_tree.getRoot(), val.first))
				{
					_size++;
					_tree.insert(val);
					node *tmp = _tree.searchKey(_tree.getRoot(), val.first);
					node *titi = _tree.maximum(_tree.getRoot(), _end);
					titi->r_child = _end;
					_end->mother = titi;
					return (ft::make_pair<iterator, bool>(iterator(tmp), true));
				}
				node *tmp = _tree.searchKey(_tree.getRoot(), val.first);
				return (ft::make_pair<iterator, bool>(iterator(tmp), false));
			}
			iterator				insert(iterator position, const value_type &val)
			{
				(void)position;
				node *toto = _tree.maximum(_tree.getRoot(), _end);
				toto->r_child = NULL;
				insert(val);
				node *tmp = _tree.searchKey(_tree.getRoot, val.first);
				node *titi = _tree.maximum(_tree.getRoot(), _end);
				titi->r_child = _end;
				_end->mother = titi;
				return (iterator(tmp));
			}
			iterator				lower_bound(const key_type &k)
			{
				iterator	first = begin();
				iterator	last = end();

				while (first != last)
				{
					if (!_comp(first->first, k))
						return (first);
					first++;
				}
				return (last);
			}
			const_iterator			lower_bound(const key_type &k) const
			{
				const_iterator first = begin();
				const_iterator last = end();

				while (first != last)
				{
					if (!_comp(first->first, k))
						return (first);
					first++;
				}
				return (last);
			}
			iterator				upper_bound(const key_type &k)
			{
				iterator	first = begin();
				iterator	last = end();

				while (first != last)
				{
					if (_comp(k, first->first))
						return (first);
					first++;
				}
				return (last);
			}
			const_iterator			upper_bound(const key_type &k) const
			{
				const_iterator first = begin();
				const_iterator last = end();

				while (first != last)
				{
					if (_comp(k, first->first))
						return (first);
					first++;
				}
				return (last);
			}
			pair<iterator,iterator>	equal_range(const key_type &k)
			{
				iterator upper;
				iterator lower;

				upper = upper_bound(k);
				lower = lower_bound(k);
				return (make_pair(lower, upper));
			}
			pair<const_iterator,const_iterator>	equal_range(const key_type &k) const
			{
				const_iterator upper;
				const_iterator lower;

				upper = upper_bound(k);
				lower = lower_bound(k);
				return (make_pair(lower, upper));
			}
			
			// iterator							find(const key_type &k); // A FAIRE
			// const_iterator						find(const key_type &k) const; // A FAIRE
			// template <class InputIterator>
			// void								insert(InputIterator first, InputIterator last); // A FAIRE

			value_compare						value_comp() const; // A FAIRE

			RBT<key_type, mapped_type, value_type, key_compare, Alloc>	_tree;
		private:
			size_type		_size;
			node			*_end;
			allocator_type	_malloc;
			Compare			_comp;
	};

	template <class Key, class T, class Compare, class Alloc>
	void	swap(map<Key,T,Compare,Alloc> &x, map<Key,T,Compare,Alloc> &y);

	template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>=(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs);
}

#include "map.tpp"

#endif
