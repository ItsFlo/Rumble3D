#include "R3D/RigidBodyEngine/CollisionDetection/Algorithm/SphereSphereNarrowAlgorithm.h"
#include "R3D/RigidBodyEngine/CollisionSphere.h"

#include <glm/glm.hpp>

namespace r3
{
	SphereSphereNarrowAlgorithm::SphereSphereNarrowAlgorithm()
	= default;

	SphereSphereNarrowAlgorithm::~SphereSphereNarrowAlgorithm()
	= default;

	bool SphereSphereNarrowAlgorithm::generateContactDataImpl(RigidBody* rbSphere1, CollisionSphere* sphere1,
															  RigidBody* rbSphere2, CollisionSphere* sphere2,
															  CollisionData& collisionData)
	{
		// Wenn Kontakt-Array voll ist, nichts mehr zu tun:
		if(collisionData.getContactsLeft() <= 0)
		{
			return false;
		}

		// Positionen der Kugeln:
		const auto positionOne = rbSphere1->getTransform().getPosition();
		const auto positionTwo = rbSphere2->getTransform().getPosition();


		//const auto positionOne = sphere1->getAxis(3);
		//const auto positionTwo = sphere2->getAxis(3);

		// Vector zwischen den Kugeln und seine L�nge:
		const auto midline = positionOne - positionTwo;
		const auto size = glm::length(midline);

		// Keine Kollision:
		if(size <= 0.0f || size >= sphere1->getRadius() + sphere2->getRadius())
		{
			return false;
		}

		// Erstellung der Kontaktnormalen und der Kontaktdaten:
		const auto normal = midline * (real(1) / size);
		auto* contact = collisionData.getAvailableContact();
		
		contact->setContactNormal(normal);
		contact->setContactPoint(positionOne + midline * real(0.5));
		contact->setPenetration((sphere1->getRadius() + sphere2->getRadius() - size));
		contact->setBodyData(rbSphere1, rbSphere2);
		return true;
	}
}
