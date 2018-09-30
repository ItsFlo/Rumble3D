#pragma once
#include "R3D/Common/Common.h"
#include "R3D/RigidBodyEngine/CollisionDetection/CollisionPrimitiveType.h"

#include <glm/glm.hpp>

namespace r3
{
	class RigidBody;
	class INarrowPhaseFilter;

	class CollisionBox;
	class CollisionSphere;

	class R3D_DECLSPEC CollisionPrimitive
	{
	public:
		virtual ~CollisionPrimitive();	

		// Berechnet die Transformation:
		void calculateInternals();
		// R�ckgabe der i-ten Spalte der Transformationsmatrix:
		glm::vec3 getAxis(unsigned index) const;
		const glm::mat4 & getTransform() const;
		
		RigidBody* getBody() const;

		CollisionPrimitiveType getType() const;

	protected:
		explicit CollisionPrimitive(CollisionPrimitiveType type);

		// Festk�rper, der duch das Objekt repr�sentiert wird.
		RigidBody* m_body{};
		// Offset gegen�ber dem repr�sentierten Festk�rper.
		glm::mat4 m_offset;
		glm::mat4 m_transform;

	private:
		CollisionPrimitiveType m_type;
	};
}