/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:05:06 by alsaeed           #+#    #+#             */
/*   Updated: 2024/08/27 11:10:44 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int ac, char *av[] ) {

	if ( ac != 2 ) {
		
		std::cerr << "Invalid number of arguments." << std::endl;
		return -1;
	}

	RPN	calculator;
	try {
		
		int result = calculator.calculate( av[1] );
		std::cout << result << std::endl;
	} catch ( const std::exception &e ) {
		
		std::cerr << "Error: " << e.what() << std::endl;
		return -2;
	}

	return 0;
}