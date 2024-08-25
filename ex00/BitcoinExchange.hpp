/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:30:49 by alsaeed           #+#    #+#             */
/*   Updated: 2024/08/25 21:26:57 by alsaeed          ###   ########.fr       */
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
#include <sstream>
#include <cmath>

class BitcoinExchange {

	private:
		std::map<std::string, int> rate;
		std::map<std::string, int> input;

		BitcoinExchange();

	public:	
		BitcoinExchange( std::string const &inputFile );
		BitcoinExchange( BitcoinExchange const &src );
		BitcoinExchange &operator=( BitcoinExchange const &src );
		~BitcoinExchange();

		std::map<std::string, int> readFile( std::string const &file ) const;
		
};

#endif
	