#ifndef __NUMBER_SQUARE_H__
#define __NUMBER_SQUARE_H__


#include <cstddef>
#include <memory>
#include <vector>

class NumberSquare
{
	public:
		virtual std::shared_ptr<NumberSquare> Clone() const = 0;
		virtual NumberSquare & Assign(const NumberSquare & that) = 0;

		virtual size_t Size() const = 0;

		virtual unsigned & At(const size_t col, const size_t row) = 0; 

		bool IsMagic() const;

		inline const unsigned & At(const size_t col, const size_t row) const
		{
			return const_cast<NumberSquare&>(*this).At(col, row);
		}
};

#endif

