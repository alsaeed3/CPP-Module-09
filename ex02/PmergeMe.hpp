/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:35:27 by alsaeed           #+#    #+#             */
/*   Updated: 2024/08/31 00:36:41 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGE_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <iterator>
# include <sstream>
# include <utility>
# include <algorithm>

typedef std::pair<int, bool> straggler_t;

#define IS_ODD(x) ((x.size()) % 2 != 0)

template<typename N, typename P>
class PmergeMe {

	private:
		PmergeMe( void );
		PmergeMe( PmergeMe const &src );
		PmergeMe &operator=( PmergeMe const &rhs );
		~PmergeMe( void );

		static straggler_t	findStraggler( N &numbers );
		static P			mergeSortSeconds( P &pairs );
		static void			extractLargest( P &sorted_pairs, N &sorted_numbers );
		static void			insertSmallest( P &sorted_pairs, N &sorted_num );
		
	public:
		static N			parseNumbers( int ac, char *av[] );
		static N			FJMIS( N &numbers );
		
};

# include "PmergeMe.tpp"

#endif