/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:30:51 by alsaeed           #+#    #+#             */
/*   Updated: 2024/09/03 12:14:12 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main( int ac, char *av[] ) {

	if ( ac != 2 ) {
		
		std::cerr << "Usage: './btc <input_file>'." << std::endl;
		return -1;
	}

	BitcoinExchange exchange;
	try {
		
		exchange.loadDatabase( "data.csv" );
		exchange.processInputFile( av[1] );
	} catch ( const std::exception& e ) {

		std::cerr << e.what() << std::endl;
		return -2;
	}

	return 0;
}