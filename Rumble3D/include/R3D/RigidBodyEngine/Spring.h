#pragma once
#include "ForceGenerator.h"

#include "R3D/Common/Precision.h"
#include <glm/glm.hpp>

namespace rum
{
	class RigidBody;

	class Spring : public ForceGenerator
	{
	public:
		Spring(const glm::vec3& localConnectionPoint,
			   RigidBody* other,
			   const glm::vec3& otherConnectionPoint,
			   real springConstant,
			   real restLength);

		virtual void UpdateForce(RigidBody* body, real duration) override;

	protected:
		glm::vec3 m_connectionPoint; // in lokalen Koordinaten des K�rpers
		glm::vec3 m_otherConnectionPoint; // in lokalen Koordinaten des anderen K�rpers
		RigidBody* m_other; // Der k�rper am anderen Ende der Feder.
		real m_springConstant; // Federkonstante
		real m_restLength;
	};
}