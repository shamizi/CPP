/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:48:46 by shamizi           #+#    #+#             */
/*   Updated: 2022/10/25 13:55:35 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
//proteger le creaton de brain et delete brain dans destructeur de l'animal !

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

class Brain
{
	protected :
		std::string ideas[100];
	public :
		Brain();
		Brain(Brain const & src);
		Brain & operator=(Brain const & rhs);
		~Brain();
};

class Dog : public Animal
{
	private :
		Brain *brain;
	public :
		void	makeSound() const;
		Dog();
		Dog(Dog const & src);
		Dog & operator= (Dog const & rhs);
		~Dog();
};

class Cat : public Animal
{
	private :
		Brain *brain;
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
