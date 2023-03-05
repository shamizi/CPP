/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:55:02 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/30 14:31:48 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <exception>

/*class	Error : public std::exception
  {
  public :
  virtual const char *what() const throw()
  {
  return ("not find");
  }
  };
 */
	template <typename T>
void	easyfind(T t, int n)
{
	typename T::iterator it;
	it = std::find(t.begin(), t.end(), n);
	if (it == t.end())
		std::cout << "Element not found" << std::endl;
	else
		std::cout << "Element found : " << *it << " at position : " << std::distance(t.begin(), it) << std::endl;
}

#endif
