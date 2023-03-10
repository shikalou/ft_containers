/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:06:45 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/10 17:55:05 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TPP
#define MAP_TPP

namespace ft
{
					/*****CONS/DESTRUCTOR*****/
	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const key_compare &comp, const allocator_type &alloc)
	{
		// std::cout << "map construct" << std::endl;
		_size = 0;
		_end = _tree.make_node();
		_comp = _tree.getComp();
		_malloc = _tree.getAlloc();
		(void)comp;
		(void)alloc;
	}

	template <class Key, class T, class Compare, class Alloc>
	template <class InputIterator>
	map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc)
	{
		(void)comp;
		(void)alloc;
		_size = 0;
		_end = _tree.make_node();
		_comp = _tree.getComp();
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

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const map &copy)
	{
		_size = copy._size;
		_end = _tree.make_node();
		_comp = _tree.getComp();
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

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::~map()
	{
		// std::cout << "map destruct" << std::endl;
	}
					/*****OPERATOR OVERLOAD******/
	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>&	map<Key, T, Compare, Alloc>::operator=(const map &egal)
	{
		this->_size = egal._size;
	}

	template <class Key, class T, class Compare, class Alloc>
	T	&map<Key, T, Compare, Alloc>::operator[](const key_type &k)
	{
		node *toto = _tree.maximum(_tree.getRoot(), _end);
		toto->r_child = NULL;
		insert(ft::make_pair(k, T()));
		node *tmp = _tree.searchKey(_tree.getRoot(), k);
		node *titi = _tree.maximum(_tree.getRoot(), _end);
		titi->r_child = _end;
		_end->mother = titi;
		return (tmp->_pair.second);
	}

					/*****METHODES*****/

	template <class Key, class T, class Compare, class Alloc>
	size_t	map<Key, T, Compare, Alloc>::size() const
	{
		return (_size);
	}

	template <class Key, class T, class Compare, class Alloc>
	size_t	map<Key, T, Compare, Alloc>::max_size() const
	{
		return (_malloc.max_size());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	map<Key, T, Compare, Alloc>::empty() const
	{
		if (_size == 0)
			return (true);
		return (false);
	}

	template <class Key, class T, class Compare, class Alloc>
	size_t	map<Key, T, Compare, Alloc>::count(const key_type &k) const
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

	template <class Key, class T, class Compare, class Alloc>
	size_t	map<Key, T, Compare, Alloc>::erase(const key_type &k)
	{
		node *toto = _tree.maximum(_tree.getRoot(), _end);
		toto->r_child = NULL;

		node *tmp = _tree.searchKey(_tree.getRoot(), k);

		if (tmp != NULL)
		{
			_tree.rb_delete(k);
			node *titi = _tree.maximum(_tree.getRoot(), _end);
			titi->r_child = _end;
			_end->mother = titi;
			// _malloc.destroy(tmp);
			// _malloc.deallocate(tmp, 1);
			return (1);
		}
		return (0);
	}

	template <class Key, class T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>::erase(iterator position)
	{
		node *toto = _tree.maximum(_tree.getRoot(), _end);
		toto->r_child = NULL;

		node *tmp = _tree.searchKey(_tree.getRoot(), (*position).first);

		if (tmp != NULL)
		{
			_tree.rb_delete((*position).first);
			// _malloc.destroy(tmp);
			node *titi = _tree.maximum(_tree.getRoot(), _end);
			titi->r_child = _end;
			_end->mother = titi;
			// _malloc.deallocate(tmp, 1);
		}
	}

	template <class Key, class T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
	{
		iterator first = begin();
		iterator last = end();
		while (first != last)
		{
			erase(first);
			first++;
		}
	}

	template <class Key, class T, class Compare, class Alloc>
	Alloc	map<Key, T, Compare, Alloc>::get_allocator() const
	{
		return (_tree.getAlloc());
	}

	template <class Key, class T, class Compare, class Alloc>
	Compare	map<Key, T, Compare, Alloc>::key_comp() const
	{
		return (_tree.getComp());
	}

	template <class Key, class T, class Compare, class Alloc>
	void map<Key, T, Compare, Alloc>::swap(map<Key, T, Compare, Alloc> &x)
	{
		RBT<key_type, mapped_type, value_type, key_compare, Alloc> tmp_tree = x._tree;
		size_type	tmp_size = x._size;
		node		*tmp_end = x._end;
		allocator_type	tmp_malloc = x._malloc;
		Compare			tmp_comp = x._comp;

		x._tree = _tree;
		x._size = _size;
		x._end = _end;
		x._malloc = _malloc;
		x._comp = _comp;

		_tree = tmp_tree;
		_size = tmp_size;
		_end = tmp_end;
		_malloc = tmp_malloc;
		_comp = tmp_comp;
	}

					/*****NON-MEMBER OVERLOAD*****/
	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y)
	{
		x.swap(y);
	}
						/*RELATIONAL OPERATORS*/
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

}

#endif
