/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:31:46 by shamizi           #+#    #+#             */
/*   Updated: 2022/12/06 13:36:29 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <stdexcept>
class Base
{
	public :
		virtual ~Base();
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

#endif
