#pragma once
#include "Player.h"
#include "DestructibleEntity.h"
#include "Entity.h"
#include "GameManager.h"
#include "Scene.h"

class ContactListener : public b2ContactListener
{
	void BeginContact(b2Contact* contact)
	{
		void* objectA = contact->GetFixtureA()->GetBody()->GetUserData();
		void* objectB = contact->GetFixtureB()->GetBody()->GetUserData();

		if (objectA == static_cast<Player*>(objectA) && objectB == static_cast<DestructibleEntity*>(objectB)) {
			if (static_cast<DestructibleEntity*>(objectB)->dealDamage(contact->GetTangentSpeed())) {
				GameManager::GetInstance()->GetScene()->GetWorld()->DestroyBody(contact->GetFixtureB()->GetBody());
			}
		}
		if (objectB == static_cast<Player*>(objectB) && objectA == static_cast<DestructibleEntity*>(objectA)) {
			if (static_cast<DestructibleEntity*>(objectA)->dealDamage(contact->GetTangentSpeed())) {
				GameManager::GetInstance()->GetScene()->GetWorld()->DestroyBody(contact->GetFixtureA()->GetBody());
			}
		}
	}
};
