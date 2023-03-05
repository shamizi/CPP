/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:17:46 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/30 12:36:55 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
	    std::cout << "-----ligne ajouter au main de test donner pour prouver que je rempli bien le tableau-----" << std::endl;
	    std::cout << "valeur de numbers[10] :" << numbers[10] << std::endl;
	    std::cout << "-------------test de la fonction size demander--------" << std::endl;
	    std::cout << "valeur de retour : " << numbers.size() << std::endl;
	    std::cout << "------fin de la ligne que j'ai ajouter-------" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try //-2 out of range donc va fail;
    {
        numbers[-2] = 0; //possible de mettre un nombre strictement inferieur a 750 ici
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try // max val out of range donc fail
    {
        numbers[MAX_VAL] = 0; //max val - 1 pour faire reussir
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
