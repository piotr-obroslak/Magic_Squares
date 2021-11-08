#include "ArrayNumberSquare.h"

ArrayBasedNumberSquare::ArrayBasedNumberSquare(const size_t N)
	: ArrayBasedNumberSquare(N, 0)
{
}

ArrayBasedNumberSquare::ArrayBasedNumberSquare(const size_t N, const unsigned dfltVal)
	: volume(N)
	, sq(new unsigned[volume*volume])
{
	std::fill(sq.get(), sq.get() + volume*volume, dfltVal);
}

ArrayBasedNumberSquare::ArrayBasedNumberSquare(const size_t N, std::initializer_list<unsigned> val)
	: ArrayBasedNumberSquare(N)
{
	auto in = val.begin();
	auto out = sq.get();

	for ( ; in!=val.end() && out<sq.get()+volume*volume; in++, out++)
	{
		*out = *in;
	}
}

std::shared_ptr<NumberSquare> ArrayBasedNumberSquare::Clone() const /*override*/
{
	auto retval = std::make_shared<ArrayBasedNumberSquare>(this->volume);
	retval->Assign(*this);

	return retval;
}

NumberSquare & ArrayBasedNumberSquare::Assign(const NumberSquare & that) /*override*/
{
	//NOTE: I assume the sizes of the squares do match
	for (size_t col=0; col<this->volume; col++)
	{
		for (size_t row=0; row<this->volume; row++)
		{
			this->At(col, row) = that.At(col, row);
		}
	}

	return *this;
}

size_t ArrayBasedNumberSquare::Size() const /*override*/
{
	return volume;
}

unsigned & ArrayBasedNumberSquare::At(const size_t col, const size_t row) /*override*/
{
	return sq[volume*row + col];
}

