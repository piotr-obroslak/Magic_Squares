#ifndef __PERMUTATION_GENERATORS_H__
#define __PERMUTATION_GENERATORS_H__

#include <vector>

class PermutationCallback
{
	public:
		virtual void operator()(const std::vector<unsigned> & perm) = 0;
		virtual bool ShallContinue() { return true; }
};

/* A permutation generation algorithm that I was able to come up with
 * myself after some trail and error.
 * It generates all the permutations with no repeats so I consider it working.
 * */
void dummyGeneratePermutations(
	const unsigned N,
	PermutationCallback & cbk);

/* A clever permutation generation algorithm that swaps only a single pair
 * ov neighbor elements of the vector to generate next sequence.
 * Described in W. Lipski "Kombinatoryka dla programistów"
 * (unfortunately this book might not have been translated to English).
 * */
void JohnsonTrotterPermutations(
	const unsigned N,
	PermutationCallback & cbk);

#endif

