#pragma once
#include "R3D/Common/Precision.h"

#include <vector>

namespace rum
{
	class RigidBody;
	class ForceGenerator;

	class ForceRegistry
	{
	public:
		// Registriert ein Paar aus Teilchen und Kraftgenerator, der
		// auf dem Teilchen wirkt.
		void Add(RigidBody * rigidBody, ForceGenerator * fg);
		// L�scht einen Eintrag aus der Registry.
		void Remove(RigidBody * rigidBody, ForceGenerator * fg);
		// L�scht alle Eintr�ge aus der Registry.
		void Clear();
		// Ruft alle Kraft-Generatoren auf, so dass diese die Kr�fte
		// der zugeh�renden Teilchen aktualisieren k�nnen.
		void UpdateForces(real duration);

	protected:
		// Ein Eintrag in der Registry:
		struct ForceRegistrationEntry 
		{
			RigidBody * rigidBody;
			ForceGenerator * forceGenerator;
		};

		// Die Registry:
		typedef std::vector<ForceRegistrationEntry> Registry;
		Registry registrations;

	};
}
