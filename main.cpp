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

std::ostream & operator<<(std::ostream & o, const NumberSquare & sq)
{
	for (size_t col = 0; col < sq.Size(); col++)
	{
		for (size_t row = 0; row < sq.Size(); row++)
		{
			o << sq.At(row, col) << '\t';
		}
		o << '\n';
	}

	return o << '\n' << std::endl;
}

int main()
{
	auto sq = std::make_shared<ArrayBasedNumberSquare>(
		3, std::initializer_list<unsigned>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
	
	const auto theMagicOnes = findMagic(*sq, false);
	
	if (theMagicOnes.empty())
	{
		std::cout << "no magic square found!";
	}
	else
	{
		for (const auto & x : theMagicOnes)
		{
			std::cout << (*x);
		}
	}

	std::cout << "Thx!" << std::endl;

	return 0;
}

