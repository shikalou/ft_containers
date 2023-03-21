/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:18:17 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/21 21:05:27 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_TPP
#define SET_TPP

namespace ft
{
					/*****CONS/DESTRUCTOR*****/
	template <class Key, class Compare, class Alloc>
	set<Key, Compare, Alloc>::set(const key_compare &comp, const allocator_type &alloc)
	{
		// //std::cout << "set construct" << std::endl;
		_size = 0;
		_end = _tree.make_node();
		_comp = comp;
		_malloc = _tree.getAlloc();
		(void)alloc;
	}

	template <class Key, class Compare, class Alloc>
	template <class InputIterator>
	set<Key, Compare, Alloc>::set(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc)
	{
		(void)alloc;
		_size = 0;
		_end = _tree.make_node();
		_comp = comp;
		_malloc = _tree.getAlloc();
		while (first != last)
		{
			insert(*first);
			first++;
		}
		node *titi = _tree.maximum(_tree.getRoot(), _end);
		titi->r_child = _end;
		_end->mother = titi;
	}

	template <class Key, class Compare, class Alloc>
	set<Key, Compare, Alloc>::set(const set &copy)
	{
		_size = 0;
		_end = _tree.make_node();
		_comp = copy._comp;
		_malloc = _tree.getAlloc();
		const_iterator first = copy.begin();
		const_iterator last = copy.end();
		while (first != last)
		{
			insert(*first);
			first++;
		}
		node *titi = _tree.maximum(_tree.getRoot(), _end);
		titi->r_child = _end;
		_end->mother = titi;
	}

	template <class Key, class Compare, class Alloc>
	set<Key, Compare, Alloc>::~set()
	{
		// //std::cout << "set destruct" << std::endl;
		//std::cout << "NOTE A PAS DETRUIRE END !!!!!!!11  " << _end << std::endl;
		clear();
		_tree.supp_end(_end);
		_tree.supp_end(_tree.node_null);
	}
					/*****OPERATOR OVERLOAD******/
	template <class Key, class Compare, class Alloc>
	set<Key, Compare, Alloc>&	set<Key, Compare, Alloc>::operator=(const set &egal)
	{
		clear();
		const_iterator first = egal.begin();
		const_iterator last = egal.end();
		insert(first, last);
		return (*this);
	}

	template <class Key, class Compare, class Alloc>
	Key	&set<Key, Compare, Alloc>::operator[](const key_type &k)
	{
		insert(ft::make_pair(k, Key()));
		node *toto = _tree.maximum(_tree.getRoot(), _end);
		if (toto)
			toto->r_child = NULL;
		node *tmp = _tree.searchKey(_tree.getRoot(), k);
		node *titi = _tree.maximum(_tree.getRoot(), _end);
		titi->r_child = _end;
		_end->mother = titi;
		return (tmp->_pair->second);
	}

					/*****METHODES*****/

	template <class Key, class Compare, class Alloc>
	size_t	set<Key, Compare, Alloc>::size() const
	{
		return (_size);
	}

	template <class Key, class Compare, class Alloc>
	size_t	set<Key, Compare, Alloc>::max_size() const
	{
		return (_malloc.max_size());
	}

	template <class Key, class Compare, class Alloc>
	bool	set<Key, Compare, Alloc>::empty() const
	{
		if (_size == 0)
			return (true);
		return (false);
	}

	template <class Key, class Compare, class Alloc>
	size_t	set<Key, Compare, Alloc>::count(const key_type &k) const
	{

		node *toto = _tree.maximum(_tree.getRoot(), _end);
		toto->r_child = NULL;

		if (_tree.searchKey(_tree.getRoot(), k) == NULL)
		{
			node *titi = _tree.maximum(_tree.getRoot(), _end);
			titi->r_child = _end;
			_end->mother = titi;
			return (0);
		}
		node *titi = _tree.maximum(_tree.getRoot(), _end);
		titi->r_child = _end;
		_end->mother = titi;
		return (1);
	}

