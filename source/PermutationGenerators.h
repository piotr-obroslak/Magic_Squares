#ifndef __PERMUTATION_GENERATORS_H__
#define __PERMUTATION_GENERATORS_H__

#include <vector>

class PermutationCallback
{
	public:
		virtual void operator()(const std::vector<unsigned> & perm) = 0;
		virtual bool ShallContinue() { return true; }
};

void dummyGeneratePermutations(
	const unsigned N,
	PermutationCallback & cbk);

#endif

