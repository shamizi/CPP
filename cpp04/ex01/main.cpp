/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:26:44 by shamizi           #+#    #+#             */
/*   Updated: 2022/09/11 18:32:05 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Unknown";
	std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const & rhs)
{
	this->type = rhs.type;
	std::cout << "Copy assignement fonction called" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Default Destructor called" << std::endl;
}

std::string	Animal::getType()const
{
	return (this->type);
}
Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "DOG constructor called" << std::endl;
}

Dog::Dog(Dog const & src)
{
	*this = src;
	std::cout << "DOG copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const & rhs)
{
	this->type = rhs.type;
	std::cout << "DOG Copy assignement fonction called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const & src)
{
	*this = src;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const & rhs)
{
	this->type = rhs.type;
	std::cout << "Cat Copy assignement fonction called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal make sound" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "MEOW !" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "WOOF !" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal make sound" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WRONG MEOW !" << std::endl;
}

WrongAnimal::WrongAnimal()
{
	this->type = "WrongUnknown";
	std::cout << "Wrong Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	*this = src;
	std::cout << "Wrong Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const & rhs)
{
	this->type = rhs.type;
	std::cout << "Wrong Copy assignement fonction called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Default Destructor called" << std::endl;
}

std::string	WrongAnimal::getType()const
{
	return (this->type);
}

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src)
{
	*this = src;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const & rhs)
{
	this->type = rhs.type;
	std::cout << "WrongCat Copy assignement fonction called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(Brain const & src)
{
	*this = src;
	std::cout << "Brain Copy constructor called" << std::endl;
}

Brain &Brain::operator=(Brain const & rhs)
{
	int i = 0;
	while(i++ < 100)
		this->ideas[i] = rhs.ideas[i];
	std::cout << "Brain Copy assignement fonction called" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Default Destructor called" << std::endl;
}

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();
	delete meta;
	delete dog;
	delete cat;
	///////////////////////////////////////////////////////////////////////
/*	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	wrong->makeSound();
	wrongcat->makeSound();

	std::cout << "c'est normal de pas avoir le destructeur du chat dans ce cas, pour montrer que sans le virtual on accede pas au bonne fonction (cf le destructeur et le bon makesound)" << std::endl;
	delete wrong;
	delete wrongcat;*/
}
