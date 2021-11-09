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

bool makeMagic(NumberSquare & sq)
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

	of.open("makeMagic.txt");

	Callback cbk(sq);

	dummyGeneratePermutations(sq.Size() * sq.Size(), cbk);

	of.close();

	return sq.IsMagic();
}

