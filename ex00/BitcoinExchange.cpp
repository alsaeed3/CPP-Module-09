/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:30:54 by alsaeed           #+#    #+#             */
/*   Updated: 2024/08/25 21:34:11 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( std::string const &inputFile ) {

	this->rate = readFile( "data.csv" );
	this->input = readFile( inputFile );

	return;
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &src ) {

	this->rate = src.rate;
	this->input = src.input;

	return;
}

BitcoinExchange &BitcoinExchange::operator=( BitcoinExchange const &rhs ) {

	if ( *this != rhs ) {

		*this = rhs;
	}
	
	return *this;
}

BitcoinExchange::~BitcoinExchange() {

	return;
}

std::map<std::string, int> BitcoinExchange::readFile( std::string const &file ) const {



	return;
}
