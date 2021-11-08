#include "source/ArrayNumberSquare.h"
#include "source/MagicSquareWand.h"
#include <memory>
#include <iostream>
#include <set>

template<typename Container>
void printCollection(const Container & v, const char pfx, const size_t call_depth)
{
	for (size_t i=0; i<call_depth; i++)
		std::cout << '\t';
	std::cout << pfx << "{ ";
	for (const auto & x : v)
		std::cout << x << " ";
	std::cout << '}' << std::endl;
}

void permutationGenerator_r(
	std::vector<std::vector<unsigned>> & out, std::vector<unsigned> & v, const size_t at, const size_t call_depth)
{
	printCollection(v, '>', call_depth);

	for (size_t i=at; i<v.size(); i++)
	{
		std::swap(v[at], v[i]);
		out.push_back(v);
		printCollection(v, '!', call_depth);

		permutationGenerator_r(out, v, at+1, call_depth+1);

		std::swap(v[at], v[i]);
		printCollection(v, '<', call_depth);
	}
}


std::vector<std::vector<unsigned>> permutationGenerator(
	const size_t N)
{
	std::vector<std::vector<unsigned>> retval;

	std::vector<unsigned> temp(N);
	for (size_t i=0; i<N; i++)
		temp[i] = i;

	//retval.push_back(temp);

	permutationGenerator_r(retval, temp, 0, 1);

	return retval;
}

unsigned factorial(const unsigned N)
{
	if (N == 0)
		return 1;

	return N * factorial(N-1);
}

int main()
{
	auto sq = std::make_shared<ArrayBasedNumberSquare>(
		3, std::initializer_list<unsigned>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
	
	if (makeMagic2(*sq))
	{
		for (auto col = 0; col < 3; col++)
		{
			for (auto row=0; row < 3; row++)
			{
				std::cout << sq->At(row, col) << '\t'; 
			}

			std::cout << '\n';
		}
	}

	std::cout << std::endl;

	return 0;
}

