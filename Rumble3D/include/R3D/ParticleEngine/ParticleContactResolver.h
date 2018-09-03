#pragma once
#include "R3D/Common/Common.h"
#include "R3D/Common/Precision.h"

namespace r3
{
	class ParticleContact;

	class R3D_DECLSPEC ParticleContactResolver
	{
	public:
		explicit ParticleContactResolver(unsigned int iterations);
		~ParticleContactResolver();

		/** Set the number of iterations after creation. */
		void setIterations(unsigned int iterations);
	
		/** Resolve collision and penetration. */
		void resolveContacts(ParticleContact* contactArray,
							 unsigned int numberOfContacts,
							 real duration);

	protected:
		unsigned m_iterations;
		unsigned m_iterationsUsed; // Zum Tracking der Performanz;
	};
}