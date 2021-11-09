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

int main(int argc, const char * argv[])
{
	bool findAll = false;
	int N = 0;

	auto checkArg = [&](const char * arg) {
		try {
			if ((!findAll) && (std::string(arg) == "-all")) {
				findAll = true;
				return true;
			}
			else if ((N = std::stoi(arg)) > 1) {
				return true;
			}
		}
		catch(...) {
		}

		return false;
	};

	if ((argc != 2 && argc != 3) ||
		((argc == 2) && (!checkArg(argv[1]))) ||
		((argc == 3) && ((!checkArg(argv[1])) || (!checkArg(argv[2])))) ||
		(N < 1))
	{
		std::cout << "usage: " << argv[0] << " <N>" << "[-all]" << '\n';
		std::cout << "       N - size of the magic square to be generated (must be a positive number)" << '\n';
		std::cout << "       -all - optional, forces generating all the squares of size N" << '\n';
		std::cout << std::endl;
		return 0;
	}

	auto sq = std::make_shared<ArrayBasedNumberSquare>(N);
	{
		auto i=0;
		for (size_t col = 0; col < sq->Size(); col++)
		{
			for (size_t row = 0; row < sq->Size(); row++)
			{
				sq->At(col, row) = ++i;
			}
		}
	}
	
	const auto theMagicOnes = findMagic(*sq, findAll);
	
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

