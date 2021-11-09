#include "MagicSquareWand.h"
#include "PermutationGenerators.h"
#include <fstream>
#include <iostream>

std::vector<std::shared_ptr<NumberSquare>> findMagic(const NumberSquare & sq, const bool all)
{
	class Callback
		: public PermutationCallback
	{
		public:
			Callback(const NumberSquare & sq, const bool all)
				: m_sq(sq)
				, m_all(all)
			{
			}

			void operator()(const std::vector<unsigned> & perm) override
			{
				auto temp = m_sq.Clone();
				for (size_t i=0; i<perm.size(); i++)
				{
					const auto x = perm[i];

					temp->At(i / temp->Size(), i % temp->Size()) =
						m_sq.At(x / m_sq.Size(), x % m_sq.Size());
				}

				if (temp->IsMagic())
				{
					//m_sq.Assign(*temp);
					m_magicOnes.push_back(temp);
				}
			}

			bool ShallContinue() override
			{
				return m_all ? (true) : (m_magicOnes.empty());
			}

			const std::vector<std::shared_ptr<NumberSquare>> & GetMagicOnes() const
			{
				return m_magicOnes;
			}

		private:
			const NumberSquare & m_sq;
			const bool m_all;
			std::vector<std::shared_ptr<NumberSquare>> m_magicOnes;
	};

	Callback cbk(sq, all);
	dummyGeneratePermutations(sq.Size() * sq.Size(), cbk);

	return cbk.GetMagicOnes();
}

