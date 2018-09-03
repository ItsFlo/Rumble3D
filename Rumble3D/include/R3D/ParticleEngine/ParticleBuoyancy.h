#pragma once
#include "R3D/Common/Common.h"
#include "R3D/ParticleEngine/ParticleForceGenerator.h"
#include "R3D/Common/Precision.h"

namespace r3
{
	class Particle;

	class R3D_DECLSPEC ParticleBuoyancy : public ParticleForceGenerator
	{
	public:
		explicit ParticleBuoyancy(real maxDepth, real volume, real liquidHeight, real liquidDensity = real(1000.0f));
		~ParticleBuoyancy();

		void updateForce(Particle* particle, real duration) override;

	protected:
		real m_maxDepth;
		real m_volume;
		real m_liquidHeight;
		real m_liquidDensity;

	};
}