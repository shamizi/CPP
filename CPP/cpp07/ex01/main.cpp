/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:40:54 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/30 12:22:12 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

//class bonus pour tester le code, n'hesites pas a la decommenter

class Awesome
{
	public :
		Awesome(void) : _n(42){return;}
		int	get(void) const {return this->_n;}
	private :
		int _n;
};

std::ostream & operator<<(std::ostream &o, Awesome const &rhs)
{o << rhs.get(); return o;}


int	main(void)
{
	char 	tab[] = "abcdef";
	int	inttab[] = {0, 1, 2, 3, 4};
	Awesome classtab[5];
	std::string	str[3] = {"blue", "red", "yellow"};
	std::cout << "-----------print---------------" << std::endl;
	std::cout << "-----------des char------------" << std::endl;
	::iter<char>(tab, 6, print);
	std::cout << "-----------des int------------" << std::endl;
	::iter<int>(inttab, 5, print);
	std::cout << "-----------des std::string------------" << std::endl;
	::iter<std::string>(str, 3, print);
	std::cout << "--------des element d'une classe-------" << std::endl;
	::iter<Awesome>(classtab, 5, print);
	return 0;
}
/*
class Awesome
{
public:
Awesome( void ) : _n( 42 ) { return; }
int get( void ) const { return this->_n; }
private:
int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }
int main() {
int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
Awesome tab2[5];
iter( tab, 5, print );
iter( tab2, 5, print );
return 0;
}*/