	template <class Key, class Compare, class Alloc>
	size_t	set<Key, Compare, Alloc>::erase(const key_type &k)
	{
		node *toto = _tree.maximum(_tree.getRoot(), _end);
		//std::cout << "on suppr le max : " << toto << std::endl;
		if (toto)
			toto->r_child = NULL;

		node *tmp = _tree.searchKey(_tree.getRoot(), k);

		if (tmp != NULL)
		{
			_tree.rb_delete(k);
			node *titi = _tree.maximum(_tree.getRoot(), _end);
			if (!titi)
			{
				_size--;
				_tree.supp_end(tmp);
				return (1);
			}
			//std::cout << "dans erase titi = " << titi << std::endl;
			titi->r_child = _end;
			_end->mother = titi;
			// _malloc.destroy(tmp->p);
			// _malloc.deallocate(tmp, 1);
			_size--;
			_tree.supp_end(tmp);
			return (1);
		}
		node *titi = _tree.maximum(_tree.getRoot(), _end);
		titi->r_child = _end;
		_end->mother = titi;
		return (0);
	}

	template <class Key, class Compare, class Alloc>
	void	set<Key, Compare, Alloc>::erase(iterator position)
	{
		node *toto = _tree.maximum(_tree.getRoot(), _end);
		if (!toto)
			return ;
		toto->r_child = NULL;
		node *tmp = _tree.searchKey(_tree.getRoot(), (*position));
		if (tmp != NULL)
		{
			_tree.rb_delete((*position));
			// _malloc.destroy(tmp);
			// _malloc.deallocate(tmp, 1);
			node *titi = _tree.maximum(_tree.getRoot(), _end);
			if (!titi)
			{
				_size--;
				_tree.supp_end(tmp);
				return ;
			}
			titi->r_child = _end;
			_end->mother = titi;
			//std::cout << " FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF size = " << _size << "  " << tmp->key << std::endl;
			_tree.supp_end(tmp);
			_size--;
		}
		toto = _tree.maximum(_tree.getRoot(), _end);
		toto->r_child = _end;
	}

	template <class Key, class Compare, class Alloc>
	void	set<Key, Compare, Alloc>::erase(iterator first, iterator last)
	{
		int flast = 0;
		if (first == begin() && last == end())
		{
			clear();
			return ;
		}
		if (last == end())
		{
			flast++;
			last--;
		}
		node *toto = _tree.maximum(_tree.getRoot(), _end);
		if (!toto)
			return ;
		toto->r_child = NULL;
		if (flast)
		{
			while (first != last)
			{
				node *tmp = _tree.searchKey(_tree.getRoot(), (*first));
				_tree.rb_delete((*first));
				//real_print(_tree.getRoot(), 0, _tree);
				first++;
				_size--;
				_tree.supp_end(tmp);
			}
			if (flast)
			{
				node *tmp = _tree.searchKey(_tree.getRoot(), (*first));
				_tree.rb_delete((*first));
				////std::cout << "DANS LA BOUCLE ERASE (IT,IT) " << (*tmp) << std::endl;
				//real_print(_tree.getRoot(), 0, _tree);
				_size--;
				_tree.supp_end(tmp);
			}
		}
		else
		{

			node	*l = NULL;
		//	std::cout << "AVANT WHILE first: " << (*first) << "\n";
		if (_flower)
		{
			l = _tree.searchKey(_tree.getRoot(), (*first));
			++first;
			while (last != first)
			{
				node *tmp = _tree.searchKey(_tree.getRoot(), (*first));
				if (!tmp)
				{
					node *titi = _tree.maximum(_tree.getRoot(), _end);
					titi->r_child = _end;
					_end->mother = titi;
					return ;
				}
				++first;
				_tree.rb_delete(*tmp->_pair);
				_size--;
				_tree.supp_end(tmp);
			}
		//		node *tmp = _tree.searchKey(_tree.getRoot(), (*first));
		//		_tree.rb_delete((*first));
				////std::cout << "DANS LA BOUCLE ERASE (IT,IT) " << (*tmp) << std::endl;
				//real_print(_tree.getRoot(), 0, _tree);
		//		_size--;
		//		_tree.supp_end(tmp);
				_tree.rb_delete(*l->_pair);
				////std::cout << "DANS LA BOUCLE ERASE (IT,IT) " << (*tmp) << std::endl;
				//real_print(_tree.getRoot(), 0, _tree);
				_size--;
				_tree.supp_end(l);
		}
		
		else
		{
			//std::cout << "LAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaa\n";
			last--;
			l = _tree.searchKey(_tree.getRoot(), (*last));
			last--;
				//	std::cout << "AVANT WHILE first: " << (*first) << "\n";
			while (last != first)
			{
		
				// std::cout << "DANS LA BOUCLE ERASE (IT,IT) " << (*first) << std::endl;
				// std::cout << "DANS LA BOUCLE ERASE (IT,IT) " << (*last) << std::endl;
				node *tmp = _tree.searchKey(_tree.getRoot(), (*last));
				if (!tmp)
				{
					node *titi = _tree.maximum(_tree.getRoot(), _end);
					titi->r_child = _end;
					_end->mother = titi;
					return ;
				}
				_tree.rb_delete(*tmp->_pair);
				--last;
				// std::cout << "JDHKFJHKJFHSKDJFHSDDANS LA BOUCLE ERASE (IT,IT) " << (*last) << std::endl;
				_size--;
				_tree.supp_end(tmp);
			}
				node *tmp = _tree.searchKey(_tree.getRoot(), (*first));
				_tree.rb_delete((*first));
				////std::cout << "DANS LA BOUCLE ERASE (IT,IT) " << (*tmp) << std::endl;
				//real_print(_tree.getRoot(), 0, _tree);
				_size--;
				_tree.supp_end(tmp);
				_tree.rb_delete(*l->_pair);
				////std::cout << "DANS LA BOUCLE ERASE (IT,IT) " << (*tmp) << std::endl;
				//real_print(_tree.getRoot(), 0, _tree);
				_size--;
				_tree.supp_end(l);
		}
		}
		_flower = false;
		node *titi = _tree.maximum(_tree.getRoot(), _end);
		if (!titi)
			return ;
		titi->r_child = _end;
		_end->mother = titi;
	}

