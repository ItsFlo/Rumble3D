#pragma once
#include "R3D/Common/Common.h"
#include "R3D/RigidBodyEngine/CollisionDetection/CollisionData.h"
#include "R3D/RigidBodyEngine/CollisionDetection/CollisionPair.h"
#include "R3D/Utility/FixedSizeContainer.h"

namespace r3
{
	class CollisionPair;

	class CollisionBox;
	class CollisionSphere;

	class R3D_DECLSPEC INarrowPhaseFilter
	{
	public:
		virtual ~INarrowPhaseFilter();

		virtual void generateCollisionData(const FixedSizeContainer<CollisionPair>& broadPhaseData,
										   CollisionData& collisions) = 0;

	protected:
		explicit INarrowPhaseFilter();
	};
}
