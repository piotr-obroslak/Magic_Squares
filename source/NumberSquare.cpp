#include "NumberSquare.h"

bool NumberSquare::IsMagic() const
{
	if (Size() == 0 || Size() == 0)
	{
		return true;
	}

	const auto columnsSums = [&]() {
		std::vector<unsigned> retval;

		for (auto col = decltype(Size())(0); col < Size(); col++)
		{
			retval.push_back(0U);
			auto & colSum = retval.back();

			for (auto row = decltype(Size())(0); row < Size(); row++)
			{
				colSum += At(col, row);
			}
		}

		return retval;
	}();

	const auto rowsSums = [&]() {
		std::vector<unsigned> retval;

		for (auto row = decltype(Size())(0); row < Size(); row++)
		{
			retval.push_back(0U);
			auto & rowSum = retval.back();

			for (auto col = decltype(Size())(0); col < Size(); col++)
			{
				rowSum += At(col, row);
			}
		}

		return retval;
	}();

	
	const auto diagonalSums = [&]() {
		auto retval = std::vector<unsigned>(2, 0U);

		for (auto colrow = decltype(Size())(0); colrow < Size(); colrow++)
		{
			retval[0] += At(colrow, colrow);
			retval[1] += At(colrow, Size() - colrow - 1);
		}

		return retval;
	}();

	auto TestSums = [](const std::vector<unsigned> & sums, const unsigned expected) {

		for (const auto & sum : sums)
		{
			if (sum != expected)
			{
				return false;
			}
		}

		return true;
	};

	const auto expectedSum = columnsSums.front();

	return TestSums(columnsSums, expectedSum) &&
		TestSums(rowsSums, expectedSum) &&
		TestSums(diagonalSums, expectedSum);
}

