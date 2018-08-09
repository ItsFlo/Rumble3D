#pragma once
#include "RigidBody.h"

#include <glm/glm.hpp>

namespace rum
{
	class Rigidbody;

	class CollisionPrimitive
	{
	public:
		virtual ~CollisionPrimitive();

		// Berechnet die Transformation:
		void CalculateInternals();
		// R�ckgabe der i-ten Spalte der Transformationsmatrix:
		glm::vec3 GetAxis(unsigned index) const;
		const glm::mat4 & GetTransform() const;
		RigidBody * GetBody() const;

	protected:
		explicit CollisionPrimitive();

		// Festk�rper, der duch das Objekt repr�sentiert wird.
		RigidBody *m_body;
		// Offset gegen�ber dem repr�sentierten Festk�rper.
		glm::mat4 m_offset;
		glm::mat4 m_transform;
	};
}