#include "source/ArrayNumberSquare.h"
#include <memory>


int main()
{
	auto ptr = std::make_unique<ArrayBasedNumberSquare>(3);

	ptr.get()->IsMagic();


	return 0;
}

