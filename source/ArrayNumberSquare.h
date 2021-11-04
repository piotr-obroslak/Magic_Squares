#ifndef __ARRAY_NUMBER_SQUARE_H__
#define __ARRAY_NUMBER_SQUARE_H__


#include "NumberSquare.h"
#include <memory>

class ArrayBasedNumberSquare
	: public NumberSquare
{
	public:
		ArrayBasedNumberSquare(const size_t N);
		ArrayBasedNumberSquare(const size_t N, const unsigned dfltVal);
		ArrayBasedNumberSquare(const size_t N, std::initializer_list<unsigned> val);

		size_t Size() const override;
		unsigned & At(const size_t col, const size_t row) override;

	protected:
		size_t volume;
		std::unique_ptr<unsigned[]> sq;
};


#endif

