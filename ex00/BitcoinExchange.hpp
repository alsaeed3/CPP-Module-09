/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:30:49 by alsaeed           #+#    #+#             */
/*   Updated: 2024/09/03 12:14:12 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <cstdlib>

class BitcoinExchange {

	private:
		std::map<std::string, double> database;


	public:	
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange const &src );
		BitcoinExchange &operator=( BitcoinExchange const &src );
		~BitcoinExchange();

		void	loadDatabase( std::string const &fileName );
		void	processInputFile( std::string const &fileName );
		void	processLine( std::string const &line );
		double	getExchangeRate( std::string const &date ) const;
		bool	isValidDate( std::string const &date ) const;
		bool	isValidValue( double value ) const;
		bool	isLeapYear( int year ) const;

};

#endif
	