#include "Func.h"

void clearInputBuffer()
{
	if (cin.rdbuf()->in_avail() > 0) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
