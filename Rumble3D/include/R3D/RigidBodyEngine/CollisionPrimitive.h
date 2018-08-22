#pragma once
#include "RigidBody.h"

#include <glm/glm.hpp>

namespace rum
{
	class RigidBody;

	class CollisionPrimitive
	{
	public:
		virtual ~CollisionPrimitive();

		// Berechnet die Transformation:
		void calculateInternals();
		// R�ckgabe der i-ten Spalte der Transformationsmatrix:
		glm::vec3 getAxis(unsigned index) const;
		const glm::mat4 & getTransform() const;
		RigidBody* getBody() const;

	protected:
		explicit CollisionPrimitive();

		// Festk�rper, der duch das Objekt repr�sentiert wird.
		RigidBody* m_body{};
		// Offset gegen�ber dem repr�sentierten Festk�rper.
		glm::mat4 m_offset;
		glm::mat4 m_transform;
	};
}