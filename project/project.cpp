#include "stdafx.h"
#include "ResourseManager.h"

int main()
{
	ResourseManager *rm = new ResourseManager();
	int counter = 0;

	Resourse* asteroid = rm->getResourse("smallasteroid");
	counter = asteroid->getRc();
	rm->releaseResourse("smallasteroid");
	counter = asteroid->getRc();

	counter = 0;
	asteroid = rm->getResourse("smallasteroid");
	asteroid = rm->getResourse("smallasteroid");
	asteroid = rm->getResourse("smallasteroid");
	counter = asteroid->getRc();
	rm->releaseResourse("smallasteroid");
	rm->releaseResourse("smallasteroid");
	rm->releaseResourse("smallasteroid");
	rm->releaseResourse("smallasteroid");
	counter = asteroid->getRc();

    return 0;
}

