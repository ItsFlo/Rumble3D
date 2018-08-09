#include "R3D/ParticleEngine/ParticleCable.h"
#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleContact.h"

#include <glm/glm.hpp>

namespace rum
{

	ParticleCable::ParticleCable()
		: m_maxLength{1.0f},
		m_restitution{0.0f}
	{
	}

	ParticleCable::~ParticleCable()
	{
	}

	unsigned int ParticleCable::AddContact(ParticleContact* contact, unsigned int limit) const
	{
		real length = currentLength();
		if (length < m_maxLength) 
		{
			return 0;
		}
		
		contact->m_particles[0] = m_particles[0];
		if (m_particles[1]->HasFiniteMass()) 
		{
			contact->m_particles[1] = m_particles[1];
		}
		else 
		{
			contact->m_particles[1] = 0;
		}
		
		// Negative Kontaktnormale:
		glm::vec3 normal = m_particles[1]->GetPosition() - m_particles[0]->GetPosition();
		normal = glm::normalize(normal);
	
		contact->setContactNormal(normal);
		contact->setPenetration(length - m_maxLength);
		contact->setRestitution(m_restitution);
	
		return 1;
	}
	
	void ParticleCable::SetMaxLength(real maxLength)
	{
		m_maxLength = maxLength;
	}
	
	void ParticleCable::SetRestitution(real restitution)
	{
		m_restitution = restitution;
	}
}