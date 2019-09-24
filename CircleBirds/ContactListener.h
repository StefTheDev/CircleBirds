#pragma once
#include "Player.h"

class ContactListener : public b2ContactListener
{
	void BeginContact(b2Contact* contact)
	{
		void* objectA = contact->GetFixtureA()->GetBody()->GetUserData();
		void* objectB = contact->GetFixtureB()->GetBody()->GetUserData();


	}
};
