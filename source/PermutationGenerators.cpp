#include "PermutationGenerators.h"
#include <iostream>

static std::vector<unsigned> initializeVectorForPermutation(const unsigned N)
{
	std::vector<unsigned> temp;
	
	auto n = 0U;
	while (n < N)
	{
		temp.push_back(n++);
	}

	return temp;
}

static void dummyGeneratePermutations_r(
	std::vector<unsigned> v,
	const size_t at,
	PermutationCallback & cbk)
{
	if (!cbk.ShallContinue())
	{
		return;
	}

	for (size_t i=at; i<v.size(); i++)
	{
		std::swap(v[at], v[i]);

		if (at == v.size()-1)
		{
			// notify "new" permutation
			cbk(v);

			if (!cbk.ShallContinue())
			{
				break;
			}
		}

		// move on
		dummyGeneratePermutations_r(v, at+1, cbk);

		// "backtrack"
		std::swap(v[at], v[i]);
	}
}

void dummyGeneratePermutations(
	const unsigned N,
	PermutationCallback & cbk)
{
	return dummyGeneratePermutations_r(initializeVectorForPermutation(N), 0, cbk);
}



static void JohnsonTrotterPermutations_aux(
	std::vector<unsigned> v,
	const size_t N,
	PermutationCallback & cbk)
{
	if (!cbk.ShallContinue())
	{
		return;
	}

	std::vector<size_t> C(N+1);
	std::vector<bool> FWD(N+1);

	for (size_t i=1; i<=N; i++)
	{
		C[i] = 1;
		FWD[i] = true;
	}
	C[N] = 0;

	cbk(v);
	if (!cbk.ShallContinue())
	{
		return;
	}

	{
		size_t i=1;
		while (i<N)
		{
			i=1;
			size_t x=0;

			while (C[i] == (N-i+1))
			{
				FWD[i] = !FWD[i];
				C[i] = 1;
				if (FWD[i])
				{
					x = x+1;
				}
				i = i+1;
			}

			if (i<N)
			{
				const auto k = (FWD[i]) ? (C[i]+x) : (N-i+1 - C[i]+x);

				std::swap(v[k-1], v[k]);

				cbk(v);
				if (!cbk.ShallContinue())
				{
					return;
				}

				C[i] = C[i]+1;
			}
		}
	}
}

void JohnsonTrotterPermutations(
	const unsigned N,
	PermutationCallback & cbk)
{
	return JohnsonTrotterPermutations_aux(initializeVectorForPermutation(N), N, cbk);
}

