/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:23:23 by alsaeed           #+#    #+#             */
/*   Updated: 2024/08/27 10:57:29 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <fstream>
# include <sstream>

class RPN {

	private:
		std::stack<int> operands;

		bool	isOperator( char c );
		void	performOperation( char op );

	public:
		RPN( void );
		RPN( RPN const &src );
		RPN &operator=( RPN const &rhs );
		~RPN( void );

		int	calculate( std::string const &expression );
};

#endif