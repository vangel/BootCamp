#include "ResourseManager.h"
#include "Audio.h"
#include "Picture.h"
#include "Resourse.h"



int main()
{
	ResourseManager *rm = new ResourseManager();
	int counter = 0;

	// 1 get - 1 release	
	Picture* asteroid = rm->GetResourse<Picture>("smallasteroid");
	counter = asteroid->GetRc();
	rm->ReleaseResourse("smallasteroid");
	counter = asteroid->GetRc();

	// get > release
	counter = asteroid->GetRc();
	asteroid = rm->GetResourse<Picture>("smallasteroid");
	asteroid = rm->GetResourse<Picture>("smallasteroid");
	asteroid = rm->GetResourse<Picture>("smallasteroid");
	asteroid = rm->GetResourse<Picture>("smallasteroid");
	counter = asteroid->GetRc();
	rm->ReleaseResourse("smallasteroid");
	rm->ReleaseResourse("smallasteroid");
	counter = asteroid->GetRc();

	// get < release
	Audio* sound = rm->GetResourse<Audio>("booom");
	sound = rm->GetResourse<Audio>("booom");
	sound = rm->GetResourse<Audio>("booom");
	sound = rm->GetResourse<Audio>("booom");
	counter = sound->GetRc();
	rm->ReleaseResourse("booom");
	rm->ReleaseResourse("booom");
	rm->ReleaseResourse("booom");
	rm->ReleaseResourse("booom");
	counter = sound->GetRc();

	// release
	rm->ReleaseMemory();
	counter = sound->GetRc();
	counter = asteroid->GetRc();

	// release 
	while (asteroid->GetRc() != 0)
	{
		rm->ReleaseResourse("smallasteroid");
	}

	// unvalid resourse key
	asteroid = rm->GetResourse<Picture>("resourse");
	rm->ReleaseResourse("resourse");

    return 0;
}

