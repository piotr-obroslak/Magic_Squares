#include "source/ArrayNumberSquare.h"
#include "source/MagicSquareWand.h"
#include <iostream>
#include <limits>
#include <memory>

namespace Tests
{
	static const size_t N = 3;

	namespace ArrayNumberSquare
	{

		bool t001()
		{
			auto ptr = std::make_unique<ArrayBasedNumberSquare>(N);
			return (ptr->Size() == N);
		}

		bool t002()
		{
			static const auto dfltVal = 2U;
			auto ptr = std::make_unique<ArrayBasedNumberSquare>(N, dfltVal);

			return [&] {
				for (size_t col = 0; col < N; col++) {
					for (size_t row = 0; row < N; row++) {
						if (ptr->At(col, row) != dfltVal) {
							return false;
						}
					}
				}
				return true;
			}();
		}

		bool t003()
		{
			auto ptr = std::make_unique<ArrayBasedNumberSquare>(N,
				std::initializer_list<unsigned>({2, 7, 6, 9, 5, 1, 4, 3, 8}));

			return
				(ptr->At(0, 2) == 4) &&
				(ptr->At(1, 1) == 5) &&
				(ptr->At(1, 2) == 3);
		}

		bool t010_trivialButMagic()
		{
			static const auto dfltVal = 20;
			auto ptr = std::make_unique<ArrayBasedNumberSquare>(N, dfltVal);

			return ptr->IsMagic();
		}

		bool t011_nonTrivialAndMagic()
		{
			auto ptr = std::make_unique<ArrayBasedNumberSquare>(N,
				std::initializer_list<unsigned>({2, 7, 6, 9, 5, 1, 4, 3, 8}));

			return ptr->IsMagic();
		}

	}


	namespace MagicSquareWand
	{
		bool t001_isMagicable()
		{
			static const auto dfltVal = 20;
			auto ptr = std::make_unique<ArrayBasedNumberSquare>(N, dfltVal);

			return makeMagic(*ptr);
		}

		bool t002_isMagicable()
		{
			auto ptr = std::make_unique<ArrayBasedNumberSquare>(N,
				std::initializer_list<unsigned>({1, 2, 3, 4, 5, 6, 7, 8, 9}));

			return ptr->IsMagic();
		}
	}
}

static void AssertTrue(const bool val)
{
	if (val != true)
	{
		throw std::runtime_error("holly shit!");
	}
}

int main(void)
{
	try
	{
		AssertTrue(Tests::ArrayNumberSquare::t001());
		AssertTrue(Tests::ArrayNumberSquare::t002());
		AssertTrue(Tests::ArrayNumberSquare::t003());
		AssertTrue(Tests::ArrayNumberSquare::t010_trivialButMagic());
		AssertTrue(Tests::ArrayNumberSquare::t011_nonTrivialAndMagic());

		AssertTrue(Tests::MagicSquareWand::t001_isMagicable());
		AssertTrue(Tests::MagicSquareWand::t002_isMagicable());
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}

