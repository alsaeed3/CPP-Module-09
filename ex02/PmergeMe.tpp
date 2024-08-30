/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:35:29 by alsaeed           #+#    #+#             */
/*   Updated: 2024/08/31 00:43:12 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename N, typename P>
N			PmergeMe<N, P>::parseNumbers( int ac, char *av[] ) {

	N	numbers;
	int	g_num( -1 );

	for ( int i = 1; i < size; i++ ) {

		std::istringstream	iss( (std::string( av[i] )) );

		iss >> g_num;

		if ( iss.fail() || !iss.eof() || g_num < 0 ) {

			throw std::runtime_error( "Error: Invalid Input." );
		} else {

			numbers.push_back( g_num );
		}
	}

	return numbers;
}

template<typename N, typename P>
N			PmergeMe<N, P>::FJMIS( N &numbers ) {

	straggler_t	straggler = findStraggler( numbers );

	P	pairs( 0 );
	P	sorted_pairs( 0 );
	
	N	sorted_numbers( 0 );

	while ( !numbers.empty() ) {

		int a = numbers.front();
		numbers.pop_front();
		int b = numbers.front();
		numbers.pop_front();

		if ( a > b ) {

			std::swap(a, b);
		}

		pairs.push_back( std::make_pair(a, b) );
	}

	if ( !pairs.empty() ) {

		sorted_pairs = mergeSortSeconds( pairs );
		sorted_numbers = extractLargest( sorted_pairs );
		insertSmallest( sorted_pairs, sorted_numbers );
	}

	if( straggler.second ) {
		
		typename N::iterator insertPos = std::lower_bound( sorted_numbers.begin(), sorted_numbers.end(), straggler.first );
		sorted_numbers.insert( insertPos, straggler.first );
	}

	return sorted_numbers;
}

template<typename N, typename P>
straggler_t	PmergeMe<N, P>::findStraggler( N &numbers ) {

	straggler_t	straggler = std::make_pair( 0, false );

	if ( IS_ODD( numbers ) ) {

		straggler.first = numbers.back();
		straggler.second = true;
		numbers.pop_back();
	}

	return straggler;
}

bool	compSec( std::pair<int, int> const &l, std::pair<int, int> const &r ) {

	return l.second < r.second;
}

template<typename N, typename P>
P			PmergeMe<N, P>::mergeSortSeconds( P &pairs ) {

	P	sorted_pairs( 0 );

	if ( pairs.size() == 1 ) {

		return pairs;
	}

	typename	P::iterator mid_it = pairs.begin();
	size_t	mid = pairs.size() / 2;
	std::advance( mid_it, mid );

	P	left( pairs.begin(), mid_it );
	P	right( mid_it, pairs.end() );

	std::merge( left.begin(), left.end(), right.begin(), righ.end(),
				std::back_inserter( sorted_pairs ), compSec );

	return;
}

template<typename N, typename P>
void			PmergeMe<N, P>::extractLargest( P &sorted_pairs, N &sorted_numbers ) {


	for ( typename P::iterator it = sorted_pairs.begin(); it < sorted_pairs.end(); it++ ) {
		
		sorted_numbers.push_back( it.second );
	}

	return;
}

template<typename N, typename P>
void		PmergeMe<N, P>::insertSmallest( P &sorted_pairs, N &sorted_numbers ) {

	for ( typename P::iterator it = sorted_pairs.begin(); it < sorted_pairs.end(); it++ ) {

		typename	N::iterator insertPos = std::lower_bound( sorted_numbers.begin(), sorted_numbers.end(), it.first );
		sorted_numbers.insert( insertPos, it.first );
	}

	return;
}
