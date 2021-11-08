#include "MagicSquareWand.h"
#include "PermutationGenerators.h"
#include <fstream>
#include <iostream>

std::ofstream of;
static void printSquare(const NumberSquare & sq)
{
	for (size_t r = 0; r<sq.Size(); r++)
	{
		for (size_t c = 0; c<sq.Size(); c++)
		{
			of << sq.At(c, r) /*<< '\t'*/;
		}

		//of << '\n';
	}
	of << "------------------\n";
	//std::cout << std::endl;
}

static unsigned call_count = 0U;

static bool makeMagic_r(NumberSquare & sq,
	const size_t c1, const size_t r1,
	const size_t c2, const size_t r2)
{
	++call_count;
	if (c1 < sq.Size() &&
		r1 < sq.Size() &&
		c2 < sq.Size() &&
		r2 < sq.Size())
	{
		/*
		of << "c1=" << c1 << " r1=" << r1 <<
			" c2=" << c2 << " r2=" << r2 << '\n';
*/
		printSquare(sq);

		if (sq.IsMagic())
		{
			of << "magic!\n";

			if ((sq.At(0, 0)) == 2 &&
					(sq.At(1, 0) == 2) &&
					(sq.At(2, 0) == 6) &&
					(sq.At(0, 1) == 9) &&
					(sq.At(1, 1) == 5) &&
					(sq.At(2, 1) == 1) &&
					(sq.At(0, 2) == 4) &&
					(sq.At(1, 2) == 3) &&
					(sq.At(2, 2) == 9))
			{
				printSquare(sq);
			}

			return true;
		}
		else
		{
			if ((c1 != c2) || (r1 != r2))
				std::swap(sq.At(c1, r1), sq.At(c2, r2));

			if (makeMagic_r(sq, c1+1, r1, c2, r2))
			{
				return true;
			}

			if (makeMagic_r(sq, c1, r1+1, c2, r2))
			{
				return true;
			}

			if (makeMagic_r(sq, c1, r1, c2+1, r2))
			{
				return true;
			}

			if (makeMagic_r(sq, c1, r1, c2, r2+1))
			{
				return true;
			}
			/* "backtrack" */
			//std::swap(sq.At(c1, r1), sq.At(c2, r2));
			//of << "backtracked: \n"; 
			//printSquare(sq);
		}
	}

	return false;
}


bool makeMagic(NumberSquare & sq)
{
	of.open("dump.txt");
	const auto retval = makeMagic_r(sq, 0, 0, 0, 0);
	std::cout << call_count << std::endl;
	of.close();

	return retval;
}


bool makeMagic2(NumberSquare & sq)
{
	class Callback
		: public PermutationCallback
	{
		public:
			Callback(NumberSquare & sq)
				: m_sq(sq)
			{
			}

			Stop operator()(const std::vector<unsigned> & perm) override
			{
				auto temp = m_sq.Clone();
				for (size_t i=0; i<perm.size(); i++)
				{
					const auto x = perm[i];

					temp->At(i / temp->Size(), i % temp->Size()) =
						m_sq.At(x / m_sq.Size(), x % m_sq.Size());
				}

				//printSquare(*temp);

				if (temp->IsMagic())
				{
					m_sq.Assign(*temp);
					printSquare(m_sq);
					return Stop::Yes;
				}

				return Stop::No;
			}

		private:
			NumberSquare & m_sq;
	};

	of.open("makeMagic2.txt");

	Callback cbk(sq);

	dummyGeneratePermutations(sq.Size() * sq.Size(), cbk);

	of.close();

	return sq.IsMagic();
}

