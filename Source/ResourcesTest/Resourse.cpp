#include "Resourse.h"


Resourse::Resourse(std::string id, std::string fullName, resourseType type):ID(id), fullName(fullName), type(type), refCounter(0)
{
}

void Resourse::IncRc()
{
	++refCounter;
}

void Resourse::DecRc()
{
	--refCounter;
}

int Resourse::GetRc()
{
	return refCounter;
}

bool Resourse::Load()
{
	return false;
}

bool Resourse::Unload()
{
	return false;
}


Resourse::~Resourse()
{
	Resourse::refCounter = 0;
}
