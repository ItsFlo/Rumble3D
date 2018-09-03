#pragma once
#include "R3D/Common/Common.h"
#include "R3D/Common/Precision.h"

#include <glm/glm.hpp>

namespace r3
{
	class R3D_DECLSPEC BoundingBox
	{
	public:
		BoundingBox();
		BoundingBox(const glm::vec3& center, const glm::vec3& bounds);
		// Erstellt BoundingSphere, die die beiden Kugeln beinhaltet
		BoundingBox(const BoundingBox& one, const BoundingBox& two);
		~BoundingBox();

		// Gibt true zur�ck, wenn sich die BoundingSphere mit other �berlappt
		// und sonst false
		bool overlaps(const BoundingBox* other) const;
		/** Get the volume of this bounding box. */
		real getVolume() const;
		// Gibt einen Wert zur�ck, der das Wachstum einer Kugel durch eine
		// andere Kugel beschreibt, indem N�herungen der Oberfl�chen 
		// berechnet werden.
		real getGrowth(const BoundingBox& other) const;

	protected:
		glm::vec3 m_center;
		glm::vec3 m_bounds;
	};
}

