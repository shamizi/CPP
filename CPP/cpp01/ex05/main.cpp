/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:11:35 by shamizi           #+#    #+#             */
/*   Updated: 2022/06/13 15:19:37 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7Xl-double-cheese-triple-pickle-special-ketchup burger. I really do!";
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!";
	std::cout << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month";
	std::cout << std::endl;
}
void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"debug", "info", "warning", "error"};
	void	(Harl::*fonction[4])() = {&Harl::debug, &Harl::info, &Harl::warning , &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			(this->*fonction[i])();
	}
	return ;
}

Harl::Harl(void)
{}

Harl::~Harl(void)
{}
int	main(void)
{
	Harl harl;

	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
	std::cout <<  "prochaine ligne doit etre le delimiteur" << std::endl;
	harl.complain("ne doit rien afficher");
	std::cout <<  "delimitateur" << std::endl;
}
