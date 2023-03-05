/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:48:46 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/18 14:11:24 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
	protected :
		std::string type;
	public :
		//constructeur
		Animal();
		//constructeur par cope
		Animal(Animal const & src);
		//surchage operateur =
		Animal & operator= (Animal const & rhs);
		//destructeur
		virtual ~Animal();
		//fonction membre
		virtual void	makeSound() const;
		std::string getType() const;
};

class Dog : public Animal
{
	public :
		void	makeSound() const;
		Dog();
		Dog(Dog const & src);
		Dog & operator= (Dog const & rhs);
		~Dog();
};

class Cat : public Animal
{
	public :
		void	makeSound() const;
		Cat();
		Cat(Cat const & src);
		Cat & operator= (Cat const & rhs);
		~Cat();
};

class WrongAnimal{
	protected :
		std::string type;
	public :
		//constructeur
		WrongAnimal();
		//constructeur par cope
		WrongAnimal(WrongAnimal const & src);
		//surchage operateur =
		WrongAnimal & operator= (WrongAnimal const & rhs);
		//destructeur
		~WrongAnimal();
		//fonction membre
		void	makeSound() const;
		std::string getType() const;
};

class WrongCat : public WrongAnimal
{
	public :
		void	makeSound() const;
		WrongCat();
		WrongCat(WrongCat const & src);
		WrongCat & operator= (WrongCat const & rhs);
		~WrongCat();
};

#endif
