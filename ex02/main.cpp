/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:18:01 by alsaeed           #+#    #+#             */
/*   Updated: 2024/09/01 00:32:36 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

using std::list;
using std::pair;
using std::vector;

template<typename T>
void	print_container( T &con );

int	main( int ac, char *av[] ) {

	if ( ac < 2 ) {

		std::cout << "Usage: ./PmergeMe <numbers to sort>" << std::endl;
		return -1;
	}

	try {

		clock_t	list_start_time = clock();		
		list<int>	numbers_list = PmergeMe<list<int>, list<pair<int, int> > >::parseNumbers( ac, av );
		list<int>	list_cpy = numbers_list;
		list<int>	sorted_list = PmergeMe<std::list<int>, std::list<std::pair<int, int> > >::FJMI( numbers_list );
		clock_t list_end_time = clock() - list_start_time;
		double	list_sort_time = list_end_time / (double) CLOCKS_PER_SEC * 1e3;

		clock_t	vector_start_time = clock();		
		vector<int>	numbers_vector = PmergeMe<vector<int>, vector<pair<int, int> > >::parseNumbers( ac, av );
		vector<int>	sorted_vector = PmergeMe<vector<int>, vector<pair<int, int> > >::FJMI( numbers_vector );
		clock_t vector_end_time = clock() - vector_start_time;
		double	vector_sort_time = vector_end_time / (double) CLOCKS_PER_SEC * 1e3;

		std::cout << "Before: ";
		print_container( list_cpy );
		std::cout << "After: ";
		print_container( sorted_list );

		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time to process a range of " << list_cpy.size() << " elements with std::list : " << list_sort_time << " ms" << std::endl;

		std::cout << "Time to process a range of " << list_cpy.size() << " elements with std::vector : " << vector_sort_time << " ms" << std::endl;
	} catch( std::runtime_error const &e ) {

		std::cout << e.what() << std::endl;
		return -2;
	}

	return 0;
}

template<typename T>
void	print_container( T &con ) {

	for ( typename T::iterator it = con.begin(); it != con.end(); it++ ) {

		std::cout << *it << " ";
	}

	std::cout << std::endl;

	return;
}