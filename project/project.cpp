#include "stdafx.h"
#include "ResourseManager.h"

int main()
{
	ResourseManager * rm = new ResourseManager();

	rm->getTypeByFilename("dagsdagdasgAG\sadgdsg\dsagbmp");


	rm->getTypeByFilename("dagsdagdasgAG\s.adgdsg\dsagbm.p");

	rm->getTypeByFilename("dagsdagdasgAG\sad.gdsg\dsagbmp");
    return 0;
}

