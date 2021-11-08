#ifndef __PERMUTATION_GENERATORS_H__
#define __PERMUTATION_GENERATORS_H__

#include <vector>

class PermutationCallback
{
	public:
		enum class Stop { Yes, No};
		virtual Stop operator()(const std::vector<unsigned> & perm) = 0;
};

void dummyGeneratePermutations(
	const unsigned N,
	PermutationCallback & cbk);

#endif

