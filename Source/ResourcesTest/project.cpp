#include "ResourceManager.h"

int main()
{
	ResourceManager *rm = new ResourceManager();
	int counter = 0;

	// get and release	
	PictureResource* asteroid = rm->GetResource<PictureResource>("smallasteroid");
	counter = asteroid->GetRefCounter();
	rm->ReleaseResource("smallasteroid");
	counter = asteroid->GetRefCounter();

	

	// release resouce with counter != 0
	counter = asteroid->GetRefCounter();
	asteroid = rm->GetResource<PictureResource>("smallasteroid");
	asteroid = rm->GetResource<PictureResource>("smallasteroid");
	asteroid = rm->GetResource<PictureResource>("smallasteroid");
	asteroid = rm->GetResource<PictureResource>("smallasteroid");
	counter = asteroid->GetRefCounter();
	rm->ReleaseResource("smallasteroid");
	rm->ReleaseResource("smallasteroid");
	counter = asteroid->GetRefCounter();	
	//rm->ReleaseAllResources();         // uncomment for showing assert

	// loading file not exist
	//AudioResource* sound = rm->GetResource<AudioResource>("booom");    // uncomment for showing assert

	// invalid resource key
	//AudioResource* sound = rm->GetResource<AudioResource>("booo");	 // uncomment for showing assert

	// release not loaded resource
	//rm->ReleaseResource("asteroid");            // uncomment for showing assert

	// release resource with invalid key
	//rm->ReleaseResource("aster");              // uncomment for showing assert

	// release 
	counter = asteroid->GetRefCounter();
	while (asteroid->GetRefCounter() != 0)
	{
		rm->ReleaseResource("smallasteroid");
	}
	counter = asteroid->GetRefCounter();

	// release resource with counter == 0
	counter = asteroid->GetRefCounter();
	asteroid = rm->GetResource<PictureResource>("smallasteroid");
	asteroid = rm->GetResource<PictureResource>("smallasteroid");
	counter = asteroid->GetRefCounter();
	rm->ReleaseResource("smallasteroid");
	rm->ReleaseResource("smallasteroid");
	//rm->ReleaseResource("smallasteroid");         // uncomment for showing assert
	//rm->ReleaseResource("smallasteroid");         // uncomment for showing assert
	counter = asteroid->GetRefCounter();

	// uncorrect resource type
	//AudioResource* sound = rm->GetResource<AudioResource>("smallasteroid");         // uncomment for showing assert

    return 0;
}

