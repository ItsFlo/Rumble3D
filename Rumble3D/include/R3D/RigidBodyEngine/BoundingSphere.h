#pragma once
#include "R3D/Common/Precision.h"

#include <glm/glm.hpp>

namespace rum
{
	class BoundingSphere
	{	
	public:
		BoundingSphere();
		BoundingSphere(const glm::vec3& center, real radius);
		// Erstellt BoundingSphere, die die beiden Kugeln beinhaltet:
		BoundingSphere(const BoundingSphere& one, const BoundingSphere& two);
		~BoundingSphere();

		// Gibt true zur�ck, wenn sich die BoundingSphere mit other �berlappt
		// und sonst false:
		bool Overlaps(const BoundingSphere* other) const;
		real GetSize() const;
		// Gibt einen Wert zur�ck, der das Wachstum einer Kugel durch eine
		// andere Kugel beschreibt, indem N�herungen der Oberfl�chen 
		// berechnet werden.
		real GetGrowth(const BoundingSphere& other) const;
		
	protected:
		glm::vec3 m_center;
		real m_radius;
	};
}

