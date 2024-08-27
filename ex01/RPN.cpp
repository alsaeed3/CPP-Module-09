/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:23:25 by alsaeed           #+#    #+#             */
/*   Updated: 2024/08/27 11:04:34 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ) {
	
	return;
}

RPN::RPN( RPN const &src ) {

	this->operands = src.operands;

	return;
}

RPN &RPN::operator=( RPN const &rhs ) {

	if ( this != &rhs ) {

		this->operands = rhs.operands;
	}

	return *this;
}

RPN::~RPN( void ) {

	return;
}

bool	RPN::isOperator( char c ) {

	return c == '+' || c == '-' || c == '*' || c == '/';
}

void	RPN::performOperation( char op ) {

	if ( this->operands.size() < 2 ) {

		throw std::runtime_error( "Not Enough Operands for Operation" );
	}

	int b = this->operands.top();
	this->operands.pop();
	int a = this->operands.top();
	this->operands.pop();

	switch ( op ) {

		case '+':
			operands.push( a + b );
			break;
		case '-':
			operands.push( a - b );
			break;
		case '*':
			operands.push( a * b );
			break;
		case '/':
			if ( b == 0 ) {
				
				throw std::runtime_error("Division by Zero");
			}
			operands.push( a / b );
			break;
	}

	return;
}

int	RPN::calculate( std::string const &expression ) {

	std::istringstream	iss( expression );
	std::string			token;

	while ( iss >> token ) {

		if ( token.length() == 1 && isOperator(token[0]) ) {
			
			performOperation( token[0] );
		} else {

			int num;
			std::istringstream(token) >> num;	
			if ( num < 0 || num > 9 ) {
				
				throw std::runtime_error( "Invalid number: " + token );
			}
			operands.push( num );
		}
	}

	if ( operands.size() != 1 ) {
		
		throw std::runtime_error( "Invalid expression");
	}

	return operands.top();
}

