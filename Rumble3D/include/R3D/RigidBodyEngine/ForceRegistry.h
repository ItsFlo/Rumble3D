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
		/** A entry of the ForceRegistry. */
		struct ForceRegistrationEntry
		{
			RigidBody* m_rigidBody;
			ForceGenerator* m_forceGenerator;
		};

		using Registry = std::vector<ForceRegistrationEntry>;

		explicit ForceRegistry();
		~ForceRegistry();

		// Registriert ein Paar aus Teilchen und Kraftgenerator, der
		// auf dem Teilchen wirkt.
		void registerForce(RigidBody* rigidBody, ForceGenerator * fg);
		// L�scht einen Eintrag aus der Registry.
		void unregisterForce(RigidBody* rigidBody, ForceGenerator * fg);
		// L�scht alle Eintr�ge aus der Registry.
		void clear();
		// Ruft alle Kraft-Generatoren auf, so dass diese die Kr�fte
		// der zugeh�renden Teilchen aktualisieren k�nnen.
		void updateForces(real duration);

	protected:	
		Registry m_registrations;
	};
}
