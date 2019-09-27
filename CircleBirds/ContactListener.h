#pragma once
#include "Player.h"
#include "Pig.h"

class ContactListener : public b2ContactListener
{
	void BeginContact(b2Contact* contact)
	{
		void* objectA = contact->GetFixtureA()->GetBody()->GetUserData();
		void* objectB = contact->GetFixtureB()->GetBody()->GetUserData();

		if (objectA == static_cast<Player*>(objectA) && objectB == static_cast<Pig*>(objectA)) {
			//Kill Pig
		}

	}
};
