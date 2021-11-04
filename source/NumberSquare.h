#include <cstddef>
#include <vector>

class NumberSquare
{
	public:
		virtual size_t Size() const = 0;

		virtual unsigned & At(const size_t col, const size_t row) = 0; 

		bool IsMagic() const;

		inline const unsigned & At(const size_t col, const size_t row) const
		{
			return const_cast<NumberSquare&>(*this).At(col, row);
		}
};


class MagicSquare
	: public NumberSquare
{
	public:
		//size_t Columns() const override { return 0; }
		//size_t Rows() const override { return 0; }
};

