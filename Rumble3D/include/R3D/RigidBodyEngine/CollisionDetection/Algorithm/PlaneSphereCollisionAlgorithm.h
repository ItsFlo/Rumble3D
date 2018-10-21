#pragma once
#include "IPlaneSphereCollisionAlgorithm.h"

#include "R3D/Common/Common.h"

namespace r3
{
	class R3D_DECLSPEC PlaneSphereCollisionAlgorithm : public IPlaneSphereCollisionAlgorithm
	{
	public:
		explicit PlaneSphereCollisionAlgorithm();
		~PlaneSphereCollisionAlgorithm();

	protected:
		bool generateContactDataImpl(RigidBody* rbPlane, 
									 CollisionPlane* plane,
									 RigidBody* rbSphere,
									 CollisionSphere* sphere, 
									 CollisionData& collisionData) override;
	};
}
