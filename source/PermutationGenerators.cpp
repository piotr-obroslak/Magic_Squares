#include "PermutationGenerators.h"

void dummyGeneratePermutations_r(
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

		// notify "new" permutation
		cbk(v);

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
	std::vector<unsigned> temp;
	
	auto n = 0U;
	while (n < N)
	{
		temp.push_back(n++);
	}

	return dummyGeneratePermutations_r(temp, 0, cbk);
}

