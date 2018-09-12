#include "R3D/RigidBodyEngine/CollisionDetection/CollisionAlgorithmMatrix.h"
#include "R3D/RigidBodyEngine/CollisionDetection/INarrowPhaseAlgorithm.h"

#include <cassert>

namespace r3
{
	CollisionAlgorithmMatrix::CollisionAlgorithmMatrix()
	= default;

	CollisionAlgorithmMatrix::~CollisionAlgorithmMatrix()
	= default;

	void CollisionAlgorithmMatrix::setAlgorithm(INarrowPhaseAlgorithm* algorithm,
	                                            const CollisionPrimitiveType firstShape,
	                                            const CollisionPrimitiveType secondShape)
	{
		freeMemory(firstShape, secondShape);
		freeMemory(secondShape, firstShape);

		m_algorithms[firstShape][secondShape] = algorithm;
		if(firstShape != secondShape)
		{
			m_algorithms[secondShape][firstShape] = algorithm;
		}
	}

	INarrowPhaseAlgorithm* CollisionAlgorithmMatrix::getAlgorithm(const CollisionPrimitiveType firstShape,
	                                                              const CollisionPrimitiveType secondShape)
	{
		const auto foundAlgorithm = m_algorithms[firstShape][secondShape];
		assert(foundAlgorithm != nullptr);
		return foundAlgorithm;
	}

	void CollisionAlgorithmMatrix::freeMemory(const CollisionPrimitiveType firstShape,
	                                          const CollisionPrimitiveType secondShape)
	{
		INarrowPhaseAlgorithm* algorithm = nullptr;
		std::swap(algorithm, m_algorithms[firstShape][secondShape]);
		delete algorithm;
	}
}
