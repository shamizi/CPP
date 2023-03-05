/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:29:10 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/28 13:42:06 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data data;
	data.str1 = "test";
	data.n = 42;

	std::cout << "----------------serialize-----------" << std::endl;
	uintptr_t test = serialize(&data);
	std::cout << "0x" << std::hex << test << std::endl;
	std::cout << &data << std::endl;

	std::cout << "---------deserialize--------------" << std::endl;
	Data *raw = deserialize(test);
	std::cout << std::dec << raw << std::endl;
	std::cout << raw->n << std::endl;
	std::cout << raw->str1 << std::endl;
	return 0;
}
