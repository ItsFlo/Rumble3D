#pragma once
#include "R3D/Common/Precision.h"

//Schnittstellen-Klasse f�r Kraft-Generatoren
namespace rum
{
	class Particle;

	class ParticleForceGenerator
	{
	public:
		virtual ~ParticleForceGenerator();

		// Schnittstellen-Methode, die im speziellen Kraft-Generator 
		// �berladen werden muss. Die Methode berechnet und aktualisiert
		// die Kraft, die auf das Teilchen particle in der Zeitscheibe 
		// duration wirkt.
		virtual void updateForce(Particle* particle, real duration) = 0;

	protected:
		explicit ParticleForceGenerator();
	};
}