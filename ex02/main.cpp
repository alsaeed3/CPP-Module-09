/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:18:01 by alsaeed           #+#    #+#             */
/*   Updated: 2024/08/31 01:43:24 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main( int ac, char *av[] ) {

	if ( ac < 2 ) {

		std::cout << "Usage: ./PmergeMe <numbers to sort>" << std::endl;
		return -1;
	}

	try {
		
		PmergeMe.
	} catch( std::runtime_error const &e ) {

		std::cout << e.what() << std::endl;
		return -2;
	}

	return 0;
}