	template <class Key, class Compare, class Alloc>
	Alloc	set<Key, Compare, Alloc>::get_allocator() const
	{
		return (_tree.getAlloc());
	}

	template <class Key, class Compare, class Alloc>
	Compare	set<Key, Compare, Alloc>::key_comp() const
	{
		return (_comp);
	}

	template <class Key, class Compare, class Alloc>
	void set<Key, Compare, Alloc>::swap(set<Key, Compare, Alloc> &x)
	{
		RBT_SET<key_type, value_type, key_compare, Alloc> tmp_tree = x._tree;
		size_type		tmp_size = x._size;
		node			*tmp_end = x._end;
		allocator_type	tmp_malloc = x._malloc;
		Compare			tmp_comp = x._comp;
		node			*tmp_node_null = x._tree.node_null;

		x._tree = _tree;
		x._size = _size;
		x._end = _end;
		x._malloc = _malloc;
		x._comp = _comp;
		x._tree.node_null = _tree.node_null;

		_tree = tmp_tree;
		_size = tmp_size;
		_end = tmp_end;
		_malloc = tmp_malloc;
		_comp = tmp_comp;
		_tree.node_null = tmp_node_null;
	}
	template <class Key, class Compare, class Alloc>
	void set<Key, Compare, Alloc>::clear()
	{
		while (_tree.getRoot() != NULL && _size)
		{
			//real_print(_tree.getRoot(), 0, _tree);
			//std::cout << "DANS CLEAR    " << _size << std::endl;
			erase(_tree.getRoot()->key);
		}
	}

					/*****NON-MEMBER OVERLOAD*****/
	template <class Key, class Compare, class Alloc>
	void swap(set<Key, Compare, Alloc> &x, set<Key, Compare, Alloc> &y)
	{
		x.swap(y);
	}
						/*RELATIONAL OPERATORS*/
	template <class Key, class Compare, class Alloc>
	bool operator==(const set<Key, Compare, Alloc> &lhs, const set<Key, Compare, Alloc> &rhs)
	{
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}

	template <class Key, class Compare, class Alloc>
	bool operator!=(const set<Key, Compare, Alloc> &lhs, const set<Key, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class Compare, class Alloc>
	bool operator<(const set<Key, Compare, Alloc> &lhs, const set<Key, Compare, Alloc> &rhs)
	{
		return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class Compare, class Alloc>
	bool operator<=(const set<Key, Compare, Alloc> &lhs, const set<Key, Compare, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <class Key, class Compare, class Alloc>
	bool operator>(const set<Key, Compare, Alloc> &lhs, const set<Key, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>=(const set<Key, Compare, Alloc> &lhs, const set<Key, Compare, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

}

#endif
