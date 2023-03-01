/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:06:45 by ldinaut           #+#    #+#             */
/*   Updated: 2023/03/01 15:17:48 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TPP
#define MAP_TPP

namespace ft
{
					/*****CONS/DESTRUCTOR*****/
	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map()
	{
		// std::cout << "map construct" << std::endl;
		//_tree = RBT<>();
		_size = 0;
	}

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::~map()
	{
		// std::cout << "map destruct" << std::endl;
	}
					/*****OPERATOR OVERLOAD******/

					/*****METHODES*****/

	template <class Key, class T, class Compare, class Alloc>
	size_t	map<Key, T, Compare, Alloc>::size() const
	{
		return (_size);
	}

	template <class Key, class T, class Compare, class Alloc>
	size_t	map<Key, T, Compare, Alloc>::max_size() const
	{
		return (_tree._malloc.max_size());
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
		if (_tree.searchKey(_tree.getRoot(), k) == NULL)
			return (0);
		return (1);
	}

	template <class Key, class T, class Compare, class Alloc>
	size_t	map<Key, T, Compare, Alloc>::erase(const key_type &k)
	{
		node *tmp = _tree.searchKey(_tree.getRoot(), k);

		if (tmp != NULL)
		{
			_tree.rb_delete(k);
			_tree.getAlloc().destroy(tmp);
			_tree.getAlloc().deallocate(tmp, 1);
			return (1);
		}
		return (0);
		
		//return (_tree.rb_delete(k));
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

	// template <class Key, class T, class Compare, class Alloc>
	// void map<Key, T, Compare, Alloc>::swap(map<Key, T, Compare, Alloc> &x)
	// {
	// }

					/*****NON-MEMBER OVERLOAD*****/
	// template <class Key, class T, class Compare, class Alloc>
	// void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y)
	// {
	// 	x.swap(y);
	// }
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
